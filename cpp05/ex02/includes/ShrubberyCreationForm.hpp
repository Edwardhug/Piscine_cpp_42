#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <iostream>
# include <string>


class ShrubberyCreationForm : public  AForm {
    private :

    std::string   _target;

    public :

    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(ShrubberyCreationForm const &copy);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &copy);

    void    execute(Bureaucrat const &executor)const;
};

#endif