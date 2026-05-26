#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN
{
public:
	RPN();
	RPN(RPN const &src);
	RPN &operator=(RPN const &rhs);
	~RPN();

	void evaluate(std::string const &expression);

private:
	std::stack<int> _stack;

	bool _isOperator(char c) const;
	int _applyOp(int a, int b, char op) const;
};

#endif
