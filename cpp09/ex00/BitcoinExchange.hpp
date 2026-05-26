#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &src);
	BitcoinExchange &operator=(BitcoinExchange const &rhs);
	~BitcoinExchange();

	void loadDatabase(std::string const &filename);
	void processInput(std::string const &filename);

private:
	std::map<std::string, float> _db;

	bool _isValidDate(std::string const &date) const;
	bool _isLeapYear(int year) const;
};

#endif
