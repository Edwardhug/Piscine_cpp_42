#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class	Form {
	private :

	const std::string	_name;
	bool				_signed;
	const int			_toSign;
	const int			_toExec;

	public :

	Form();
	Form(std::string name, int toSign, int toExec);
	~Form();
	Form(Form const &copy);
	Form &operator=(Form const &copy);

	std::string	getName() const;
	bool	getSigned() const;
	int		getToSign() const;
	int		getToExec() const;

	void	beSigned(Bureaucrat const bureaucrat);

	class GradeTooHighException : public std::exception {
		public :
	
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public :

		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, Form &form);

#endif