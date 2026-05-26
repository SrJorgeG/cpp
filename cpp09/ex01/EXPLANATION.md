# Exercise 01: Reverse Polish Notation

## What it does

Evaluates a mathematical expression written in Reverse Polish Notation (postfix notation). Numbers are always single digits (0–9), and supported operators are `+`, `-`, `*`, `/`.

## Key concepts

- **std::stack**: The natural container for RPN evaluation. A stack provides LIFO (Last In, First Out) access, which maps directly to how RPN works: push operands, pop them when an operator arrives, push the result back.
- **Reverse Polish Notation**: Also called postfix notation. Operators follow their operands: `3 4 +` means `3 + 4`. No parentheses needed because operator precedence is encoded in the order.
- **Tokenization**: Using `std::istringstream` with `>>` operator to split the expression by whitespace.

## How the implementation works

1. Tokenize the input string using `std::istringstream`, extracting space-separated tokens.
2. For each token:
   - If it's a single digit (0–9), push it onto the stack.
   - If it's an operator (`+`, `-`, `*`, `/`), pop two operands, apply the operation, and push the result. The first popped value is the right operand, the second is the left operand (important for subtraction and division).
   - If it's anything else (parentheses, multi-character strings, etc.), print "Error" and return.
3. After processing all tokens, the stack must contain exactly one element — the result. Otherwise, print "Error".

## Container choice

**std::stack** was chosen because:
- RPN evaluation is the textbook use case for a stack data structure.
- The LIFO ordering directly models how postfix expressions are evaluated.
- `std::stack` is a container adapter (typically backed by `std::deque`) that restricts the interface to `push`, `pop`, and `top` — exactly the operations we need.
- Using a different container (like a vector with push_back/pop_back) would work, but `std::stack` communicates intent clearly and prevents accidental misuse.
