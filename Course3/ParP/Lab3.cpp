#include <clocale>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <type_traits>
#include <utility>
#include <immintrin.h>
#include <omp.h>
#include "bench.h"

enum vector_support_e
{
	VECTOR_NONE,
	VECTOR_SSE,
	VECTOR_AVX,
	VECTOR_AVX2,
	VECTOR_AVX512
};

inline unsigned get_max_func()
{
	unsigned regs[4] = { 0, 0, 0, 0 };
	__cpuid(regs, 0);
	return regs[0];
}

inline unsigned get_max_func_ex()
{
	unsigned regs[4] = { 0, 0, 0, 0 };
	__cpuid(regs, 0x80000000);
	return regs[0];
}

inline vector_support_e get_max_vector_support()
{
	enum vector_bits_e
	{
		SUPPORT_BIT_SSE = 1 << 25,
		SUPPORT_BIT_AVX = 1 << 28,
		SUPPORT_BIT_AVX2 = 1 << 5,
		SUPPORT_BIT_AVX512 = 1 << 16
	};

	unsigned args[4];
	__cpuid_ex(args, 7, 0);
	if (args[2] & SUPPORT_BIT_AVX512)
		return VECTOR_AVX512;
	if (args[2] & SUPPORT_BIT_AVX2)
		return VECTOR_AVX2;
	__cpuid_ex(args, 1, 0);
	if (args[2] & SUPPORT_BIT_AVX)
		return VECTOR_AVX;
	if (args[3] & SUPPORT_BIT_SSE)
		return VECTOR_SSE;
	return VECTOR_NONE;
}

template<typename T>
struct xmm
{
	typedef T type __attribute__((vector_size(16)));
	type data;
	using array = std::vector<xmm<T>>;
	static constexpr size_t vector_size = 16 / sizeof(float);
};

template<typename T>
void mod_sum(T* x, const T* y, const T* z, unsigned size)
{
	for (unsigned i = 0; i < size; ++i)
		x[i] = (y[i] > 0 ? y[i] : -y[i]) + (z[i] > 0 ? z[i] : -z[i]);
}

template<typename T>
auto task_1(unsigned bench_count, unsigned array_size)
{
	T* x = new T[array_size];
	T* y = new T[array_size];
	T* z = new T[array_size];

	for (unsigned i = 0; i < array_size; ++i)
	{
		y[i] = static_cast<T>(rand() % 101 - 50);
		z[i] = static_cast<T>(rand() % 101 - 50);
	}

	auto bench = benchmark(bench_count, [&x, &y, &z, array_size]() { mod_sum(x, y, z, array_size); }, clock);

	delete[] x;
	delete[] y;
	delete[] z;

	return bench;
}

template<typename T>
T sqrt_seq(const T &src)
{
	return sqrt(src);
}

template<typename T>
auto task_2_seq(unsigned bench_count, unsigned array_size)
{
	std::vector<T> src(array_size);
	std::vector<T> res(array_size);
	std::generate(src.begin(), src.end(), []() -> float { return static_cast<float>(rand() % 101 - 1); });

	return benchmark(bench_count, [&src, &res, array_size]()
	{
		std::transform(src.begin(), src.end(), res.begin(), sqrt_seq<T>);
	},
	clock);
}

template<typename T>
auto task_2_par(unsigned bench_count, unsigned array_size)
{
	using mm = xmm<T>;
	array_size /= mm::vector_size;

	auto pred_generator = [](mm &elem)
	{
        for (size_t i = 0; i < mm::vector_size; ++i)
			elem.data[i] = static_cast<T>(rand() % 100 + 1);
	};

	auto pred_calculator = [](const mm &src) -> mm
	{
        if constexpr (std::is_same<T, float>::value)
			return { _mm_sqrt_ps(src.data) };
        else if constexpr (std::is_same<T, double>::value)
			return { _mm_sqrt_pd(src.data) };
	};

	typename mm::array src(array_size);
	typename mm::array res(array_size);
	std::for_each(src.begin(), src.end(), pred_generator);

	return benchmark(bench_count, [&src, &res, &pred_calculator]()
	{
		std::transform(src.begin(), src.end(), res.begin(), pred_calculator);;
	}, clock);
}

template<typename TFNPred>
auto task_3_seq(unsigned bench_count, unsigned array_size, TFNPred pred)
{
	auto pred_generator = []() -> std::pair<float, float>
	{
		return { static_cast<float>(rand() % 101 - 1), static_cast<float>(rand() % 101 - 1) };
	};
	auto pred_calculator = [&pred](const std::pair<float, float> &lhs, const std::pair<float, float> &rhs) -> const std::pair<float, float>
	{
		return { pred(lhs.first, rhs.first), pred(lhs.second, rhs.second) };
	};

	std::vector<std::pair<float, float>> x(array_size);
	std::vector<std::pair<float, float>> y(array_size);
	std::vector<std::pair<float, float>> z(array_size);
	std::generate(y.begin(), y.end(), pred_generator);
	std::generate(z.begin(), z.end(), pred_generator);
	return benchmark(bench_count, [&x, &y, &z, &pred_calculator]()
	{
		std::transform(y.begin(), y.end(), z.begin(), x.begin(), pred_calculator);
	}, clock);
}

template<typename TFNPred>
auto task_3_par(unsigned bench_count, unsigned array_size, TFNPred pred)
{
	using mm = xmm<float>;
	array_size /= mm::vector_size * 2;

	auto pred_generator = []() -> mm
	{
		return { mm::type
		{
			static_cast<float>(rand() % 101 - 1),
			static_cast<float>(rand() % 101 - 1),
			static_cast<float>(rand() % 101 - 1),
			static_cast<float>(rand() % 101 - 1)
		} };
	};
	auto pred_calculator = [&pred](const mm &lhs, const mm &rhs) -> const mm
	{
		return { pred(lhs.data, rhs.data) };
	};

	mm::array x(array_size);
	mm::array y(array_size);
	mm::array z(array_size);
	std::generate(y.begin(), y.end(), pred_generator);
	std::generate(z.begin(), z.end(), pred_generator);
	return benchmark(bench_count, [&x, &y, &z, &pred_calculator]()
	{
		std::transform(y.begin(), y.end(), z.begin(), x.begin(), pred_calculator);
	}, clock);
}

int main()
{
	setlocale(LC_ALL, "");
	srand(time(nullptr));

	unsigned max_func = get_max_func();
	unsigned max_func_ex = get_max_func_ex();
	vector_support_e max_vector_support = get_max_vector_support();

	constexpr unsigned BENCH_COUNT = 10;
	constexpr unsigned ARRAY_SIZE = 4096 * 4096;

	std::wcout << L"Макс. номер обычной функции:\t\t" << max_func << std::endl;
	std::wcout << L"Макс. номер расширенной функции:\t" << std::hex << max_func_ex << std::endl;
	std::wcout << std::dec << std::endl;

	std::wcout << L"Поддержка:"	<< std::endl;
	std::wcout << L"AVX512:\t"	<< ((max_vector_support >= VECTOR_AVX512) ? L"Да" : L"Нет") << std::endl;
	std::wcout << L"AVX2:\t"	<< ((max_vector_support >= VECTOR_AVX2) ? L"Да" : L"Нет") << std::endl;
	std::wcout << L"AVX:\t"		<< ((max_vector_support >= VECTOR_AVX) ? L"Да" : L"Нет") << std::endl;
	std::wcout << L"SSE:\t"		<< ((max_vector_support >= VECTOR_SSE) ? L"Да" : L"Нет") << std::endl;
	std::wcout << std::endl;

	std::wcout << L"Задание 1"	<< std::endl;
	std::wcout << L"8 бит:\t"	<< task_1<int8_t>(BENCH_COUNT, ARRAY_SIZE) << std::endl;
	std::wcout << L"16 бит:\t"	<< task_1<int16_t>(BENCH_COUNT, ARRAY_SIZE) << std::endl;
	std::wcout << L"32 бит:\t"	<< task_1<int32_t>(BENCH_COUNT, ARRAY_SIZE) << std::endl;
	std::wcout << L"64 бит:\t"	<< task_1<int64_t>(BENCH_COUNT, ARRAY_SIZE) << std::endl;
	std::wcout << L"Float:\t"	<< task_1<float>(BENCH_COUNT, ARRAY_SIZE) << std::endl;
	std::wcout << L"Double:\t"	<< task_1<double>(BENCH_COUNT, ARRAY_SIZE) << std::endl;
	std::wcout << std::endl;

	std::wcout << L"Задание 2"	<< std::endl;
	std::wcout << L"Без векторизации" << std::endl;
	std::wcout << L"Float:\t"	<< task_2_seq<float>(BENCH_COUNT, ARRAY_SIZE) << std::endl;
	std::wcout << L"Double:\t"	<< task_2_seq<double>(BENCH_COUNT, ARRAY_SIZE) << std::endl;
	std::wcout << L"С векторизацией" << std::endl;
	std::wcout << L"Float:\t"	<< task_2_par<float>(BENCH_COUNT, ARRAY_SIZE) << std::endl;
	std::wcout << L"Double:\t"	<< task_2_par<double>(BENCH_COUNT, ARRAY_SIZE) << std::endl;
	std::wcout << std::endl;

	std::wcout << L"Задание 3"	<< std::endl;
	std::wcout << L"Без векторизации" << std::endl;
	std::wcout << L"Умножение:\t" << task_3_seq(BENCH_COUNT, ARRAY_SIZE, std::multiplies()) << std::endl;
	std::wcout << L"Деление:\t" << task_3_seq(BENCH_COUNT, ARRAY_SIZE, std::divides()) << std::endl;
	std::wcout << L"С векторизацией" << std::endl;
	std::wcout << L"Умножение:\t" << task_3_par(BENCH_COUNT, ARRAY_SIZE, std::multiplies()) << std::endl;
	std::wcout << L"Деление:\t" << task_3_par(BENCH_COUNT, ARRAY_SIZE, std::divides()) << std::endl;
	std::wcout << std::endl;

	return 0;
}
