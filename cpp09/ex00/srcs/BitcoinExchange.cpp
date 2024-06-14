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

// char	*ft_itoa(const int num) {
// 	std::cout << "num = " << num << std::endl;
// 	char ret[100];

// 	int i = 0;
// 	int	size = 0;
// 	while (num / (size * 10) > 0){
// 		size++;
// 	}
// 	while (i > size) {
// 		ret[i] = (num / (size - 1)) + '0';
// 		i++;
// 	}
// 	ret[i] = 0;
// 	std::cout << "ret = " << ret << std::endl;
// 	return ret;
// }

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
	return true;
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
		if (timestamp == 20110110)
			std::cout << "PRICE =" << price << std::endl;
		_data[timestamp] = price;
	}
	file.close();
}

std::map<int, float> BitcoinExchange::getData() const {
	return _data;
}


void BitcoinExchange::getPrice(const char *date) const {
	std::ifstream file(date);
	if (!file.is_open()) {
		std::cerr << "Error: could not open file" << std::endl;
		return;
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		if (line.size() < 14) {
			std::cerr << "Error: invalid format" << std::endl;
		}
		else {
			int year = ft_stoi(line.substr(0, 4));
			int month = ft_stoi(line.substr(5, 2));
			int day = ft_stoi(line.substr(8, 2));
			float number = ft_stof(line.substr(13));
			if (number < 0)
				std::cerr << "Error: not a positive number." << std::endl;
			else if (checkDate(year, month, day) == false) {
				std::cerr << "Error: invalid date " << year << "-" << month << "-" << day << std::endl;
			}
			else {
				int timestamp = year * 10000 + month * 100 + day;
				if (this->getData()[timestamp] != 0) {
					std::cout << year << "-" << month << "-" << day << "=> " << this->getData()[timestamp] * number << std::endl;
				}
				else {
					std::map<int, float>::const_iterator it;
					while (this->getData()[timestamp] == 0)
						timestamp--;
					it = this->getData().find(timestamp);
					// it++;
					// std::cout << "PASS ="  << it->second << std::endl;
					std::cout << year << "-" << month << "-" << day << "=> " << it->second * number << std::endl;
				}
			}
		}
	}
	file.close();
}