/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:13:43 by nryser            #+#    #+#             */
/*   Updated: 2026/02/04 16:17:30 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*
	Constructor:
	- Loads the BTC database from "data.csv"
	- Expects "data.csv" to be in the current working directory
*/
BitcoinExchange::BitcoinExchange()
{
	std::ifstream	data("data.csv");
	std::string		line;

	if (!data.is_open())
		throw std::string("could not open file.");

	// Skip CSV header line (example: "date,exchange_rate")
	std::getline(data, line);

	while (std::getline(data, line))
	{
		if (line.empty())
			continue;
		fillData(line);
	}
	data.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &original)
	: btcData(original.btcData), LineData(original.LineData)
{
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange &original)
{
	if (this != &original)
	{
		btcData = original.btcData;
		LineData = original.LineData;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

const std::map<std::string, double>	&BitcoinExchange::getBtcData() const
{
	return (btcData);
}

const DataLine	&BitcoinExchange::getLineData() const
{
	return (LineData);
}

/* ************************************************************************** */
/*                               helper: trim                                */
/* ************************************************************************** */

std::string	BitcoinExchange::trim(const std::string &str)
{
	const std::string	ws = " \t";
	size_t				first;
	size_t				last;

	first = str.find_first_not_of(ws);
	if (first == std::string::npos)
		return ("");
	last = str.find_last_not_of(ws);
	return (str.substr(first, last - first + 1));
}

/* ************************************************************************** */
/*                        helper: strict double parsing                        */
/* ************************************************************************** */

/*
	Strictly parse a double:
	- Rejects strings that don't start with a valid number
	- Rejects trailing garbage (ex: "12.3abc")
	- Allows trailing whitespace and Windows '\r'
*/
bool	BitcoinExchange::parseDoubleStrict(const std::string &s, double &out)
{
	char		*end;
	const char	*cstr;

	end = 0;
	cstr = s.c_str();

	out = std::strtod(cstr, &end);
	if (end == cstr)
		return (false);

	while (*end == ' ' || *end == '\t' || *end == '\r')
		++end;

	return (*end == '\0');
}

/* ************************************************************************** */
/*                             data.csv parsing                               */
/* ************************************************************************** */

/*
	Parse one CSV line:
		YYYY-MM-DD,rate

	Stores into btcData with overwrite behavior (btcData[date] = rate)
*/
void	BitcoinExchange::fillData(const std::string &line)
{
	std::stringstream	ss(line);
	std::string			dateToken;
	std::string			valueToken;
	double				rate;

	if (!std::getline(ss, dateToken, ',') || !std::getline(ss, valueToken))
		throw std::string("wrong line configuration.");

	dateToken = trim(dateToken);
	valueToken = trim(valueToken);

	if (dateToken.empty() || valueToken.empty())
		throw std::string("wrong line configuration.");

	if (!parseDoubleStrict(valueToken, rate))
		throw std::string("wrong line configuration.");

	btcData[dateToken] = rate;
}

/* ************************************************************************** */
/*                           input file: header check                          */
/* ************************************************************************** */

void	BitcoinExchange::expectHeader(std::ifstream &file)
{
	std::string	line;

	if (!std::getline(file, line) || line != "date | value")
		throw std::string("invalid first line in data file. Expected 'date | value'.");
}

/* ************************************************************************** */
/*                         input file: line parsing                            */
/* ************************************************************************** */

/*
	Split one input line:
		"YYYY-MM-DD | value"

	Returns false if:
	- line empty
	- missing '|'
	- date or value empty after trimming
*/
bool	BitcoinExchange::splitInputLine(const std::string &line,
			std::string &dateOut, std::string &valueOut)
{
	size_t	sepPos;

	if (line.empty())
		return (false);

	sepPos = line.find('|');
	if (sepPos == std::string::npos)
		return (false);

	dateOut = trim(line.substr(0, sepPos));
	valueOut = trim(line.substr(sepPos + 1));

	if (dateOut.empty() || valueOut.empty())
		return (false);

	return (true);
}

/*
	Parse date in the strict "YYYY-MM-DD" format into integers.
	This checks:
	- length is 10
	- '-' positions are correct
	- sscanf reads 3 numbers
*/
bool	BitcoinExchange::parseDateYMD(const std::string &dateStr,
			int &y, int &m, int &d)
{
	if (dateStr.size() != 10 || dateStr[4] != '-' || dateStr[7] != '-')
		return (false);
	if (std::sscanf(dateStr.c_str(), "%d-%d-%d", &y, &m, &d) != 3)
		return (false);
	return (true);
}

/*
	Parse and validate the value constraints:
	- must be a valid number (strict parsing)
	- must be 0 <= value <= 1000

	Returns a ValueStatus instead of throwing exceptions.
*/
BitcoinExchange::ValueStatus
	BitcoinExchange::parseAndValidateValue(const std::string &valueStr, double &valueOut)
{
	if (!parseDoubleStrict(valueStr, valueOut))
		return (VS_BAD);
	if (valueOut < 0.0)
		return (VS_NEGATIVE);
	if (valueOut > 1000.0)
		return (VS_TOO_LARGE);
	return (VS_OK);
}

/* ************************************************************************** */
/*                           date validation helpers                           */
/* ************************************************************************** */

bool	BitcoinExchange::isLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

/*
	Calendar validation only.
	We do NOT hardcode a min/max year, because the evaluator's data.csv can vary.
*/
void	BitcoinExchange::checkDate(int year, int month, int day)
{

	if (year < 0)
		throw std::string("Invalid date: year out of range");
	if (month < 1 || month > 12)
		throw std::string("Invalid date: month out of range");
	if (day < 1)
		throw std::string("Invalid date: day out of range");

	int	daysInMonth[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	// daysInMonth[0] = 31;
	// daysInMonth[1] = 28;
	// daysInMonth[2] = 31;
	// daysInMonth[3] = 30;
	// daysInMonth[4] = 31;
	// daysInMonth[5] = 30;
	// daysInMonth[6] = 31;
	// daysInMonth[7] = 31;
	// daysInMonth[8] = 30;
	// daysInMonth[9] = 31;
	// daysInMonth[10] = 30;
	// daysInMonth[11] = 31;

	if (month == 2 && isLeapYear(year))
		daysInMonth[1] = 29;

	if (day > daysInMonth[month - 1])
		throw std::string("Invalid date: day exceeds days in month");
}

/* ************************************************************************** */
/*                                 output helpers                              */
/* ************************************************************************** */

void	BitcoinExchange::printBadInput(const std::string &line)
{
	// Subject format: "Error: bad input => ..."
	std::cout << "Error: bad input => " << line << std::endl;
}

/*
	Find the correct exchange rate:
	- if exact date exists -> use it
	- else use the closest LOWER date (previous entry)
	- if no lower date exists -> bad input
*/
void	BitcoinExchange::findDateAndCalculate(const std::string &rawLine)
{
	std::map<std::string, double>::iterator	it;

	if (btcData.empty())
	{
		std::cout << "Error: database is empty." << std::endl;
		return ;
	}

	it = btcData.lower_bound(LineData.date);

	// If lower_bound returns begin() and it's not exact, there is no earlier date.
	if (it == btcData.begin())
	{
		if (it->first != LineData.date)
		{
			printBadInput(rawLine);
			return ;
		}
	}
	else if (it == btcData.end())
	{
		// Date is after the last known date -> use last entry
		--it;
	}
	else if (it->first != LineData.date)
	{
		// First entry >= date is not exact -> use previous (closest lower)
		--it;
	}

	std::cout << LineData.date
		<< " => " << LineData.value
		<< " = " << (LineData.value * it->second)
		<< std::endl;
}

/* ************************************************************************** */
/*                               main file logic                               */
/* ************************************************************************** */

/*
	Read the user input file:
	- first line must be: "date | value"
	- for each line:
		- split date/value
		- validate date format + calendar
		- parse and validate value constraints
		- compute using exact or closest lower date in the DB
*/
void	BitcoinExchange::handleInputFile(const std::string &fileName)
{
	std::ifstream	file(fileName.c_str());
	std::string		line;

	if (!file.is_open())
		throw std::string("could not open file.");

	expectHeader(file);

	while (std::getline(file, line))
	{
		std::string	dateStr;
		std::string	valueStr;
		int			y;
		int			m;
		int			d;
		double		value;
		ValueStatus	st;

		if (!splitInputLine(line, dateStr, valueStr))
		{
			printBadInput(line);
			continue;
		}

		if (!parseDateYMD(dateStr, y, m, d))
		{
			printBadInput(line);
			continue;
		}

		// Calendar validation (leap years, days per month, etc.)
		try
		{
			checkDate(y, m, d);
		}
		catch (...)
		{
			printBadInput(line);
			continue;
		}

		st = parseAndValidateValue(valueStr, value);
		if (st == VS_NEGATIVE)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (st == VS_TOO_LARGE)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		if (st != VS_OK)
		{
			printBadInput(line);
			continue;
		}

		LineData.date = dateStr;
		LineData.value = value;
		findDateAndCalculate(line);
	}
}
