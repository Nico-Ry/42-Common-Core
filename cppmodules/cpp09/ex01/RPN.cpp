/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:14:43 by nryser            #+#    #+#             */
/*   Updated: 2026/02/04 19:14:43 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : _result(0)
{
}

RPN::RPN(const RPN &other) : _stack(other._stack), _result(other._result)
{
}

RPN	&RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		_stack = other._stack;
		_result = other._result;
	}
	return (*this);
}

RPN::~RPN()
{
}

int	RPN::getResult() const
{
	return (_result);
}

bool	RPN::isOperator(char c) const
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

/*
	Applies op to the top 2 stack values.

	Important:
	- The order matters: for "a b -" we must compute a - b
	- Division by 0 is an error
*/
void	RPN::applyOperator(char op)
{
	int	b;
	int	a;
	int	r;

	if (_stack.size() < 2)
		throw std::string("Error");

	b = _stack.top();
	_stack.pop();
	a = _stack.top();
	_stack.pop();

	if (op == '+')
		r = a + b;
	else if (op == '-')
		r = a - b;
	else if (op == '*')
		r = a * b;
	else
	{
		if (b == 0)
			throw std::string("Error");
		r = a / b;
	}

	_stack.push(r);
}

/*
	Evaluate RPN expression.

	Subject constraints:
	- input is an "inverted Polish" expression as a single argument
	- operands are always < 10 => single digit
	- only operators: + - / *
	- no brackets, no decimals
*/
void	RPN::evaluate(const std::string &expr)
{
	std::istringstream	iss(expr);
	std::string			tok;

	// Reset state in case evaluate() is called multiple times.
	while (!_stack.empty())
		_stack.pop();
	_result = 0;

	while (iss >> tok)
	{
		/*
			We accept only single-character tokens:
			- digit '0'..'9'
			- operator '+', '-', '*', '/'
		*/
		if (tok.size() != 1)
			throw std::string("Error");

		if (tok[0] >= '0' && tok[0] <= '9')
			_stack.push(tok[0] - '0');
		else if (isOperator(tok[0]))
			applyOperator(tok[0]);
		else
			throw std::string("Error");
	}

	// After evaluation, exactly 1 value must remain.
	if (_stack.size() != 1)
		throw std::string("Error");

	_result = _stack.top();
}
