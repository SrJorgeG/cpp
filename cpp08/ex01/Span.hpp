#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>

class Span
{
private:
	unsigned int _maxSize;
	std::vector<int> _numbers;

public:
	Span();
	Span(unsigned int n);
	Span(Span const& other);
	Span& operator=(Span const& other);
	~Span();

	void addNumber(int num);

	template <typename InputIterator>
	void addRange(InputIterator begin, InputIterator end)
	{
		if (static_cast<unsigned int>(std::distance(begin, end)) > _maxSize - _numbers.size())
			throw std::runtime_error("Not enough space to add range");
		_numbers.insert(_numbers.end(), begin, end);
	}

	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
};
