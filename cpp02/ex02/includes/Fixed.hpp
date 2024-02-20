#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private :

	int Fixed_point;
	static const int Fractional_bit = 8;

	public :

	Fixed();	//default constructor
	Fixed(const int x);
	Fixed(const float x);
	Fixed(const Fixed &other);	//copy constructor
	~Fixed();	// destructor
	Fixed & operator = (const Fixed &other);	//copy assignement operator

	int	getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void)const;
	int	toInt(void)const;

	bool	operator<(Fixed const& a) const;
	bool	operator>(Fixed const& a) const;
	bool	operator<=(Fixed const& a) const;
	bool	operator>=(Fixed const& a) const;
	bool	operator==(Fixed const& a) const;
	bool	operator!=(Fixed const& a) const;

	Fixed	operator+(Fixed const& a) const;
	Fixed	operator-(Fixed const& a) const;
	Fixed	operator*(Fixed const& a) const;
	Fixed	operator/(Fixed const& a) const;

	Fixed	operator++(int a);
	Fixed	operator--(int a);
	Fixed	&operator++();
	Fixed	&operator--();

	static Fixed	&min(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static Fixed	&max(Fixed &a, Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream& operator<<(std::ostream& o, const Fixed& fixed);

#endif