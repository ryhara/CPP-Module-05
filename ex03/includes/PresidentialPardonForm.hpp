#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include <exception>

#include "AForm.hpp"

// 25 grade to sign
// 5 grade to execute
// Informs that <target> has been pardoned by Zaphod Beeblebrox.
class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);

		std::string getTarget() const;
		void execute(Bureaucrat const &executor) const;
};

#endif