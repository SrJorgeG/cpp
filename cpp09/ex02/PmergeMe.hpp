#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(PmergeMe const &src);
	PmergeMe &operator=(PmergeMe const &rhs);
	~PmergeMe();

	void sortVector(std::vector<int> &v);
	void sortDeque(std::deque<int> &d);

private:
	void _mergeInsertSortVector(std::vector<int> &v);
	void _mergeInsertSortDeque(std::deque<int> &d);
	std::vector<size_t> _jacobsthalSequence(size_t n) const;
};

#endif
