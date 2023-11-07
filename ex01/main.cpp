#include "Form.hpp"
#include "Bureaucrat.hpp"


int main(void)
{
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
	std::cout << "-----------------------------------------" << std::endl;
	{
		try {

		} catch (std::exception &e) {
			std::cerr << RED << e.what() << END <<std::endl;
		}
	}
	std::cout << "-----------------------------------------" << std::endl;
	{
		try {

		} catch (std::exception &e) {
			std::cerr << RED << e.what() << END <<std::endl;
		}
	}
	std::cout << "-----------------------------------------" << std::endl;
	{
		try {

		} catch (std::exception &e) {
			std::cerr << RED << e.what() << END <<std::endl;
		}
	}
	std::cout << "-----------------------------------------" << std::endl;
	{
		try {

		} catch (std::exception &e) {
			std::cerr << RED << e.what() << END <<std::endl;
		}
	}
}
