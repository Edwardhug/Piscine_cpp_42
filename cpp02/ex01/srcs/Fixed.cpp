#include "../includes/Fixed.hpp"
#include <iostream>

Fixed::Fixed() : Fixed_point(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int x) : Fixed_point(x) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float x) : Fixed_point(x) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : Fixed_point(other.Fixed_point) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(const Fixed &other) {
	Fixed_point = other.Fixed_point;
	std::cout << "Copy assignement operator called" << std::endl;
	return (*this);
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (Fixed_point);
}

void	Fixed::setRawBits(int const raw) {
	Fixed_point = raw;
	std::cout << "setRawBits member function called" << std::endl;
}

float Fixed::toFloat(void)const {
	return ((float)Fixed_point);
}

int Fixed::toInt(void)const {
	return((int)Fractional_bit);
}