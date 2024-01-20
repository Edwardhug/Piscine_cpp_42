#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	private :

	int Fixed_point;
	static const int Fractional_bit = 8;

	public :

	Fixed();	//default constructor
	Fixed(const Fixed &other);	//copy constructor
	~Fixed();	// destructor
	Fixed & operator = (const Fixed &other);	//copy assignement operator
	int	getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif