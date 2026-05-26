#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	std::vector<int> vec;
	std::deque<int> deq;

	for (int i = 1; i < argc; i++)
	{
		std::string arg(argv[i]);
		for (size_t j = 0; j < arg.size(); j++)
		{
			if (arg[j] < '0' || arg[j] > '9')
			{
				std::cerr << "Error" << std::endl;
				return 1;
			}
		}
		int val = std::atoi(argv[i]);
		if (val < 0)
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
		vec.push_back(val);
		deq.push_back(val);
	}

	std::cout << "Before: ";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << (i + 1 < vec.size() ? " " : "");
	std::cout << std::endl;

	PmergeMe pme;

	clock_t start1 = std::clock();
	pme.sortVector(vec);
	clock_t end1 = std::clock();

	clock_t start2 = std::clock();
	pme.sortDeque(deq);
	clock_t end2 = std::clock();

	std::cout << "After:  ";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << (i + 1 < vec.size() ? " " : "");
	std::cout << std::endl;

	double timeVec = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000000.0;
	double timeDeq = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000000.0;

	std::cout << "Time to process a range of " << vec.size()
	          << " elements with std::vector : "
	          << std::fixed << std::setprecision(5) << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << deq.size()
	          << " elements with std::deque : "
	          << std::fixed << std::setprecision(5) << timeDeq << " us" << std::endl;

	return 0;
}
