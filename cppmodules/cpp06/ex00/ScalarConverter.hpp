/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 19/01/2026 12:14:54 by nryser            #+#    #+#             */
/*   Updated: 19/01/2026 17:31:51 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>


class ScalarConverter {
	public:
		static void convert(const std::string& str);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& original);
		ScalarConverter& operator=(const ScalarConverter& original);
		~ScalarConverter();

		// Convert from a known detected type.
		static void convertFromChar(const std::string& str);
		static void convertFromInt(const std::string& str);
		static void convertFromFloat(const std::string& str);
		static void convertFromDouble(const std::string& str);
};

#endif
