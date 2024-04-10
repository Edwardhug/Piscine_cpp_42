#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data
{
	private	:
		unsigned long _data;

	public:
		Data();
		Data(unsigned long data);
		Data(Data const &src);
		virtual ~Data();
		Data	&operator=(Data const &rhs);
		unsigned long	getData() const;
};

#endif