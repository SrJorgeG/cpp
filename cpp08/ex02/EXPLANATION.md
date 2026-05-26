# Exercise 02: Mutated abomination

## What it does

A `MutantStack` class that inherits from `std::stack` and exposes the underlying container's iterators, making a stack iterable just like any other STL container.

## Key concepts

- **Inheriting from STL containers**: `std::stack` is a container adapter. It wraps an underlying container (default: `std::deque`) and exposes only stack operations. By inheriting from it, we get all stack functionality for free.
- **The `c` member**: `std::stack` stores its underlying container in a protected member called `c`. Accessing `this->c` gives us the deque, which has `begin()`, `end()`, and their variants.
- **Iterator typedefs**: The class exposes `iterator`, `const_iterator`, `reverse_iterator`, and `const_reverse_iterator` typedefs that map directly to the underlying container's iterator types.
- **Liskov substitution**: A `MutantStack` can be used wherever a `std::stack` is expected, as demonstrated by `std::stack<int> s(mstack)`.

## How the implementation works

The class inherits publicly from `std::stack<T>`, which means all of `push`, `pop`, `top`, `size`, `empty`, and the constructors are available without reimplementation.

The key addition is the set of `begin()`/`end()` methods that delegate to `this->c.begin()`/`this->c.end()`. Since the underlying container (by default `std::deque`) already supports iterators, this is a thin forwarding layer.

Both const and non-const overloads are provided, along with reverse iterator variants.

## Design decisions

- **Why inherit and not wrap**: Inheritance gives us all of `std::stack`'s interface for free. Since `std::stack` doesn't have a virtual destructor, this is acceptable because we're not deleting through a base pointer to a derived object in typical usage.
- **Exposing `c` directly**: The protected `c` member is an implementation detail of `std::stack`, but it's guaranteed by the standard and is the only clean way to access the underlying container's iterators.
- **Full iterator suite**: Providing const and reverse iterators makes `MutantStack` compatible with STL algorithms that require different iterator categories.
