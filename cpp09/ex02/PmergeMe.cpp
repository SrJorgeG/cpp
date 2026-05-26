#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &src) {(void)src;}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {(void)rhs; return *this;}

PmergeMe::~PmergeMe() {}

std::vector<size_t> PmergeMe::_jacobsthalSequence(size_t n) const
{
	std::vector<size_t> seq;
	if (n == 0)
		return seq;
	seq.push_back(1);
	if (n == 1)
		return seq;
	seq.push_back(3);
	size_t i = 2;
	while (true)
	{
		size_t next = seq[i - 1] + 2 * seq[i - 2];
		if (next >= n)
			break;
		seq.push_back(next);
		i++;
	}
	return seq;
}

void PmergeMe::_mergeInsertSortVector(std::vector<int> &v)
{
	if (v.size() <= 1)
		return;

	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i + 1 < v.size(); i += 2)
	{
		if (v[i] < v[i + 1])
			pairs.push_back(std::make_pair(v[i + 1], v[i]));
		else
			pairs.push_back(std::make_pair(v[i], v[i + 1]));
	}

	int oddElement = 0;
	bool hasOdd = (v.size() % 2 != 0);
	if (hasOdd)
		oddElement = v[v.size() - 1];

	std::vector<int> mainChain;
	for (size_t j = 0; j < pairs.size(); j++)
		mainChain.push_back(pairs[j].first);

	_mergeInsertSortVector(mainChain);

	std::vector<int> pend(pairs.size());
	std::vector<int> pairMain(pairs.size());
	for (size_t j = 0; j < pairs.size(); j++)
	{
		for (size_t k = 0; k < mainChain.size(); k++)
		{
			if (mainChain[k] == pairs[j].first)
			{
				pend[k] = pairs[j].second;
				pairMain[k] = pairs[j].first;
				break;
			}
		}
	}

	std::vector<size_t> jacob = _jacobsthalSequence(pend.size());

	std::vector<bool> inserted(pend.size(), false);
	size_t prevEnd = 0;
	for (size_t j = 0; j < jacob.size(); j++)
	{
		size_t end = jacob[j];
		if (end > pend.size())
			end = pend.size();
		for (size_t k = end; k > prevEnd; k--)
		{
			if (!inserted[k - 1])
			{
				std::vector<int>::iterator bound =
					std::lower_bound(mainChain.begin(), mainChain.end(), pend[k - 1]);
				mainChain.insert(bound, pend[k - 1]);
				inserted[k - 1] = true;
			}
		}
		prevEnd = end;
	}

	for (size_t k = 0; k < pend.size(); k++)
	{
		if (!inserted[k])
		{
			std::vector<int>::iterator bound =
				std::lower_bound(mainChain.begin(), mainChain.end(), pend[k]);
			mainChain.insert(bound, pend[k]);
		}
	}

	if (hasOdd)
	{
		std::vector<int>::iterator bound =
			std::lower_bound(mainChain.begin(), mainChain.end(), oddElement);
		mainChain.insert(bound, oddElement);
	}

	v = mainChain;
}

void PmergeMe::_mergeInsertSortDeque(std::deque<int> &d)
{
	if (d.size() <= 1)
		return;

	std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0; i + 1 < d.size(); i += 2)
	{
		if (d[i] < d[i + 1])
			pairs.push_back(std::make_pair(d[i + 1], d[i]));
		else
			pairs.push_back(std::make_pair(d[i], d[i + 1]));
	}

	int oddElement = 0;
	bool hasOdd = (d.size() % 2 != 0);
	if (hasOdd)
		oddElement = d[d.size() - 1];

	std::deque<int> mainChain;
	for (size_t j = 0; j < pairs.size(); j++)
		mainChain.push_back(pairs[j].first);

	_mergeInsertSortDeque(mainChain);

	std::deque<int> pend(pairs.size());
	for (size_t j = 0; j < pairs.size(); j++)
	{
		for (size_t k = 0; k < mainChain.size(); k++)
		{
			if (mainChain[k] == pairs[j].first)
			{
				pend[k] = pairs[j].second;
				break;
			}
		}
	}

	std::vector<size_t> jacob = _jacobsthalSequence(pend.size());

	std::vector<bool> inserted(pend.size(), false);
	size_t prevEnd = 0;
	for (size_t j = 0; j < jacob.size(); j++)
	{
		size_t end = jacob[j];
		if (end > pend.size())
			end = pend.size();
		for (size_t k = end; k > prevEnd; k--)
		{
			if (!inserted[k - 1])
			{
				std::deque<int>::iterator bound =
					std::lower_bound(mainChain.begin(), mainChain.end(), pend[k - 1]);
				mainChain.insert(bound, pend[k - 1]);
				inserted[k - 1] = true;
			}
		}
		prevEnd = end;
	}

	for (size_t k = 0; k < pend.size(); k++)
	{
		if (!inserted[k])
		{
			std::deque<int>::iterator bound =
				std::lower_bound(mainChain.begin(), mainChain.end(), pend[k]);
			mainChain.insert(bound, pend[k]);
		}
	}

	if (hasOdd)
	{
		std::deque<int>::iterator bound =
			std::lower_bound(mainChain.begin(), mainChain.end(), oddElement);
		mainChain.insert(bound, oddElement);
	}

	d = mainChain;
}

void PmergeMe::sortVector(std::vector<int> &v)
{
	_mergeInsertSortVector(v);
}

void PmergeMe::sortDeque(std::deque<int> &d)
{
	_mergeInsertSortDeque(d);
}
