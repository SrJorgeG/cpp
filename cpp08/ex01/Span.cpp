#include "Span.hpp"
#include <algorithm>
#include <climits>

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(Span const& other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span& Span::operator=(Span const& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int num)
{
	if (_numbers.size() >= _maxSize)
		throw std::runtime_error("Span is already full");
	_numbers.push_back(num);
}

unsigned int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to calculate span");

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	unsigned int minSpan = static_cast<unsigned int>(sorted[1] - sorted[0]);
	for (std::size_t i = 1; i < sorted.size() - 1; ++i)
	{
		unsigned int diff = static_cast<unsigned int>(sorted[i + 1] - sorted[i]);
		if (diff < minSpan)
			minSpan = diff;
	}
	return minSpan;
}

unsigned int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to calculate span");

	int minVal = *std::min_element(_numbers.begin(), _numbers.end());
	int maxVal = *std::max_element(_numbers.begin(), _numbers.end());

	return static_cast<unsigned int>(maxVal - minVal);
}
