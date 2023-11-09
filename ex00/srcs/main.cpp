#include "Bureaucrat.hpp"

int main(void)
{
	{
		try {
			std::cout << BOLD << "Creating a Bureaucrat with default" << END << std::endl;
			Bureaucrat bureaucrat;
			std::cout << bureaucrat << std::endl;
			Bureaucrat bureaucrat2(bureaucrat);
			std::cout << bureaucrat2 << std::endl;
			Bureaucrat bureaucrat3(bureaucrat2);
			std::cout << bureaucrat3 << std::endl;
		} catch (std::exception &e) {
			std::cerr << RED << e.what() << END << std::endl;
		}
	}
	std::cout << "-------------------------------------------"	<< std::endl << std::endl;
	{
		try {
			std::cout << BOLD << "Creating a Bureaucrat with grade 1" << END << std::endl;
			Bureaucrat bureaucrat("Bureaucrat1", 1);
			std::cout << bureaucrat << std::endl;
			for (int i = 1; i < 200; i++)
			{
				bureaucrat.decrementGrade();
				std::cout << GREEN << "Count: " << i << " Decrementing grade" << END << std::endl;
			}
		} catch (std::exception &e) {
			std::cerr << RED << e.what() << END << std::endl;
		}
	}
	std::cout << "-------------------------------------------"	<< std::endl << std::endl;
	{
		try {
			std::cout << BOLD << "Creating a Bureaucrat with grade 150" << END << std::endl;
			Bureaucrat bureaucrat("Bureaucrat150", 150);
			std::cout << bureaucrat << std::endl;
			for (int i = 1; i < 200; i++)
			{
				bureaucrat.incrementGrade();
				std::cout << GREEN << "Count: " << i << " Incrementing grade" << END << std::endl;
			}
		} catch (std::exception &e) {
			std::cerr << RED << e.what() << END << std::endl;
		}
	}
	std::cout << "-------------------------------------------"	<< std::endl << std::endl;
	{
		try {
			std::cout << BOLD << "Creating a Bureaucrat with grade 0" << END << std::endl;
			Bureaucrat bureaucrat("Bureaucrat0", 0);
		} catch (std::exception &e) {
			std::cerr << RED << e.what() << END << std::endl;
		}
	}
	std::cout << "-------------------------------------------"	<< std::endl << std::endl;
	{
		try {
			std::cout << BOLD << "Creating a Bureaucrat with grade 151" << END << std::endl;
			Bureaucrat bureaucrat("Bureaucrat151", 151);
		} catch (std::exception &e) {
			std::cerr << RED << e.what() << END << std::endl;
		}
	}
	std::cout << "-------------------------------------------"	<< std::endl << std::endl;
}
