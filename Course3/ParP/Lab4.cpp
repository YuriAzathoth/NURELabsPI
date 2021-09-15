#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <omp.h>
#include <pthread.h>
#include <sys/sysinfo.h>
#include <sys/unistd.h>
#include "bench.h"

template<typename T>
std::pair<T, int> calculate_pi_wallis()
{
	T sum_tmp = 1.0;
	T sum_res = 1.0;
	T sqr;
	for (T i = 2.0; ; i += 2.0)
	{
		sqr = (i * i);
		sum_tmp *= sqr / (sqr - 1);
		if (sum_tmp != sum_res)
			sum_res = sum_tmp;
		else
			return { 2.0 * sum_tmp, static_cast<int>(i / 2.0) };
	}
}

template<typename T>
std::pair<T, int> calculate_pi_leibniz()
{
	T sum_tmp = 0.0;
	T sum_res = 0.0;
	for (T i = 0.0, j = 1.0; ; ++i, j *= -1.0)
	{
		sum_tmp += j / (2.0 * i + 1.0);
		if (sum_tmp != sum_res)
			sum_res = sum_tmp;
		else
			return { 4.0 * sum_tmp, static_cast<int>(i) };
	}
}

template<typename T>
std::pair<T, int> calculate_pi_nikalant()
{
	T sum_tmp = 3.0;
	T sum_res = 3.0;
	for (T i = 2.0, j = 1.0; ; i += 2, j *= -1.0)
	{
		sum_tmp += (4.0 * j) / (i * (i + 1) * (i + 2));
		if (sum_tmp != sum_res)
			sum_res = sum_tmp;
		else
			return { sum_tmp, static_cast<int>(i / 2) };
	}
}

template<typename T>
T calculate_pi_seq()
{
	static constexpr int ITERATIONS_COUNT = 8192;
	T sum = 3.0;
	int i = 2.0;
	for (i = 2; i < ITERATIONS_COUNT; i += 4)
		sum += 4.0 / (T)(i * (i + 1) * (i + 2)) - 4.0 / (T)((i + 2) * (i + 3) * (i + 4));
	return sum;
}

template<typename T>
struct pi_pthread_data
{
	T result;
	int id;
	int iterations;
};

template<typename T>
void* calculate_pi_pth_fun(void* ptr)
{
	pi_pthread_data<T>* data = reinterpret_cast<pi_pthread_data<T>*>(ptr);
	T sum = 0.0;
	int begin = 2 + (data->id) * data->iterations;
	int end = (data->id + 1) * data->iterations;
	for (int i = begin; i < end; i += 4)
		sum += 4.0 / (T)(i * (i + 1) * (i + 2)) - 4.0 / (T)((i + 2) * (i + 3) * (i + 4));
	data->result = sum;
	return nullptr;
}

template<typename T>
T calculate_pi_pth()
{
	static constexpr int ITERATIONS_COUNT = 8192;
	static const int threads_count = get_nprocs();
	static const int thread_iteration_count = ITERATIONS_COUNT / threads_count;
	std::vector<pthread_t> threads(threads_count);
	std::vector<pi_pthread_data<T>> thread_data(threads_count);
	for (int i = 0; i < threads_count; ++i)
	{
		thread_data[i].id = i;
		thread_data[i].iterations = thread_iteration_count;
		pthread_create(&threads[i], nullptr, calculate_pi_pth_fun<T>, reinterpret_cast<void*>(&thread_data[i]));
	}
	for (pthread_t &thread : threads)
		pthread_join(thread, nullptr);

	T sum = 0.0;
	for (const pi_pthread_data<T> &data : thread_data)
		sum += data.result;
	return sum + 3.0;
}

template<typename T>
T calculate_pi_omp()
{
	static constexpr int ITERATIONS_COUNT = 8192;
	T sum = 3.0;
	int i = 2.0;
	#pragma omp parallel for private(i) reduction(+:sum)
	for (i = 2; i < ITERATIONS_COUNT; i += 4)
		sum += 4.0 / (T)(i * (i + 1) * (i + 2)) - 4.0 / (T)((i + 2) * (i + 3) * (i + 4));
	return sum;
}

void task_1()
{
	std::wcout << L"Задание 1" << std::endl;
	std::wcout << L"omp_get_max_threads():\t" << omp_get_max_threads() << std::endl;
	std::wcout << L"POSIX:" << std::endl;
	std::wcout << L"sysconf():\t\t" << sysconf(_SC_NPROCESSORS_ONLN) << std::endl;
	std::wcout << L"get_nprocs():\t\t" << get_nprocs() << std::endl;
	std::wcout << std::endl;
}

void task_2()
{
	auto [res1, prec1] = calculate_pi_wallis<float>();
	auto [res2, prec2] = calculate_pi_leibniz<float>();
	auto [res3, prec3] = calculate_pi_nikalant<float>();
	std::wcout << L"Задание 2" << std::endl;
	std::wcout.precision(20);
	std::wcout << L"Валлис\t\t" << std::fixed << res1 << " (" << prec1 << ")" << std::endl;
	std::wcout << L"Лейбниц\t\t" << std::fixed << res2 << " (" << prec2 << ")" << std::endl;
	std::wcout << L"Никаллант\t" << std::fixed << res3 << " (" << prec3 << ")" << std::endl;
	std::wcout << L"Наилучшая: функция Никалланта" << std::endl;
	std::wcout << std::endl;
}

void task_3()
{
	auto [res4, prec4] = calculate_pi_nikalant<double>();
	std::wcout << L"Задание 3" << std::endl;
	std::wcout.precision(50);
	std::wcout << L"Рассчёт для double: " << res4 << " (" << prec4 << ")" << std::endl;
	std::wcout << std::endl;
}

void task_4()
{
	double res1;
	double res2;
	double res3;
	auto bench_seq = benchmark(100, [&res1]() { res1 = calculate_pi_seq<double>(); }, omp_get_wtime);
	auto bench_pth = benchmark(100, [&res2]() { res2 = calculate_pi_pth<double>(); }, omp_get_wtime);
	auto bench_omp = benchmark(100, [&res3]() { res3 = calculate_pi_omp<double>(); }, omp_get_wtime);

	std::wcout << L"Задание 4" << std::endl;
	std::wcout.precision(10);
	std::wcout << L"Обычная:  " << bench_seq << ": " << res1 << std::endl;
	std::wcout << L"pthreads: " << bench_pth << ": " << res1 << std::endl;
	std::wcout << L"OpenMP:   " << bench_omp << ": " << res2 << std::endl;
	std::wcout << std::endl;
}

int main()
{
	setlocale(LC_ALL, "");

	task_1();
	task_2();
	task_3();
	task_4();

	return 0;
}
