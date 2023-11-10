#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <chrono>
#include <thread>

int main(void)
{
	std::cout << "----------------------------------------------------------------------------------" << std::endl;
	{
		Intern	someRandomIntern;
		AForm	*form;
		form = someRandomIntern.makeForm("robotomy request", "Bender");
		if (form)
		{
			std::cout << *form << std::endl;
			delete form;
		}
	}
	std::cout << "----------------------------------------------------------------------------------" << std::endl;
	{
		Intern someRandomIntern;
		AForm *form;
		form = someRandomIntern.makeForm("presidential pardon", "Bender");
		if (form)
		{
			std::cout << *form << std::endl;
			delete form;
		}
	}
	std::cout << "----------------------------------------------------------------------------------" << std::endl;
	{
		Intern someRandomIntern;
		AForm *form;
		form = someRandomIntern.makeForm("shrubbery creation", "Bender");
		if (form)
		{
			std::cout << *form << std::endl;
			form->beSigned(Bureaucrat("bureaucrat", 1));
			delete form;
		}
	}
	std::cout << "----------------------------------------------------------------------------------" << std::endl;
	{
		Intern someRandomIntern;
		AForm *form;
		form = someRandomIntern.makeForm("shrubbery", "Bender");
		if (form)
		{
			std::cout << *form << std::endl;
			delete form;
		}
	}
}