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

		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};


#endif