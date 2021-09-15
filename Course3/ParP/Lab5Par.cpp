#include <chrono>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <omp.h>

int main()
{
	std::vector<std::string> keys;
	std::ifstream file_keys("Lab5File1");
	std::string line;

	std::getline(file_keys, line);
	const size_t keys_count = std::stoull(line);

	while (std::getline(file_keys, line))
		keys.push_back(line);

	file_keys.close();

	std::ifstream file_data("Lab5File2");
	std::ofstream file_result("Lab5ResPar", std::ios_base::trunc);

	auto time_begin = std::chrono::system_clock::now();

	while (std::getline(file_data, line))
	{
		size_t i;
		size_t id = 0;
		bool found = false;
		#pragma omp parallel for shared(line, keys, found, id) private(i)
		for (i = 0; i < keys.size(); ++i)
			if (keys[i] == line)
			{
				id = i;
				found = true;
			}

		#pragma omp critical
		{
			if (found)
				file_result << line << " is found at index " << id << std::endl;
			else
				file_result << line << " is NOT FOUND" << std::endl;
		}
	}

	auto time_end = std::chrono::system_clock::now();
	std::cout.precision(6);
	std::cout << std::chrono::duration<double, std::micro>(time_end - time_begin).count() << " mcs" << std::endl;

	file_data.close();
	file_result.close();

	return 0;
}
