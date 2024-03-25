#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class Bureaucrat {
	private :

	std::string const	_name;
	int					_grade;

	public :

	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(Bureaucrat const &copy);
	Bureaucrat &operator=(Bureaucrat const &copy);

	std::string getName();
	int			getName();

	// GradeTooHighException();
	// GradeTooLowException();
};

#endif