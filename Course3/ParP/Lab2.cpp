#include <clocale>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

inline void __cpuid(unsigned* regs, unsigned func_id)
{
	asm volatile ("cpuid" : "=a"(regs[0]), "=b"(regs[1]), "=c"(regs[2]), "=d"(regs[3]) : "a"(func_id), "c"(0));
}

template<typename TFN>
std::pair<double, clock_t> benchmark(TFN function)
{
	std::chrono::system_clock::time_point time_start;
	std::chrono::system_clock::time_point time_end;
	clock_t stops_start;
	clock_t stops_end;

	unsigned regs[4] = {0};
	__cpuid(regs, 0);

	stops_start = clock();
	time_start = std::chrono::system_clock::now();
	function();
	stops_end = clock();
	time_end = std::chrono::system_clock::now();

	return { std::chrono::duration<double, std::micro>(time_end - time_start).count(), stops_end - stops_start };
}

template<typename T>
size_t positive_count(const std::vector<T> &data)
{
	size_t result = 0;
	for (size_t i = 0; i < data.size(); ++i)
		if (data[i] > 0)
			++result;
	return result;
}

template<typename T>
size_t positive_count_opt(const std::vector<T> &data)
{
	size_t result = 0;
	for (size_t i = 0; i < data.size(); ++i)
		result += static_cast<size_t>(data[i] > 0);
	return result;
}

template<typename T>
void bubble_sort(std::vector<T> &data)
{
	for (int i = 0; i < data.size(); ++i)
		for (int j = i; j < data.size(); ++j)
			if(data[j] < data[i])
				std::swap(data[i], data[j]);
}

template<typename T>
void bubble_sort_opt(std::vector<T> &data)
{
	T temp;
	int backward_distance;
	int di;
	int dj;
	for (int i = 0; i < data.size(); ++i)
		for (int j = i; j < data.size(); ++j)
		{
			backward_distance = (j - i) * static_cast<int>(data[i] < data[j]);
			std::swap(data[i + backward_distance], data[j]);
		}
}

template<typename T>
void round_array(std::vector<T> &data)
{
	for (auto it = data.begin(); it != data.end(); ++it)
		if (*it >= 0)
			*it = static_cast<T>(static_cast<long long>(*it + 0.5f));
		else
			*it = static_cast<T>(static_cast<long long>(*it - 0.5f));
}

template<typename T>
void round_array_opt(std::vector<T> &data)
{
	for (auto it = data.begin(); it != data.end(); ++it)
		*it = static_cast<T>(static_cast<long long>(*it + 0.5f - static_cast<float>(*it < 0)));
}

template<typename T, typename U, typename V>
void polynom_multiple(T &result, const U &lhs, const V &rhs)
{
	std::fill(result.begin(), result.end(), static_cast<typename T::value_type>(0));
	for (size_t i = 0; i < lhs.size(); ++i)
		for (size_t j = 0; j < rhs.size(); ++j)
			result[i + j] += lhs[i] * rhs[j];
}

int main()
{
	constexpr size_t data_count = 4 * 1024;

	std::setlocale(LC_ALL, "");
	srand(time(nullptr));

	std::vector<float> data(data_count);
	std::vector<float> data1(data_count);
	std::vector<float> data2(data_count);
	std::generate(data.begin(), data.end(), []() -> float { return static_cast<float>(rand() % 101 - 50) / 10.0f; });
	std::copy(data.begin(), data.end(), data1.begin());
	std::copy(data.begin(), data.end(), data2.begin());
	data.clear();
	if (!std::equal(data1.begin(), data1.end(), data2.begin(), data2.end()))
	{
		std::wcout << L"Data error! (Line 129)" << std::endl;
		return -1;
	}

	std::wcout.precision(10);
	std::wcout << L"№  Название\t\tНеопт.\t\tОптимиз.\t" << std::endl;
	std::wcout << L"\t\t\tВремя\t\tТакты\tВремя\t\tТакты" << std::endl;

	auto bench_heavy = benchmark([&data1]() { positive_count(data1); });
	auto bench_light = benchmark([&data2]() { positive_count_opt(data2); });
	std::wcout << L"1. Позитивные числа\t";
	std::wcout << bench_heavy.first << "\t\t" << bench_heavy.second << "\t" << bench_light.first << "\t\t" << bench_light.second << std::endl;

	bench_heavy = benchmark([&data1]() { bubble_sort(data1); });
	bench_light = benchmark([&data2]() { bubble_sort_opt(data2); });
	if (!std::equal(data1.begin(), data1.end(), data2.begin(), data2.end()))
	{
		std::wcout << L"Data error! (Line 146)" << std::endl;
		return -1;
	}
	std::wcout << L"2. Сортировка пузырьком\t";
	std::wcout << bench_heavy.first << "\t" << bench_heavy.second << "\t" << bench_light.first << "\t" << bench_light.second << std::endl;

	bench_heavy = benchmark([&data1]() { round_array(data1); });
	bench_light = benchmark([&data2]() { round_array_opt(data2); });
	if (!std::equal(data1.begin(), data1.end(), data2.begin(), data2.end()))
	{
		std::wcout << L"Data error! (Line 156)" << std::endl;
		return -1;
	}
	std::wcout << L"3. Округление числел\t";
	std::wcout << bench_heavy.first << "\t\t" << bench_heavy.second << "\t" << bench_light.first << "\t\t" << bench_light.second << std::endl;

	std::array<int, 4> poly_left = { 2, 4, 6, 8 };
	std::array<int, 3> poly_right = { 1, 0, -1 };
	std::array<int, poly_left.size() + poly_right.size() - 1> poly_result;
	bench_heavy = benchmark([&poly_result, &poly_left, &poly_right]() { polynom_multiple(poly_result, poly_left, poly_right); });
	std::wcout << L"4. Умножение полиномов\t";
	std::wcout << bench_heavy.first << "\t\t" << bench_heavy.second << std::endl;

	return 0;
}
