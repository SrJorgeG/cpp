# Exercise 01: Serialization

## What was done

Implemented a `Serializer` class with two static methods that demonstrate `reinterpret_cast`:
- `serialize()` — converts a `Data*` pointer to `uintptr_t`
- `deserialize()` — converts a `uintptr_t` back to a `Data*` pointer

Also created a `Data` struct with data members (`id`, `name`, `value`) as required.

## Key design decisions

- **Non-instantiable class**: Same pattern as ex00 — private constructor, copy constructor, assignment operator, and destructor. The `Serializer` class is a utility with only static methods and no state.

- **reinterpret_cast**: This is the focus of the exercise. `reinterpret_cast` is the ONLY C++ cast that can convert between pointers and integers like `uintptr_t`. It reinterprets the bit pattern of the pointer as an integer (and vice versa). This is fundamentally different from `static_cast` (which performs value conversions) — `reinterpret_cast` does no computation, it just reinterprets the bits.

- **uintptr_t**: An unsigned integer type guaranteed to be large enough to hold a pointer value. Defined in `<stdint.h>` (C++98 compatible; `<cstdint>` requires C++11).

- **Pointer round-trip guarantee**: The test verifies that `deserialize(serialize(ptr)) == ptr`, proving the round-trip preserves the exact pointer value.

## Files

| File | Purpose |
|------|---------|
| `Serializer.hpp` | Data struct and Serializer class declaration |
| `Serializer.cpp` | serialize/deserialize implementation with reinterpret_cast |
| `main.cpp` | Test program verifying round-trip pointer equality |
| `Makefile` | Build system |