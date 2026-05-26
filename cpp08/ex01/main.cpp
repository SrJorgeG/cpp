#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl;

	Span big(10000);
	std::srand(static_cast<unsigned int>(std::time(0)));
	for (int i = 0; i < 10000; ++i)
		big.addNumber(std::rand());

	std::cout << "Big span shortest: " << big.shortestSpan() << std::endl;
	std::cout << "Big span longest: " << big.longestSpan() << std::endl;

	std::cout << std::endl;

	Span range(10);
	std::vector<int> v;
	for (int i = 0; i < 10; ++i)
		v.push_back(i * 5);
	range.addRange(v.begin(), v.end());

	std::cout << "Range shortest: " << range.shortestSpan() << std::endl;
	std::cout << "Range longest: " << range.longestSpan() << std::endl;

	return 0;
}
