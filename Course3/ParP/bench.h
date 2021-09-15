#ifndef BENCH_H
#define BENCH_H

#include <algorithm>
#include <chrono>
#include <numeric>
#include <vector>

inline void __cpuid(unsigned* regs, unsigned func_id)
{
	asm volatile ("cpuid" : "=a"(regs[0]), "=b"(regs[1]), "=c"(regs[2]), "=d"(regs[3]) : "a"(func_id), "c"(0));
}

inline void __cpuid_ex(unsigned* regs, unsigned func_id, unsigned subfunc_id)
{
	asm volatile ("cpuid" : "=a"(regs[0]), "=b"(regs[1]), "=c"(regs[2]), "=d"(regs[3]) : "a"(func_id), "c"(subfunc_id));
}

inline uint64_t __rdtsc()
{
	unsigned lo;
	unsigned hi;
	asm volatile("rdtsc" : "=a" (lo), "=d" (hi));
	return (uint16_t)(lo) | ((uint64_t)(hi) << 32llu);
}

inline size_t clock_gettime_nsec()
{
	timespec result;
	clock_gettime(CLOCK_REALTIME, &result);
	return static_cast<size_t>(result.tv_nsec);
}

template<typename TFNFunction, typename TFNBenchmarker>
auto benchmark(size_t tests_count, TFNFunction function, TFNBenchmarker benchmarker)
{
	using TTime = decltype(benchmarker());
	TTime time_min = std::max(std::numeric_limits<TTime>::infinity(), std::numeric_limits<TTime>::max());
	TTime time_start;
	TTime time_end;
	TTime time_current;

	unsigned regs[4] = {0};
	__cpuid(regs, 0);
	for (size_t i = 0; i < tests_count; ++i)
	{
		time_start = benchmarker();
		function();
		time_end = benchmarker();
		time_current = time_end - time_start;
		if (time_current < time_min)
			time_min = time_current;
	}

	return time_min;
}

template<size_t data_count>
struct bench_add
{
	void operator()()
	{
		std::vector<float> lhs(data_count);
		std::vector<float> rhs(data_count);
		std::vector<float> res(data_count);
		std::iota(lhs.begin(), lhs.end(), 1.0f);
		std::iota(rhs.begin(), rhs.end(), 1.0f);
		std::transform(lhs.begin(), lhs.end(), rhs.begin(), res.begin(), std::plus<float>());
	};
};

#endif // BENCH_H
