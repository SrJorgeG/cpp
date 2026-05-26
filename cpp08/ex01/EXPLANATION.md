# Exercise 01: Span

## What it does

A `Span` class that stores up to N integers (N set at construction) and can compute the shortest and longest distance between any two stored numbers. It supports adding numbers one at a time or in bulk via an iterator range.

## Key concepts

- **Orthodox Canonical Form**: The class implements default constructor, parameterized constructor, copy constructor, copy assignment operator, and destructor.
- **STL containers**: Uses `std::vector<int>` internally for efficient random access and sorting.
- **STL algorithms**: Uses `std::sort`, `std::min_element`, and `std::max_element`.
- **Member function templates**: The `addRange` method is templated on an iterator type, allowing any iterator range to be inserted.
- **Exception safety**: Throws descriptive exceptions when the container is full or when span calculations lack sufficient data.

## How the implementation works

- **addNumber**: Checks if `_numbers.size() >= _maxSize` before pushing. Throws if full.
- **addRange**: Uses `std::distance` to verify the range fits within remaining capacity, then uses `vector::insert` to add all elements at once.
- **shortestSpan**: Creates a sorted copy of the numbers, then iterates adjacent pairs to find the minimum difference. Sorting is O(n log n), and the linear scan is O(n).
- **longestSpan**: Simply finds the min and max elements (O(n) each via `std::min_element`/`std::max_element`) and returns their difference.

## Design decisions

- **Sorted copy for shortestSpan**: Sorting a copy avoids modifying the original insertion order. The O(n log n) cost is acceptable given we need to compare adjacent elements.
- **Separate min/max for longestSpan**: No need to sort — just find the extremes. This is O(n) vs O(n log n) for sorting.
- **unsigned int for spans**: Distances between integers are non-negative, so `unsigned int` is the appropriate return type and matches the expected output format.
- **Template method in header**: `addRange` is a template method, so its implementation lives in the header file. This is a standard C++ pattern — template definitions must be visible at instantiation time.
