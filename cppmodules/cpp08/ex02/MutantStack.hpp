/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:50:03 by nryser            #+#    #+#             */
/*   Updated: 2026/01/21 13:50:03 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>   // std::stack (container adaptor)

/*
	Goal:
	- std::stack is not iterable by design (it only exposes push/pop/top).
	- But std::stack stores its elements in an underlying container named `c`
	  (a protected member), which *is* iterable (std::deque<T> by default).
	- By inheriting from std::stack, I can legally access `c` and expose iterators.

	Key points:
	- I do NOT reimplement a stack. just reuse std::stack entirely.
	- I only add iterator access (begin/end and optionally reverse iterators).
	- This preserves full stack behavior while enabling iteration.
*/

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	/* ================= Iterator type aliases =================

		std::stack<T> defines:
			typedef Container container_type;

		`container_type` is the underlying container type alias used by the stack.
		I reuse its iterator types, so the iterators are exactly the same
		as the underlying container's iterators.
	*/

	typedef typename std::stack<T>::container_type::iterator				iterator;
	typedef typename std::stack<T>::container_type::const_iterator		const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

	/* ================= Orthodox Canonical Form =================	*/

	MutantStack() : std::stack<T>() {}

	MutantStack(const MutantStack& other) : std::stack<T>(other) {}

	MutantStack& operator=(const MutantStack& other)
	{
		if (this != &other)
			std::stack<T>::operator=(other);
		return *this;
	}

	/*
		Destructor:
		- Virtual is not required for this subject because I do not use
		  polymorphic deletion (deleting via std::stack<T>*).
		- So I keep it non-virtual .
	*/
	~MutantStack() {}

	/* ================= Iterator access =================

		I forward begin/end to the underlying container `c`.

		Important:
		- `c` is a protected member of std::stack, so only derived classes can access it.
		- I use `this->c` because in templates, names from dependent base classes
		  require `this->` for correct lookup.
	*/

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }

	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }

	/* ================= Reverse iterator access  ================= */

	reverse_iterator rbegin() { return this->c.rbegin(); }
	reverse_iterator rend() { return this->c.rend(); }

	const_reverse_iterator rbegin() const { return this->c.rbegin(); }
	const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif
