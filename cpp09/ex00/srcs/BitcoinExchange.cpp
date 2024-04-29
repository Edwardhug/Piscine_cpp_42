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
	while (str[i] && str[i] != '.') {
		result = result * 10 + str[i] - '0';
		i++;
	}
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