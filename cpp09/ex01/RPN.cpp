#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>

RPN::RPN() {}

RPN::RPN(RPN const &src) : _stack(src._stack) {}

RPN &RPN::operator=(RPN const &rhs)
{
	if (this != &rhs)
		_stack = rhs._stack;
	return *this;
}

RPN::~RPN() {}

bool RPN::_isOperator(char c) const
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::_applyOp(int a, int b, char op) const
{
	switch (op)
	{
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/':
			if (b == 0)
				return 0;
			return a / b;
		default: return 0;
	}
}

void RPN::evaluate(std::string const &expression)
{
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (token.length() == 1 && _isOperator(token[0]))
		{
			if (_stack.size() < 2)
			{
				std::cerr << "Error" << std::endl;
				return;
			}
			int b = _stack.top(); _stack.pop();
			int a = _stack.top(); _stack.pop();
			if (token[0] == '/' && b == 0)
			{
				std::cerr << "Error" << std::endl;
				return;
			}
			_stack.push(_applyOp(a, b, token[0]));
		}
		else if (token.length() == 1 && token[0] >= '0' && token[0] <= '9')
		{
			_stack.push(token[0] - '0');
		}
		else
		{
			std::cerr << "Error" << std::endl;
			return;
		}
	}

	if (_stack.size() != 1)
	{
		std::cerr << "Error" << std::endl;
		return;
	}

	std::cout << _stack.top() << std::endl;
}
