#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main()
{
	std::vector<int> v;
	for (int i = 0; i < 10; ++i)
		v.push_back(i * 3);

	std::cout << "=== Vector test ===" << std::endl;
	try
	{
		std::vector<int>::iterator it = easyfind(v, 9);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		easyfind(v, 42);
	}
	catch (std::runtime_error& e)
	{
		std::cout << "Not found: " << e.what() << std::endl;
	}

	std::list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);

	std::cout << "=== List test ===" << std::endl;
	try
	{
		std::list<int>::iterator it = easyfind(l, 30);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::deque<int> d;
	d.push_back(100);
	d.push_back(200);
	d.push_back(300);

	std::cout << "=== Const deque test ===" << std::endl;
	const std::deque<int>& cd = d;
	try
	{
		std::deque<int>::const_iterator it = easyfind(cd, 200);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
