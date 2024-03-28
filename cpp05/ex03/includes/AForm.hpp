#ifndef AFORM_HPP
# define AFORM_HPP

class Bureaucrat;
# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class	AForm {
	private :

	const std::string	_name;
	bool				_signed;
	const int			_toSign;
	const int			_toExec;

	public :

	AForm();
	AForm(std::string name, int toSign, int toExec);
	virtual ~AForm();
	AForm(AForm const &copy);
	AForm &operator=(AForm const &copy);

	std::string	getName() const;
	bool	getSigned() const;
	int		getToSign() const;
	int		getToExec() const;

	void	beSigned(Bureaucrat const bureaucrat);
	virtual void	execute(Bureaucrat const &executor) const = 0;

	class GradeTooHighException : public std::exception {
		public :
	
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public :

		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, AForm &form);

#endif