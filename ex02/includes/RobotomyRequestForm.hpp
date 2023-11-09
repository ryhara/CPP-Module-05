#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include <ctime>
#include <cstdlib>

#include "AForm.hpp"


// 72 grade to sign
// 45 grade to execute
// Makes some drilling noises. Then, informs that <target> has been robotomized successfully 50% of the time. Otherwise, informs that the robotomy failed.
class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);

		std::string getTarget() const;
		void execute(Bureaucrat const &executor) const;
};

#endif