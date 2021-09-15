#include <cstdlib>
#include <cstring>
#include <ctime>

#define BOOST_TEST_MODULE Lab1Test
#include <boost/test/included/unit_test.hpp>

#include "des.h"

BOOST_AUTO_TEST_CASE(random_data_processing)
{
	constexpr int DATA_MAX_SIZE = 100;
	constexpr int TESTS_COUNT = 100;

	srand(time(nullptr));

	char source[DATA_MAX_SIZE + 1];
	char result[DATA_MAX_SIZE + 1];

	for (int i = 2; i <= DATA_MAX_SIZE; ++i)
		for (int j = 0; j < TESTS_COUNT; ++j)
		{
			uint64_t key = (uint64_t)rand() & ((~0llu) >> 8);

			for (int k = 0; k < i - 1; ++k)
				source[k] = rand() % 255 + 1;
			source[i - 1] = 0;
			result[i - 1] = 0;
			strcpy(result, source);

			des_process(result, i, key, false);
			des_process(result, i, key, true);

			BOOST_TEST(!memcmp(source, result, i));
		}
}
