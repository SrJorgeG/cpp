# cpp

> 42 C++ Modules 00–09: from classes to the STL (C++98).

## What it does
All exercises of the 42 C++ piscine: classes, memory and references, operator overloading and fixed-point numbers, inheritance, polymorphism and abstract classes, exceptions, casts, templates, containers/iterators and STL (BitcoinExchange, RPN, PmergeMe). Several modules include my own notes (`EXPLANATION.md`, `MODULE_CONCLUSION.md`).

## Tech stack
C++98, Make

## Build & run
```bash
cd cpp09/ex01 && make && ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
# each exercise has its own Makefile
```

## Structure
`cppXX/exYY/` per exercise.

> Note: compiled `.o` files and binaries are committed; consider a `.gitignore`.

---
*Built at 42 Madrid by jgomez-d (Jorge Gomez De Oliveira).*
