#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

class BitcoinExchange {
private:
	std::map<int, float> _data;
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange &operator=(const BitcoinExchange &copy);
	void fill(const char *filename);
	std::map<int, float> getData() const;
};

#endif