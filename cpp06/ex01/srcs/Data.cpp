#include "../includes/Data.hpp"

Data::Data() : _data(0) {
}

Data::Data(unsigned long data) : _data(data) {
}

Data::Data(Data const &src) {
	*this = src;
}

Data::~Data() {
}

Data	&Data::operator=(Data const &rhs) {
	this->_data = rhs._data;
	return *this;
}

unsigned long	Data::getData() const {
	return this->_data;
}