#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(Intern const &copy)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = copy;
}

Intern &Intern::operator=(Intern const &copy)
{
	std::cout << "Intern assignment operator called" << std::endl;
	(void)copy;
	return (*this);
}

AForm *Intern::makeRobotomyRequestForm(std::string const &target) const
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidentialPardonForm(std::string const &target) const
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeShrubberyCreationForm(std::string const &target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target) const
{
	int	i;
	AForm *form = NULL;
	std::string formNames[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm *(Intern::*const formCreators[3])(std::string const &target) const = {&Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm, &Intern::makeShrubberyCreationForm};

	for (i = 0; i < 3 && !form; i++) {
		form = ((formName == formNames[i]) ? (this->*formCreators[i])(target) : NULL);
	}
	if (!form)
		std::cout << RED << "Form not found" << END << std::endl;
	else
		std::cout << GREEN <<  "Intern creates " << formName << END << std::endl;
	return (form);
}