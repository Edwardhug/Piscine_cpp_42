#include "../includes/BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy) {
	this->_data = copy._data;
	return *this;
}

//	UTILS

int	ft_stoi(const std::string &str) {
	int result = 0;
	for (size_t i = 0; i < str.size(); i++) {
		result = result * 10 + str[i] - '0';
	}
	return result;
}

float	ft_stof(const std::string &str) {
	float result = 0;
	int i = 0;
	while (str[i] && str[i] != '\n' && str[i] != '.') {
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (!str[i] || str[i] == '\n')
		return result;
	i++;
	float decimal = 0.1;
	while (str[i]) {
		result += (str[i] - '0') * decimal;
		decimal /= 10;
		i++;
	}
	return result;
}


bool checkDate(int year, int month, int day) {
	if (year < 2009 || year > 2024) {
		return false;
	}
	if (month < 1 || month > 12) {
		return false;
	}
	if (day < 1 || day > 31) {
		return false;
	}
	if (month == 2 && day > 29) {
		return false;
	}
	if (month == 2 && year % 4 != 0 && day > 28)
		return false;
	return true;
}

bool isDigit(std::string num) {
	for (int i = 0; num[i]; i++) {
		if (num[i] < '0' || num[i] > '9')
			return false;
	}
	return (true);
}

// METHODES

void BitcoinExchange::fill(const char *filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error: could not open file" << std::endl;
		return;
	}
	int year, month, day;
	int timestamp;
	float price;
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		year = ft_stoi(line.substr(0, 4));
		month = ft_stoi(line.substr(5, 2));
		day = ft_stoi(line.substr(8, 2));
		price = ft_stof(line.substr(11));
		timestamp = year * 10000 + month * 100 + day;
		_data[timestamp] = price;
	}
	file.close();
}

const std::map<int, float> &BitcoinExchange::getData() const {
	return _data;
}

void	BitcoinExchange::printPrice(int year, int month, int day, float price) const {
	std::cout << year << "-";
	if (month < 10)
		std::cout << "0" << month << "-";
	else
		std::cout << month << "-";
	if (day < 10)
		std::cout << "0" << day << "=> ";
	else
		std::cout << day << "=> ";
	std::cout << price << std::endl;
	
}

bool	BitcoinExchange::lineIsValid(std::string line) const {
	if (line.size() < 14) {
		return (false);
	}
	if (isDigit(line.substr(0, 4)) == false || isDigit(line.substr(5, 2)) == false || isDigit(line.substr(8, 2)) == false) {
		return (false);
	}
	if (line[4] != '-' || line[7] != '-' || line[10] != ' ' || line[11] != '|' || line[12] != ' ')
		return (false);
	std::string lastNum = line.substr(13);
	if (isDigit(lastNum) == false)
		return (false);
	return true;
}

void BitcoinExchange::getPrice(const char *date) const {
    std::ifstream file(date);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file" << std::endl;
        return;
    }

    const std::map<int, float>& dataMap = this->getData();
    std::string line;
    std::getline(file, line);
	if (line != "date | value") {
		std::cerr << "Error: First line must be \"date | value\"" << std::endl;
		file.close();
		return ;
	}

    while (std::getline(file, line)) {
        if (!lineIsValid(line)) {
            std::cerr << "Error: invalid format" << std::endl;
            continue;
        }

        int year = ft_stoi(line.substr(0, 4));
        int month = ft_stoi(line.substr(5, 2));
        int day = ft_stoi(line.substr(8, 2));
        float number = ft_stof(line.substr(13));

        if (number < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        } else if (number > 1000) {
            std::cerr << "Error: too large number." << std::endl;
            continue;
        }

        if (!checkDate(year, month, day)) {
            std::cerr << "Error: invalid date " << year << "-" << month << "-" << day << std::endl;
            continue;
        }

        int timestamp = year * 10000 + month * 100 + day;

        std::map<int, float>::const_iterator it = dataMap.upper_bound(timestamp);
        if (it != dataMap.begin()) {
            --it;
        } else {
            std::cerr << "Error: no valid date found before " << line.substr(0, 10) << std::endl;
            continue;
        }

        printPrice(year, month, day, it->second * number);
    }

    file.close();
}