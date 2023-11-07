#include "Form.hpp"
#include "Bureaucrat.hpp"


int main(void)
{
	std::cout << "----------------------------------------------------------------------------------" << std::endl;
	{
		try {
			std::cout << BOLD << "Creating a Form with default" << END << std::endl;
			Form form;
			std::cout << form << std::endl;
			Form form2(form);
			std::cout << form2 << std::endl;
			Form form3;
			form3 = form2;
			std::cout << form3 << std::endl;
		} catch (std::exception &e) {
			std::cerr << RED << e.what() << END <<std::endl;
		}
	}
	std::cout << "----------------------------------------------------------------------------------" << std::endl;
	{
		try {
			std::cout << BOLD << "Grade equal" << END << std::endl;
			Form form("form", 1, 1);
			std::cout << form << std::endl;
			Bureaucrat bureaucrat("bureaucrat", 1);
			std::cout << bureaucrat << std::endl;
			bureaucrat.signForm(form);
			std::cout << form << std::endl;
		}  catch (std::exception &e) {
			std::cerr << RED << e.what() << END <<std::endl;
		}
	}
	std::cout << "----------------------------------------------------------------------------------" << std::endl;
	{
		try {
			std::cout << BOLD << "Grade too low" << END << std::endl;
			Form form("form", 1, 1);
			std::cout << form << std::endl;
			Bureaucrat bureaucrat("bureaucrat", 2);
			std::cout << bureaucrat << std::endl;
			bureaucrat.signForm(form);
			std::cout << form << std::endl;
		} catch (std::exception &e) {
			std::cerr << RED << e.what() << END <<std::endl;
		}
	}
	std::cout << "----------------------------------------------------------------------------------" << std::endl;
	{
		try {
			std::cout << BOLD << "Grade too low" << END << std::endl;
			Form form("form", 150, 150);
			std::cout << form << std::endl;
			Bureaucrat bureaucrat("bureaucrat", 2);
			std::cout << bureaucrat << std::endl;
			bureaucrat.signForm(form);
			std::cout << form << std::endl;
		} catch (std::exception &e) {
			std::cerr << RED << e.what() << END <<std::endl;
		}
	}
}
