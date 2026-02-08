/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 17:13:41 by nryser            #+#    #+#             */
/*   Updated: 2026/02/08 17:13:49 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>
# include <list>
# include <sstream>

class	RPN
{
	private:
		/*
			Use a stack to evaluate Reverse Polish Notation:
			- push numbers
			- when an operator appears, pop 2 operands, apply, push result
		*/
		std::stack<int, std::list<int> >	_stack;
		int									_result;

		// Check if c is one of the allowed operators: + - * /
		bool	isOperator(char c) const;

		// Apply operator on the top 2 values of the stack (throws on error)
		void	applyOperator(char op);

	public:
		RPN();
		RPN(const RPN &other);
		RPN	&operator=(const RPN &other);
		~RPN();

		/*
			Evaluate the expression:
			- tokens must be space-separated
			- numbers are single-digit (0..9) as per subject
			- operators: + - * /
		*/
		void	evaluate(const std::string &expr);

		int		getResult() const;
};

#endif
