#include "../includes/ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &copy) {(void)copy;}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &copy) {
	(void)copy;
	return (*this);
}

int	ft_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

int	ft_atoi(const char *s)
{
	int		i;
	int		a;
	int		r;

	i = ft_whitespace((char *)s);
	a = 1;
	r = 0;
	if (s[i] == '-' || s[i] == '+')
	{	
		if (s[i] == '-')
			a = a * (-1);
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		r = (s[i] - '0') + r * 10;
		i++;
	}
	r = r * a;
	return (r);
}

void	print_char(std::string arg) {
	std::cout << "char: " << char(ft_atoi(arg.c_str())) << std::endl;
}

void	print_int(std::string arg) {
	std::cout << "int: " << ft_atoi(arg.c_str()) << std::endl;
}

void	print_float(std::string arg) {
	float	f = static_cast<float>(ft_atoi(arg.c_str()));
	std::cout << "float: " << f << std::endl;
}

void	print_double(std::string arg) {
	double	f = static_cast<double>(ft_atoi(arg.c_str()));
	std::cout << "double: " << f << std::endl;
}

void	ScalarConverter::convert(std::string arg) {
	print_char(arg);
	print_int(arg);
	print_float(arg);
	print_double(arg);
}