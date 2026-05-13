# Exercise 00: Conversion of Scalar Types

## What was done

Implemented a `ScalarConverter` class with a single static method `convert()` that takes a string representation of a C++ literal and displays its value as all four scalar types: `char`, `int`, `float`, and `double`.

## Key design decisions

- **Non-instantiable class**: Private constructor, copy constructor, assignment operator, and destructor prevent users from creating instances. This is correct because the class is purely a utility with a static method — it stores no state.

- **Type detection**: The `detectType()` helper function parses the string literal to determine if it represents a `char`, `int`, `float`, `double`, or one of the pseudo-literals (`nan`, `±inf`, `nanf`, `±inff`). Char literals are detected both in quoted form (`'c'`) and bare form (`c` — when the shell strips quotes).

- **static_cast for conversions**: All explicit type conversions use `static_cast`, as required by the module theme (C++ casts). This is the correct cast for value conversions between numeric types.

- **Impossible/Non-displayable handling**:
  - `char: impossible` — when the value cannot be represented as a valid char (out of 0-127 range, NaN, infinity)
  - `char: Non displayable` — when the value is a valid char but not printable (control characters)
  - `int: impossible` — when the value overflows int range or is NaN/infinity
  - `float/double: impossible` — only for completely invalid input

- **Pseudo-literals**: `-inf`, `+inf`, `nan` (double) and `-inff`, `+inff`, `nanf` (float) are handled as special cases. Char and int conversions are always "impossible" for these.

## Files

| File | Purpose |
|------|---------|
| `ScalarConverter.hpp` | Class declaration with private constructors |
| `ScalarConverter.cpp` | Type detection, formatting, and convert implementation |
| `main.cpp` | Test program that takes a literal as CLI argument |
| `Makefile` | Build system |