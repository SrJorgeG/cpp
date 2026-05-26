# Module 08: Templated Containers, Iterators, Algorithms

## What this module teaches

Module 08 is the gateway to the C++ Standard Template Library. After seven modules of manual memory management, raw pointers, and hand-rolled containers, this module introduces the real power of C++: generic programming with templates, iterator-based algorithms, and the STL container ecosystem.

## The progression

### Exercise 00 → Easy find: Templates meet algorithms
The simplest possible combination — a function template that uses `std::find`. It teaches that templates aren't just for classes; they work for functions too. The key insight is that any container exposing `begin()` and `end()` can be searched identically. The iterator abstraction makes algorithm code container-agnostic.

### Exercise 01 → Span: STL containers as building blocks
Span shows how to *use* an STL container (`std::vector`) as an internal data structure, combined with STL algorithms (`std::sort`, `std::min_element`, `std::max_element`) to solve real problems efficiently. The `addRange` template method introduces the pattern of accepting iterator ranges — the same pattern the STL itself uses everywhere. This is where you start thinking in terms of algorithms + containers rather than loops + arrays.

### Exercise 02 → Mutated abomination: Making containers iterable
MutantStack is the capstone: by inheriting from `std::stack` and exposing the underlying container's iterators, you make a non-iterable container adapter iterable. This exercise connects all the pieces — without iterators, you can't use algorithms. Without the iterator abstraction, `std::stack` is a dead end for anything beyond LIFO operations. Exposing iterators makes it a full citizen of the STL ecosystem.

## Key takeaways

1. **Iterators are the glue**: The STL's power comes from the iterator abstraction. Algorithms don't know about containers; they know about iterators. Any type that provides `begin()` and `end()` can participate.

2. **Templates enable genericity**: Whether it's a function template (`easyfind<T>`) or a class template (`MutantStack<T>`), templates let you write code once that works with any compatible type. The compiler generates the specialized code at instantiation time.

3. **Don't reinvent the wheel**: `std::sort`, `std::find`, `std::min_element`, `std::max_element` — these are battle-tested, optimized algorithms. Use them. Your hand-rolled loop is almost certainly slower and buggier.

4. **Container adapters expose `c`**: `std::stack`, `std::queue`, and `std::priority_queue` wrap an underlying container accessible via the protected `c` member. This is the escape hatch when you need more than the adapter's limited interface.

5. **Iterator ranges are the standard interface**: Passing `begin, end` pairs is how STL functions communicate ranges. It's more flexible than passing a container directly — you can work with subranges, filtered views, or any pair of iterators.

## How the exercises connect

The module follows a clear arc: **use** a template function with iterators (ex00), **build** a class that leverages STL containers and algorithms (ex01), then **extend** an existing STL component to support the iterator interface (ex02). By the end, you understand both sides of the iterator contract — consuming iterators via algorithms and providing iterators from your own types.
