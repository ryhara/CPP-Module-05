#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include <fstream>

#include "AForm.hpp"

// 145 grade to sign
// 137 grade to execute
// Create a file <target>_shrubbery in the working directory, and writes ASCII trees inside it.
class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);

		std::string getTarget() const;
		void execute(Bureaucrat const &executor) const;
};

#endif