# Exercise 02: Identify Real Type

## What was done

Implemented a type identification system using `dynamic_cast` without `std::typeinfo`:
- `Base` class with a public virtual destructor (making it polymorphic — required for `dynamic_cast`)
- `A`, `B`, `C` — empty classes that publicly inherit from `Base`
- `generate()` — randomly instantiates A, B, or C and returns as `Base*`
- `identify(Base* p)` — identifies the actual type via `dynamic_cast` on pointers
- `identify(Base& p)` — identifies the actual type via `dynamic_cast` on references (no pointers allowed inside)

## Key design decisions

- **Why `virtual ~Base()`?** `dynamic_cast` requires the type to be polymorphic — it needs at least one virtual function to determine the actual runtime type. The virtual destructor serves double duty: it makes the class polymorphic AND ensures proper cleanup of derived objects through base pointers.

- **Pointer version of `identify`**: Uses `dynamic_cast<A*>(p)` which returns `NULL` (or `nullptr` in C++11) if the cast fails. This is a clean, non-throwing approach — just check if the result is non-null.

- **Reference version of `identify`**: Since using pointers inside this function is forbidden, we cannot use `dynamic_cast<A*>(&p)`. Instead, we use `dynamic_cast<A&>(p)` which throws `std::bad_cast` on failure. We catch the exception and try the next type. The `(void)` suppresses the "unused result" warning since we only care whether the cast succeeds.

- **Why NOT `std::typeinfo`?** The subject explicitly forbids `#include <typeinfo>`. `dynamic_cast` is the C++-correct way to identify types in a polymorphic hierarchy without RTTI's `typeid` operator.

- **Not Orthodox Canonical Form**: The subject explicitly states these classes don't need OCF since they're empty utility classes with no data members.

## The three C++ casts in this module

| Cast | Exercise | Purpose |
|------|----------|---------|
| `static_cast` | ex00 | Compile-time type conversions between related types (numeric types). Safe, no runtime cost. |
| `reinterpret_cast` | ex01 | Reinterpret bit patterns (pointer ↔ integer). Dangerous, no safety checks. |
| `dynamic_cast` | ex02 | Runtime type identification in polymorphic hierarchies. Safe, has runtime cost (RTTI). |

## Files

| File | Purpose |
|------|---------|
| `Base.hpp` | Base, A, B, C class declarations + function prototypes |
| `Base.cpp` | generate(), identify() implementations using dynamic_cast |
| `main.cpp` | Test program generating random types and identifying them |
| `Makefile` | Build system |