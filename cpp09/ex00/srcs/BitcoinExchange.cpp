#include "../includes/BitcoinExchange.hpp"
#include <fstream>
#include <iostream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy) {
	*this = copy;
	return *this;
}

int	stoi(const std::string &str) {
	int result = 0;
	for (size_t i = 0; i < str.size(); i++) {
		result = result * 10 + str[i] - '0';
	}
	return result;
}

float	stof(const std::string &str) {
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
		year = stoi(line.substr(0, 4));
		month = stoi(line.substr(5, 2));
		day = stoi(line.substr(8, 2));
		price = stof(line.substr(11));
		timestamp = year * 10000 + month * 100 + day;
		_data[timestamp] = price;
	}
	file.close();
}

std::map<int, float> BitcoinExchange::getData() const {
	return _data;
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
		int year = stoi(line.substr(0, 4));
		int month = stoi(line.substr(5, 2));
		int day = stoi(line.substr(8, 2));
		float number = stof(line.substr(13));
		if (checkDate(year, month, day) == false) {
			std::cerr << "Error: invalid date " << year << "-" << month << "-" << day << std::endl;
		}
		else {
			int timestamp = year * 10000 + month * 100 + day;
			if (this->getData()[timestamp] != 0) {
				std::cout << year << "-" << month << "-" << day << "=> " << this->getData()[timestamp] * number << std::endl;
			}
			else {
				std::map<int, float>::const_iterator it = this->getData().lower_bound(timestamp);
				if (it == this->getData().begin()) {
					std::cerr << "Error: no data available" << std::endl;
				}
				else {
					it--;
					std::cout << year << "-" << month << "-" << day << "=> " << it->second * number << std::endl;
				}
			}
		}
		}
	}
}