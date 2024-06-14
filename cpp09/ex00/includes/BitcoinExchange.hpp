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
	void getPrice(const char *date) const;
	void	printPrice(int year, int month, int day, float price) const;
	bool	lineIsValid(std::string line) const;
};

#endif