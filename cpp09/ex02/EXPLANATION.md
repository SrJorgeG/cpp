# Exercise 02: PmergeMe — Ford-Johnson Merge-Insertion Sort

## What it does

Sorts a sequence of positive integers using the Ford-Johnson (merge-insertion) algorithm, implemented separately with `std::vector` and `std::deque`, and displays timing information for both.

## Key concepts

- **Ford-Johnson Algorithm**: A comparison-based sorting algorithm that minimizes the number of comparisons. It works in three phases:
  1. **Pairing**: Group elements into pairs, compare each pair, and separate into "winners" (larger) and "losers" (smaller).
  2. **Recursive sorting**: Recursively sort the winners (the "main chain").
  3. **Insertion**: Insert the losers into the main chain using binary search, following the Jacobsthal sequence order for optimal comparison count.

- **Jacobsthal Sequence**: The sequence 1, 3, 5, 11, 21, 43, ... defined by J(n) = J(n-1) + 2*J(n-2). Ford-Johnson uses this sequence to determine the optimal insertion order for the pend (loser) elements, minimizing comparisons.

- **std::vector vs std::deque**: The exercise requires implementing the same algorithm with both containers to compare performance characteristics.

## How the implementation works

1. **Pairing phase**: Iterate through the container, comparing adjacent elements. Store pairs as (larger, smaller). If the container has an odd number of elements, save the last element as a "straggler."

2. **Recursive sort**: Extract the larger elements from all pairs into a "main chain" and recursively apply the algorithm.

3. **Build pend array**: After the main chain is sorted, create a pend array where `pend[i]` is the smaller element whose partner is `mainChain[i]`. This preserves the correspondence between winners and losers.

4. **Jacobsthal insertion**: Insert pend elements into the main chain using binary search (`std::lower_bound`), but in the order dictated by the Jacobsthal sequence. This order minimizes the total number of comparisons.

5. **Insert straggler**: If there was an odd element, binary-search insert it last.

6. **Timing**: Use `std::clock()` to measure processing time for each container separately.

## Container choices

**std::vector** and **std::deque** were chosen because:
- They are the two remaining STL containers not used in previous exercises (ex00 used `std::map`, ex01 used `std::stack`).
- Both support random-access iterators, which are required for `std::lower_bound` binary search.
- Their different memory layouts allow meaningful performance comparison:
  - `std::vector`: Contiguous memory, excellent cache locality, but insertions in the middle require shifting elements.
  - `std::deque`: Chunked memory, slightly worse cache locality for sequential access, but front/middle insertions can be faster in theory.

The algorithm is implemented separately for each container (not templated) as required by the subject, ensuring container-specific behavior is visible.
