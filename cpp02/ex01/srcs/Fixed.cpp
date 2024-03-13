#include "../includes/Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : Fixed_point(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int x) {
	Fixed_point = int(x * (1 << Fractional_bit));
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float x) {
	Fixed_point = int(roundf(x * (1 << Fractional_bit)));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	*this = other;
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
	return (((float)Fixed_point) / (1 << Fractional_bit));
}

int Fixed::toInt(void)const {
	return((int)(Fixed_point / (1 << Fractional_bit)));
}

std::ostream& operator<<(std::ostream& o, const Fixed& fixed)
{
	o << fixed.toFloat();
	return o;
}