#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <exception>
# include <iostream>

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

	std::string getName() const;
	int			getGrade() const;

	class GradeTooHighException : public std::exception {
		public :
		
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public :
	
		const char *what() const throw();
	};
};

#endif