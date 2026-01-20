/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:35:23 by nryser            #+#    #+#             */
/*   Updated: 2026/01/20 13:00:23 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>    // NULL
#include <exception>  // std::exception

/*

	GOAL:
	- Own a dynamically allocated array of T (using new[] / delete[])
	- Support deep copy (copy constructor + copy assignment)
	- Provide bounds-checked operator[]
	- Provide size()

	WHY "RULE OF 3"?
	- If a class owns a resource (here: heap memory in _data),
	  then the default compiler-generated copy is a SHALLOW COPY.
	- Shallow copy would copy the pointer only, making 2 Arrays share the same memory.
	  That causes:
	    1) double free when both destructors delete[] the same pointer
	    2) shared state (modifying one modifies the other)
	- Therefore we must implement:
	    (1) Destructor
	    (2) Copy constructor
	    (3) Copy assignment operator
*/

template <typename T>
class Array {
private:
	/* =========================
	   INTERNAL STATE / OWNERSHIP
	   =========================
	   - _data is owned by this object (allocated with new[])
	   - _size is the number of valid elements
	   Invariant we try to keep:
	     - if _size == 0, then _data == NULL (no unnecessary allocation)
	*/
	T* _data;
	unsigned int _size;

public:
	/* =========================
	   1) CONSTRUCTORS
	   ========================= */

	// Default constructor: creates an empty Array (no allocation)
	Array() : _data(NULL), _size(0) {}

	// Size constructor: creates an Array with n elements
	// - If n == 0, do NOT allocate (keeps clean invariant and avoids new T[0])
	Array(unsigned int n) : _data(NULL), _size(n) {
		if (n > 0)
			_data = new T[n]; // default-initializes elements
	}

	/* =========================
	   2) RULE OF 3 - COPY CONSTRUCTOR
	   =========================
	   Called when creating a new object from an existing one:
	     Array<T> b(a);
	   Must do a DEEP COPY:
	     - allocate new memory
	     - copy each element
	*/
	Array(Array const& other) : _data(NULL), _size(other._size) {
		if (_size > 0)
			_data = new T[_size];
		for (unsigned int i = 0; i < _size; ++i)
			_data[i] = other._data[i];
	}

	/* =========================
	   3) RULE OF 3 - COPY ASSIGNMENT OPERATOR
	   =========================
	   Called when assigning to an existing object:
	     b = a;
	   Must do a DEEP COPY and avoid leaks:
	     - handle self-assignment (b = b)
	     - free old memory
	     - allocate new memory
	     - copy elements
	*/
	Array& operator=(Array const& other) {
		// Self-assignment check prevents deleting our own data before copying it
		if (this == &other)
			return *this;

		// Free currently owned memory
		delete[] _data;
		_data = NULL;

		// Copy size, then allocate if needed
		_size = other._size;
		if (_size > 0)
			_data = new T[_size];

		// Copy elements one by one (deep copy)
		for (unsigned int i = 0; i < _size; ++i)
			_data[i] = other._data[i];

		return *this;
	}

	/* =========================
	   4) RULE OF 3 - DESTRUCTOR
	   =========================
	   Called when the object is destroyed:
	     - releases owned memory
	   Note: delete[] NULL is safe (does nothing).
	*/
	~Array() {
		delete[] _data;
	}

	/* =========================
	   5) PUBLIC API
	   ========================= */

	// size(): must be const because it should not modify the object
	unsigned int size() const {
		return _size;
	}

	/* =========================
	   6) ELEMENT ACCESS WITH BOUNDS CHECK
	   =========================
	   operator[] must throw if index is out of bounds.
	   We provide 2 overloads:
	     - non-const: allows modification of elements
	     - const: allows reading elements from a const Array
	*/

	// Non-const operator[]: returns a modifiable reference
	T& operator[](unsigned int i) {
		if (i >= _size)
			throw std::exception();
		return _data[i];
	}

	// Const operator[]: returns a read-only reference
	T const& operator[](unsigned int i) const {
		if (i >= _size)
			throw std::exception();
		return _data[i];
	}
};

#endif
