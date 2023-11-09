#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
		std::cout << "----------------------------------------------------------------------------------" << std::endl;
	{
		try {
			

		} catch (std::exception &e) {
			std::cerr << RED << e.what() << END <<std::endl;
		}
	}
	std::cout << "----------------------------------------------------------------------------------" << std::endl;
	{
		try {

		}  catch (std::exception &e) {
			std::cerr << RED << e.what() << END <<std::endl;
		}
	}
	std::cout << "----------------------------------------------------------------------------------" << std::endl;
	{
		try {

		} catch (std::exception &e) {
			std::cerr << RED << e.what() << END <<std::endl;
		}
	}
	std::cout << "----------------------------------------------------------------------------------" << std::endl;
	{
		try {
			std::cout << BOLD << "Grade too low" << END << std::endl;

		} catch (std::exception &e) {
			std::cerr << RED << e.what() << END <<std::endl;
		}
	}
}