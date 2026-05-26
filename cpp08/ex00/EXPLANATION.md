# Exercise 00: Easy find

## What it does

A function template `easyfind` that searches for the first occurrence of an integer value inside a generic container of integers. If the value is not found, it throws a `std::runtime_error`.

## Key concepts

- **Function templates**: The function is templated on the container type `T`, so it works with any STL sequential container (vector, list, deque).
- **STL algorithms**: Uses `std::find` from `<algorithm>` to perform the linear search.
- **Iterator return types**: The function returns `T::iterator` (or `T::const_iterator` for const containers), tying the return type to the container's own iterator typedef.
- **Exception handling**: Rather than returning a sentinel value, the function throws when the value isn't found, which is the idiomatic C++ approach.

## How the implementation works

Two overloads are provided:

1. **Non-const version**: Takes `T&` and returns `T::iterator`. This allows the caller to modify the found element through the returned iterator.
2. **Const version**: Takes `T const&` and returns `T::const_iterator`. This works with const containers and prevents modification.

Both use `std::find(container.begin(), container.end(), value)`. If the returned iterator equals `container.end()`, the value wasn't found and an exception is thrown.

## Design decisions

- **Two overloads instead of one template parameter for the iterator**: This keeps the API simple — the caller just passes a container and a value, without needing to specify iterator types.
- **`std::runtime_error` over custom exception class**: A standard exception is sufficient for this simple case. A custom exception class would add complexity without meaningful benefit.
- **No associative container support**: As specified, this only works with sequential containers where `std::find` with begin/end makes sense.
