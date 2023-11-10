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

const char *Intern::FormNotFoundException::what() const throw()
{
	return ("Form not found");
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target) const
{
	int	i;
	AForm *form = NULL;
	std::string formNames[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	for (i = 0; i < 3 && formName != formNames[i]; i++)
		;

	try {
		switch (i) {
			case 0:
				form = new PresidentialPardonForm(target);
				std::cout << GREEN << "Intern creates " << formName << " form" << END << std::endl;
				break;
			case 1:
				form = new RobotomyRequestForm(target);
				std::cout << GREEN << "Intern creates " << formName << " form" << END << std::endl;
				break;
			case 2:
				form = new ShrubberyCreationForm(target);
				std::cout << GREEN << "Intern creates " << formName << " form" << END << std::endl;
				break;
			default:
				throw Intern::FormNotFoundException();

		}
	} catch (const std::bad_alloc &e) {
		std::cerr << RED << e.what() << END <<std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << END <<std::endl;
	}
	return (form);
}