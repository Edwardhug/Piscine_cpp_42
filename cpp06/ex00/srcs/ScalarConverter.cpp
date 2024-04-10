#include "../includes/ScalarConverter.hpp"
#include <iostream>
#include <climits>
#include <stdlib.h>

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

double	ft_atod(std::string arg)
{
	double		i;
	double		a;
	double		r;
	int			j;

	i = 0;
	j = 0;
	a = 1;
	r = 0;
	if (arg[j] == '-' || arg[j] == '+')
	{	
		if (arg[j] == '-')
			a = a * (-1);
		j++;
	}
	while (arg[j] >= '0' && arg[j] <= '9')
	{
		r = (arg[j] - '0') + r * 10;
		j++;
	}
	if (arg[j] == '.')
		j++;
	while (arg[j] >= '0' && arg[j] <= '9')
	{
		r = (arg[j] - '0') + r * 10;
		j++;
		i++;
	}
	r = r * a;
	while (i > 0)
	{
		r = r / 10;
		i--;
	}
	return (r);
}

bool	is_char(std::string arg)
{
	if (arg.length() != 1)
		return false;
	return (true);
}

bool is_int(std::string arg)
{
	long	copy;
	char	*end;

	copy = strtol(arg.c_str(), &end, 10);
	if (end == arg.c_str() || *end != 0 || copy > INT_MAX || copy < INT_MIN)
		return false;
	return (true);
}

bool is_float(std::string arg)
{
	float	copy;
	char	*end;

	copy = strtof(arg.c_str(), &end);
	(void)copy;
	if (end == arg.c_str() || *end != 0 || arg.find('.') == std::string::npos)
		return false;
	return true;
}

bool is_double(std::string arg)
{
	double	copy;
	char	*end;

	copy = strtod(arg.c_str(), &end);
	(void)copy;
	if (end == arg.c_str() || *end != 0)
		return false;
	return true;
}

void	print_int(std::string arg)
{
	std::cout << "char: ";
	if ( ft_atoi(arg.c_str()) < 32 || ft_atoi(arg.c_str()) > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(ft_atoi(arg.c_str())) << "'" << std::endl;
	std::cout << "int: " << ft_atoi(arg.c_str()) << std::endl;
	std::cout << "float: " << static_cast<float>(ft_atod(arg.c_str())) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(ft_atod(arg.c_str())) << std::endl;
	return ;
}

void	print_char(std::string arg)
{
	std::cout << "char: ";
	std::cout << "'" << arg[0] << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(arg[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(arg[0]) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(arg[0]) << ".0" <<std::endl;
	return ;
}

void	print_double(std::string arg)
{
	std::cout << "char: ";
	if (ft_atoi(arg.c_str()) < 32 || ft_atoi(arg.c_str()) > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(ft_atoi(arg.c_str())) << "'" << std::endl;
	std::cout << "int: " << ft_atoi(arg.c_str()) << std::endl;
	std::cout << "float: " << static_cast<float>(ft_atod(arg.c_str())) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(ft_atod(arg.c_str())) << std::endl;
	return ;
}

void	print_float(std::string arg)
{
	std::cout << "char: ";
	if (ft_atoi(arg.c_str()) < 32 || ft_atoi(arg.c_str()) > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(ft_atoi(arg.c_str())) << "'" << std::endl;
	std::cout << "int: " << ft_atoi(arg.c_str()) << std::endl;
	std::cout << "float: " << static_cast<float>(ft_atod(arg.c_str())) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(ft_atod(arg.c_str())) << std::endl;
	return ;
}

bool	check_execeptions(std::string arg)
{
	if (arg == "nan" || arg == "-inf" || arg == "+inf" || arg == "inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << arg << "f" << std::endl;
		std::cout << "double: " << arg << std::endl;
		return true;
	}
	else if (arg == "-inff" || arg == "+inff" || arg == "inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << arg << std::endl;
		std::cout << "double: " << arg << std::endl;
		return true;
	}
	return false;
}

void	ScalarConverter::convert(std::string arg) {
	if (check_execeptions(arg))
		return ;
	else if (is_int(arg))
		print_int(arg);
	else if (is_char(arg))
		print_char(arg);
	else if (is_double(arg))
		print_double(arg);
	else if (is_float(arg))
		print_float(arg);
	else
	{
		std::cout << "Error: can't find type" << std::endl;
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
}