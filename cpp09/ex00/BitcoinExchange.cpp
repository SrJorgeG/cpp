#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cmath>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) : _db(src._db) {}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	if (this != &rhs)
		_db = rhs._db;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::_isLeapYear(int year) const
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::_isValidDate(std::string const &date) const
{
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (date[i] < '0' || date[i] > '9')
			return false;
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 2009 || month < 1 || month > 12 || day < 1)
		return false;

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (_isLeapYear(year))
		daysInMonth[1] = 29;
	if (day > daysInMonth[month - 1])
		return false;

	return true;
}

void BitcoinExchange::loadDatabase(std::string const &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open database file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string date;
		std::string rateStr;
		if (!std::getline(iss, date, ','))
			continue;
		if (!std::getline(iss, rateStr))
			continue;

		float rate = std::atof(rateStr.c_str());
		_db[date] = rate;
	}
	file.close();
}

void BitcoinExchange::processInput(std::string const &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		size_t sep = line.find(" | ");
		if (sep == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, sep);
		std::string valueStr = line.substr(sep + 3);

		if (!_isValidDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		char *end;
		double value = std::strtod(valueStr.c_str(), &end);
		if (*end != '\0')
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		std::map<std::string, float>::iterator it = _db.lower_bound(date);
		if (it != _db.end() && it->first == date)
		{
			std::cout << date << " => " << value << " = " << value * it->second << std::endl;
		}
		else if (it != _db.begin())
		{
			--it;
			std::cout << date << " => " << value << " = " << value * it->second << std::endl;
		}
		else
		{
			std::cerr << "Error: bad input => " << date << std::endl;
		}
	}
	file.close();
}
