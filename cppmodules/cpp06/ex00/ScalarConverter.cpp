/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 19/01/2026 12:14:54 by nryser            #+#    #+#             */
/*   Updated: 19/01/2026 17:31:43 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */



#include "ScalarConverter.hpp"

#include <iostream>
#include <string>
#include <cstdlib>     // strtol, strtod, strtof
#include <cerrno>      // errno
#include <climits>     // INT_MIN, INT_MAX
#include <cmath>       // isnan, isinf
#include <iomanip>     // fixed, setprecision

/*
	Anonymous namespace:
	Everything inside here is "private to this .cpp file" (internal linkage).
	Other files cannot see these helpers, which prevents name collisions and keeps API clean.
*/
namespace {

	/*--------------------------------------------------------------------------
	ASCII rules used by the subject/evaluators (common 42 convention):

	- If value is outside [0, 127] => char conversion is "impossible"
	- If value is inside [0, 127] but not printable => "Non displayable"
	- Printable ASCII range is [32, 126]
	--------------------------------------------------------------------------*/
	bool isAsciiPrintable(int v) {
		return (v >= 32 && v <= 126);
	}

	bool isAsciiRange(int v) {
		return (v >= 0 && v <= 127);
	}

	/*--------------------------------------------------------------------------
	Pseudo-literals are special floating-point values:
	- nan / nanf (Not a Number)
	- +inf / -inf and +inff / -inff (infinity)

	They must be handled explicitly because converting them to int/char is meaningless.
	--------------------------------------------------------------------------*/
	bool isPseudoLiteral(const std::string& s) {
		return (s == "nan" || s == "nanf" ||
				s == "+inf" || s == "+inff" ||
				s == "-inf" || s == "-inff");
	}

	/*
	Print the exact required outputs for pseudo-literals.
	Notice:
	- char and int are always impossible
	- float uses "nanf/+inff/-inff"
	- double uses "nan/+inf/-inf"
	*/
	void printPseudoLiteral(const std::string& s) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;

		if (s == "nan" || s == "nanf") {
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
		} else if (s == "+inf" || s == "+inff") {
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
		} else {
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		}
	}

	/* --------------------------------------------------------------------------
	Detect "single printable character literal" in the 42 common interpretation:
	Example: "a" or "*" (NOT a digit, because "7" should be treated as int).
	-------------------------------------------------------------------------- */
	bool isSingleCharLiteral(const std::string& s) {
		if (s.length() != 1)
			return false;

		// If it's a digit, interpret it as an integer literal instead.
		if (s[0] >= '0' && s[0] <= '9')
			return false;

		// Cast to unsigned char to avoid issues if char is signed on this platform.
		unsigned char uc = static_cast<unsigned char>(s[0]);
		return (uc >= 32 && uc <= 126);
	}

	/*--------------------------------------------------------------------------
	Detect integer literal:
	- Optional leading '+' or '-'
	- Remaining chars must be digits
	--------------------------------------------------------------------------*/
	bool isIntLiteral(const std::string& s) {
		if (s.empty())
			return false;

		std::size_t i = 0;

		// optional sign
		if (s[i] == '+' || s[i] == '-')
			++i;

		// string cannot be only "+" or "-"
		if (i == s.length())
			return false;

		// all remaining must be digits
		for (; i < s.length(); ++i) {
			if (s[i] < '0' || s[i] > '9')
				return false;
		}
		return true;
	}

	/*--------------------------------------------------------------------------
	Detect float literal in this simplified 42 format:
	- Must end with 'f'
	- Must contain exactly 1 '.'
	- Must contain at least 1 digit somewhere

	Examples: "0.0f", "-4.2f"
	--------------------------------------------------------------------------*/
	bool isFloatLiteral(const std::string& s) {
		// Minimal valid float like "0.0f" => 4 chars
		if (s.length() < 4)
			return false;

		if (s[s.length() - 1] != 'f')
			return false;

		std::size_t i = 0;
		if (s[i] == '+' || s[i] == '-')
			++i;

		// Need at least something before the final 'f'
		if (i >= s.length() - 1)
			return false;

		bool sawDot = false;
		bool sawDigit = false;

		// Only scan until before the last 'f'
		for (; i < s.length() - 1; ++i) {
			if (s[i] == '.') {
				if (sawDot)
					return false; // 2 dots => invalid
				sawDot = true;
			} else if (s[i] >= '0' && s[i] <= '9') {
				sawDigit = true;
			} else {
				return false; // invalid character
			}
		}
		return (sawDot && sawDigit);
	}

	/*--------------------------------------------------------------------------
	Detect double literal in this simplified 42 format:
	- Must contain exactly 1 '.'
	- Must contain at least 1 digit somewhere
	- No trailing 'f'

	Examples: "0.0", "-4.2"
	--------------------------------------------------------------------------*/
	bool isDoubleLiteral(const std::string& s) {
		// Minimal valid double like "0.0" => 3 chars
		if (s.length() < 3)
			return false;

		std::size_t i = 0;
		if (s[i] == '+' || s[i] == '-')
			++i;

		if (i >= s.length())
			return false;

		bool sawDot = false;
		bool sawDigit = false;

		for (; i < s.length(); ++i) {
			if (s[i] == '.') {
				if (sawDot)
					return false;
				sawDot = true;
			} else if (s[i] >= '0' && s[i] <= '9') {
				sawDigit = true;
			} else {
				return false;
			}
		}
		return (sawDot && sawDigit);
	}

	/*--------------------------------------------------------------------------
	Print float/double like subject examples:
	- If nan/inf => print pseudo form
	- Else print fixed with 1 decimal
	- For float add trailing 'f'

	Important: std::fixed and setprecision "stick" to the stream, so we reset them.
	--------------------------------------------------------------------------*/
	void printFloatDouble(double d, bool isFloat) {
		if (std::isnan(d)) {
			std::cout << (isFloat ? "nanf" : "nan");
			return;
		}
		if (std::isinf(d)) {
			if (d < 0)
				std::cout << (isFloat ? "-inff" : "-inf");
			else
				std::cout << (isFloat ? "+inff" : "+inf");
			return;
		}

		// finite numbers: always show 1 decimal
		std::cout << std::fixed << std::setprecision(1) << d;
		if (isFloat)
			std::cout << 'f';

		// reset stream formatting for safety (so later prints are not affected)
		std::cout.unsetf(std::ios::floatfield);
		std::cout << std::setprecision(6);
	}

} // end anonymous namespace

// ======================================================================================
// ScalarConverter Orthodox Canonical Form (even if not strictly needed, 42 expects it)
// ======================================================================================

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& original) { (void)original; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& original) { (void)original; return *this; }
ScalarConverter::~ScalarConverter() {}

// ======================================================================================
// Conversions from a detected source type
// ======================================================================================

void ScalarConverter::convertFromChar(const std::string& str) {
	// Detected "value" is str[0]
	const char c = str[0];

	// Convert char to int explicitly
	const int i = static_cast<int>(c);

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << i << std::endl;

	// For float/double we print with subject formatting
	std::cout << "float: ";
	printFloatDouble(static_cast<double>(i), true);
	std::cout << std::endl;

	std::cout << "double: ";
	printFloatDouble(static_cast<double>(i), false);
	std::cout << std::endl;
}

void ScalarConverter::convertFromInt(const std::string& str) {
	// Parse as long first to detect overflow before casting to int.
	// strtol sets errno on overflow/underflow.
	errno = 0;
	char* endPtr = 0;
	const long l = std::strtol(str.c_str(), &endPtr, 10);


	/* If overflow/underflow happened, the integer literal is invalid.
	If the literal is classified as an integer and integer parsing overflows,
	the conversion is impossible, as required by the subject.*/
	if (errno == ERANGE) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	// ---------------- CHAR ----------------
	// char rules follow ASCII convention: only [0,127] and printable or not.
	if (!isAsciiRange(static_cast<int>(l))) {
		std::cout << "char: impossible" << std::endl;
	} else if (!isAsciiPrintable(static_cast<int>(l))) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << static_cast<char>(l) << "'" << std::endl;
	}

	// ---------------- INT ----------------
	// int conversion is impossible if out of int range or errno indicates overflow.
	if (l > INT_MAX || l < INT_MIN) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(l) << std::endl;
	}

	// ---------------- FLOAT / DOUBLE ----------------
	// For finite integer inputs, float/double are always representable here.
	std::cout << "float: ";
	printFloatDouble(static_cast<double>(l), true);
	std::cout << std::endl;

	std::cout << "double: ";
	printFloatDouble(static_cast<double>(l), false);
	std::cout << std::endl;
}

void ScalarConverter::convertFromFloat(const std::string& str) {
	// Convert string to float (C++98 uses strtof from C99).
	errno = 0;
	char* endPtr = 0;
	const float f = std::strtof(str.c_str(), &endPtr);

	// Convert float to double for unified checks/printing.
	const double d = static_cast<double>(f);

	// ---------------- CHAR ----------------
	// Cannot convert NaN/Inf to char, and must be in ASCII range.
	if (errno != 0 || std::isnan(d) || std::isinf(d) || !isAsciiRange(static_cast<int>(d))) {
		std::cout << "char: impossible" << std::endl;
	} else if (!isAsciiPrintable(static_cast<int>(d))) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	}

	// ---------------- INT ----------------
	// Cannot convert NaN/Inf to int, and must be inside int bounds.
	if (errno != 0 || std::isnan(d) || std::isinf(d) || d > INT_MAX || d < INT_MIN) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	}

	// ---------------- FLOAT / DOUBLE ----------------
	std::cout << "float: ";
	printFloatDouble(d, true);
	std::cout << std::endl;

	std::cout << "double: ";
	printFloatDouble(d, false);
	std::cout << std::endl;
}

void ScalarConverter::convertFromDouble(const std::string& str) {
	errno = 0;
	char* endPtr = 0;
	const double d = std::strtod(str.c_str(), &endPtr);

	// ---------------- CHAR ----------------
	if (errno != 0 || std::isnan(d) || std::isinf(d) ||
		!isAsciiRange(static_cast<int>(d))) {
		std::cout << "char: impossible" << std::endl;
	} else if (!isAsciiPrintable(static_cast<int>(d))) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	}

	// ---------------- INT ----------------
	if (errno != 0 || std::isnan(d) || std::isinf(d) ||
		d > INT_MAX || d < INT_MIN) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	}

	// ---------------- FLOAT / DOUBLE ----------------
	std::cout << "float: ";
	printFloatDouble(d, true);
	std::cout << std::endl;

	std::cout << "double: ";
	printFloatDouble(d, false);
	std::cout << std::endl;
}

// ======================================================================================
// The main entry point: detect the literal type, then dispatch to the correct converter.
// ======================================================================================
void ScalarConverter::convert(const std::string& str) {
	// 1) Pseudo-literals first because they don’t behave like normal numbers.
	if (isPseudoLiteral(str)) {
		printPseudoLiteral(str);
		return;
	}

	// 2) Detect actual category and delegate.
	if (isSingleCharLiteral(str)) {
		convertFromChar(str);
	} else if (isIntLiteral(str)) {
		convertFromInt(str);
	} else if (isFloatLiteral(str)) {
		convertFromFloat(str);
	} else if (isDoubleLiteral(str)) {
		convertFromDouble(str);
	} else {
		std::cerr << "Error: Invalid literal." << std::endl;
	}
}
