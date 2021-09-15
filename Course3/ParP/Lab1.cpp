#include <clocale>
#include <ctime>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>
#include <sys/time.h>
#include <sys/unistd.h>
#include <omp.h>
#include "bench.h"
#include "matrix.h"

void task_1()
{
	time_t int_max = 0x7FFFFFFF;
	std::wcout << L"Задание 1" << std::endl;
	std::wcout << L"Дата последнего использования time(): " << std::asctime(std::localtime(&int_max)) << std::endl;
	std::wcout << std::endl;
}

void task_2()
{
	timeval tv1;
	timeval tv2;
	struct timezone tz1;
	struct timezone tz2;
	timespec ts1;
	timespec ts2;

	auto _time = time(nullptr);
	auto _clock = clock();
	auto _rdtsc = __rdtsc();
	auto _chrono = std::chrono::system_clock::now();
	auto _omp = omp_get_wtime();
	gettimeofday(&tv1, &tz1);
	clock_gettime(CLOCK_REALTIME, &ts1);

	sleep(1);

	auto __time = time(nullptr) - _time;
	auto __clock = clock() - _clock;
	auto rdtsc = __rdtsc() - _rdtsc;
	auto __chrono = std::chrono::system_clock::now() - _chrono;
	auto __omp = omp_get_wtime() - _omp;
	gettimeofday(&tv2, &tz2);
	clock_gettime(CLOCK_REALTIME, &ts2);
	auto _sec = tv2.tv_sec - tv1.tv_sec;
	auto _usec = tv2.tv_usec - tv1.tv_usec;
    auto __sec = ts2.tv_sec - ts1.tv_sec;
    auto __nsec = ts2.tv_nsec - ts1.tv_nsec;

	std::wcout << L"Задание 2" << std::endl;
	std::wcout << L"Данные при паузе в 1 сек:" << std::endl;
	std::wcout << L"time(): " << __time << std::endl;
	std::wcout << L"clock(): " << __clock << std::endl;
	std::wcout << L"__rdtsc(): " << rdtsc << std::endl;
	std::wcout << L"std::chrono: " << std::fixed << std::chrono::duration<double, std::micro>(__chrono).count() << std::endl;
	std::wcout << L"omp_get_wtime(): " << __omp << std::endl;
	std::wcout << L"POSIX:" << std::endl;
	std::wcout << L"gettimeofday(): " << _sec << "sec " << _usec << "usec" << std::endl;
	std::wcout << L"clock_gettime(): " << __sec << "sec " << __nsec << "nsec" << std::endl;
	std::wcout << std::endl;
}

void task_3()
{
	static constexpr size_t data_count = 1'000;
	static constexpr size_t tests_count = 100;

	std::wcout	<< L"Задание 3" << std::endl;
	std::wcout	<< L"__rdtsc(): "
				<< benchmark(tests_count, bench_add<data_count>(), __rdtsc)
				<< std::endl;
	std::wcout	<< L"clock_gettime(): "
				<< benchmark(tests_count, bench_add<data_count>(), clock_gettime_nsec)
				<< std::endl;
	std::wcout	<< std::endl;
}

void task_4()
{
	static constexpr size_t tests_count = 10;
	auto t1 = benchmark(tests_count, bench_add<100'000>(), clock_gettime_nsec);
	auto t2 = benchmark(tests_count, bench_add<200'000>(), clock_gettime_nsec);
	auto t3 = benchmark(tests_count, bench_add<300'000>(), clock_gettime_nsec);

	std::wcout << L"Задание 4" << std::endl;
	std::wcout << L"Абсолютное измерение" << std::endl;
	std::wcout << L"100тыс: " << std::fixed << benchmark(tests_count, bench_add<100'000>(), omp_get_wtime) << std::endl;
	std::wcout << L"200тыс: " << std::fixed << benchmark(tests_count, bench_add<200'000>(), omp_get_wtime) << std::endl;
	std::wcout << L"300тыс: " << std::fixed << benchmark(tests_count, bench_add<300'000>(), omp_get_wtime) << std::endl;
	std::wcout << L"Относительное измерение" << std::endl;
	std::wcout << L"100тыс: 1" << std::endl;
	std::wcout << L"200тыс: " << static_cast<float>(t2) / static_cast<float>(t1) << std::endl;
	std::wcout << L"300тыс: " << static_cast<float>(t3) / static_cast<float>(t1) << std::endl;
	std::wcout << std::endl;
}

void task_5()
{
	std::wcout << L"Задание 5" << std::endl;
	std::wcout << L"Общая сложность: O(n^3 + n^2 + n)" << std::endl;
	std::wcout << L"512x512   O(" << mprod_complexity<512>::value << L"):" << std::endl;
	std::wcout << L"  Последовательно: " << benchmark(1, bench_prod_seq<512, int>(), omp_get_wtime) << std::endl;
	std::wcout << L"  Параллельно:     " << benchmark(1, bench_prod_par<512, int>(), omp_get_wtime) << std::endl;
	std::wcout << L"1024x1024 O(" << mprod_complexity<1024>::value << L"):" << std::endl;
	std::wcout << L"  Последовательно: " << benchmark(1, bench_prod_seq<1024, int>(), omp_get_wtime) << std::endl;
	std::wcout << L"  Параллельно:     " << benchmark(1, bench_prod_par<1024, int>(), omp_get_wtime) << std::endl;
	std::wcout << L"2048x2048 O(" << mprod_complexity<2048>::value << L"):" << std::endl;
	std::wcout << L"  Последовательно: " << benchmark(1, bench_prod_seq<2048, int>(), omp_get_wtime) << std::endl;
	std::wcout << L"  Параллельно:     " << benchmark(1, bench_prod_par<2048, int>(), omp_get_wtime) << std::endl;
	std::wcout << std::endl;
}

void task_6()
{
	constexpr size_t matrix_size = 512;
	std::wcout << L"Задание 6" << std::endl;
	std::wcout << L"int8:   " << benchmark(10, bench_prod_seq<matrix_size, int8_t>(), omp_get_wtime) << std::endl;
	std::wcout << L"int16:  " << benchmark(10, bench_prod_seq<matrix_size, int16_t>(), omp_get_wtime) << std::endl;
	std::wcout << L"int32:  " << benchmark(10, bench_prod_seq<matrix_size, int32_t>(), omp_get_wtime) << std::endl;
	std::wcout << L"int64:  " << benchmark(10, bench_prod_seq<matrix_size, int64_t>(), omp_get_wtime) << std::endl;
	std::wcout << L"float:  " << benchmark(10, bench_prod_seq<matrix_size, float>(), omp_get_wtime) << std::endl;
	std::wcout << L"double: " << benchmark(10, bench_prod_seq<matrix_size, double>(), omp_get_wtime) << std::endl;
	std::wcout << std::endl;
}

int main()
{
	std::setlocale(LC_ALL, "");
	srand(time(nullptr));

	task_1();
	task_2();
	task_3();
	task_4();
	task_5();
	task_6();

	return 0;
}
