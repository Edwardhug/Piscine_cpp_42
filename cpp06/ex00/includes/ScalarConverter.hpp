#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter {
	private :

	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(ScalarConverter const &copy);
	ScalarConverter &operator=(ScalarConverter const &copy);

	public :

	static void	convert(std::string arg);
};

#endif