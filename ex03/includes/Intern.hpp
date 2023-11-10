#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "Bureaucrat.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(Intern const &copy);
		Intern &operator=(Intern const &copy);

		AForm *makeForm(std::string const &formName, std::string const &target) const;
		AForm *makeRobotomyRequestForm(std::string const &target) const;
		AForm *makePresidentialPardonForm(std::string const &target) const;
		AForm *makeShrubberyCreationForm(std::string const &target) const;
};


#endif