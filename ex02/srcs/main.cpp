#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <chrono>
#include <thread>

int main(void)
{
		std::cout << "----------------------------------------------------------------------------------" << std::endl;
	{
		try {
			std::cout << BOLD << "----- PresidentialPardonForm : 25 grade to sign : 5 grade to execute ----" << END << std::endl;
			std::cout << BOLD << std::endl <<  "----- PresidentialPardonForm Sign OK & Execute OK ----" << END << std::endl;
			Bureaucrat bureaucrat("bureaucrat", 1);
			std::cout << bureaucrat << std::endl;
			PresidentialPardonForm form("president");
			bureaucrat.signForm(form);
			std::cout << form << std::endl;
			bureaucrat.executeForm(form);
			std::cout << BOLD << std::endl << "----  PresidentialPardonForm Sign NG ----" << END << std::endl;
			Bureaucrat bureaucrat2("bureaucrat2", 26);
			std::cout << bureaucrat2 << std::endl;
			PresidentialPardonForm form2("president2");
			bureaucrat2.signForm(form2);
		} catch (std::exception &e) {
			std::cerr << RED << e.what() << END <<std::endl;
		}
		try {
			std::cout << BOLD << std::endl << "----- PresidentialPardonForm Sign OK & Execute NG----" << END << std::endl;
			Bureaucrat bureaucrat3("bureaucrat", 6);
			std::cout << bureaucrat3 << std::endl;
			PresidentialPardonForm form3("president3");
			bureaucrat3.signForm(form3);
			std::cout << form3 << std::endl;
			bureaucrat3.executeForm(form3);
		} catch (std::exception &e) {
			std::cerr << RED << e.what() << END <<std::endl;
		}
	}
	std::cout << "----------------------------------------------------------------------------------" << std::endl;
	{
		try {
			std::cout << BOLD << "----- RobotomyRequestForm : 72 grade to sign : 45 grade to execute ----" << END << std::endl;
			std::cout << BOLD << std::endl << "----- RobotomyRequestForm Sign OK & Execute OK ----" << END << std::endl;
			Bureaucrat bureaucrat("bureaucrat", 1);
			std::cout << bureaucrat << std::endl;
			RobotomyRequestForm form("robot");
			bureaucrat.signForm(form);
			std::cout << form << std::endl;
			for (int i = 0; i < 10; i++) {
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
				bureaucrat.executeForm(form);
			}
			std::cout << BOLD << std::endl <<  "----  RobotomyRequestForm Sign NG ----" << END << std::endl;
			Bureaucrat bureaucrat2("bureaucrat2", 73);
			std::cout << bureaucrat2 << std::endl;
			RobotomyRequestForm form2("robot2");
			bureaucrat2.signForm(form2);
		}  catch (std::exception &e) {
			std::cerr << RED << e.what() << END <<std::endl;
		}
		try {
			std::cout << BOLD << std::endl <<  "----- RobotomyRequestForm Sign OK & Execute NG----" << END << std::endl;
			Bureaucrat bureaucrat3("bureaucrat", 60);
			std::cout << bureaucrat3 << std::endl;
			RobotomyRequestForm form3("robot3");
			bureaucrat3.signForm(form3);
			std::cout << form3 << std::endl;
			bureaucrat3.executeForm(form3);
		} catch (std::exception &e) {
			std::cerr << RED << e.what() << END <<std::endl;
		}
	}
	std::cout << "----------------------------------------------------------------------------------" << std::endl;
	{
		try {
			std::cout << BOLD << "----- ShrubberyCreationForm : 145 grade to sign : 137 grade to execute ----" << END << std::endl;
			std::cout << BOLD << std::endl << "----- ShrubberyCreationForm Sign OK && Execute OK ----" << END << std::endl;
			Bureaucrat bureaucrat("bureaucrat", 1);
			std::cout << bureaucrat << std::endl;
			ShrubberyCreationForm form("tree");
			bureaucrat.signForm(form);
			std::cout << form << std::endl;
			bureaucrat.executeForm(form);
			std::cout << BOLD << std::endl << "----  ShrubberyCreationForm Sign NG ----" << END << std::endl;
			Bureaucrat bureaucrat2("bureaucrat2", 146);
			std::cout << bureaucrat2 << std::endl;
			ShrubberyCreationForm form2("tree2");
			bureaucrat2.signForm(form2);
		} catch (std::exception &e) {
			std::cerr << RED << e.what() << END <<std::endl;
		}
		try {
			std::cout << BOLD << std::endl << "----- ShrubberyCreationForm Sign OK & Execute NG ----" << END << std::endl;
			Bureaucrat bureaucrat3("bureaucrat", 140);
			std::cout << bureaucrat3 << std::endl;
			ShrubberyCreationForm form3("tree3");
			bureaucrat3.signForm(form3);
			std::cout << form3 << std::endl;
			bureaucrat3.executeForm(form3);
		} catch (std::exception &e) {
			std::cerr << RED << e.what() << END <<std::endl;
		}
	}
	std::cout << "----------------------------------------------------------------------------------" << std::endl;
	{
		try {
			// std::cout << "AForm" << std::endl;
			// cannot compile because AForm is abstract
			// AForm form("form", 1, 1);
		} catch (std::exception &e) {
			std::cerr << RED << e.what() << END <<std::endl;
		}
	}
}