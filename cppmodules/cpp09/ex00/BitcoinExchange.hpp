/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:12:29 by nryser            #+#    #+#             */
/*   Updated: 2026/02/04 16:12:29 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <cstdlib>	// strtod
# include <cstdio>	// sscanf

/*
	Represents 1 parsed input line:
		YYYY-MM-DD | value
*/
struct	DataLine
{
	double		value;
	std::string	date;
};

class	BitcoinExchange
{
	private:
		/*
			Value parsing/validation status.
			We use this to avoid throwing exceptions for normal input mistakes.
		*/
		enum ValueStatus
		{
			VS_OK,
			VS_BAD,
			VS_NEGATIVE,
			VS_TOO_LARGE
		};

		/*
			Database: date -> exchange rate
			std::map keeps keys sorted, enabling efficient lower_bound() lookups.
		*/
		std::map<std::string, double>	btcData;

		/*
			Stores the currently processed input line (date/value),
			used by findDateAndCalculate().
		*/
		DataLine							LineData;

	private:
		/* ---------- data.csv loading ---------- */

		// Parse 1 CSV line: "YYYY-MM-DD,rate" and store into btcData
		void			fillData(const std::string &line);

		/* ---------- parsing helpers ---------- */

		// Trim leading/trailing spaces and tabs
		std::string		trim(const std::string &str);

		// Split "date | value" into two trimmed strings (returns false if malformed)
		bool			splitInputLine(const std::string &line,
							std::string &dateOut, std::string &valueOut);

		// Parse "YYYY-MM-DD" into integers, checks format and sscanf success
		bool			parseDateYMD(const std::string &dateStr,
							int &y, int &m, int &d);

		// Strict numeric parsing (rejects trailing garbage)
		bool			parseDoubleStrict(const std::string &s, double &out);

		// Parse + validate 0..1000 constraints (no exceptions here)
		ValueStatus		parseAndValidateValue(const std::string &valueStr,
							double &valueOut);

		/* ---------- validation ---------- */

		// Validates calendar correctness (month/day ranges + leap years)
		void			checkDate(int year, int month, int day);
		bool			isLeapYear(int year);

		/* ---------- output / processing ---------- */

		// Print subject-style "bad input" error (prints the raw line)
		void			printBadInput(const std::string &line);

		// Find exact or closest lower date and print final computation
		void			findDateAndCalculate(const std::string &rawLine);

		// Validate the first line in the input file: "date | value"
		void			expectHeader(std::ifstream &file);

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &original);
		BitcoinExchange&	operator=(const BitcoinExchange &original);
		~BitcoinExchange();

		const std::map<std::string, double>	&getBtcData() const;
		const DataLine						&getLineData() const;

		// Read input file, validate each line, compute and print results
		void			handleInputFile(const std::string &fileName);
};

#endif
