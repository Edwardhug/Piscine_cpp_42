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
};

std::ostream& operator<<(std::ostream& o, const Fixed& fixed);

#endif