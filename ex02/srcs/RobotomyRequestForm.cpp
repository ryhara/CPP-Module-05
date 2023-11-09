#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExecute()), _target(copy.getTarget())
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &copy)
{
	std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
	if (this != &copy)
	{
		AForm::operator=(copy);
		this->_target = copy.getTarget();
	}
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executer) const
{
	std::srand(std::time(NULL));
	int random = std::rand();
	if (this->getSigned() == false)
		throw AForm::FormNotSignedException();
	if (executer.getGrade() > this->getGradeToExecute())
		throw Bureaucrat::GradeTooLowException();
	std::cout << BLUE << "bzzzzzzzzzzzzzzzz" << END << std::endl;
	if (random % 2 == 0)
		std::cout << GREEN << this->getTarget() << " has been robotomized successfully." << END << std::endl;
	else
		std::cout << RED << this->getTarget() << " robotomization failed." << END << std::endl;
}