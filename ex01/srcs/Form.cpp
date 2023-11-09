#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Form constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(Form const &copy) : _name(copy.getName()), _signed(copy.getSigned()), _gradeToSign(copy.getGradeToSign()), _gradeToExecute(copy.getGradeToExecute())
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(Form const &copy)
{
	std::cout << "Form assignation operator called" << std::endl;
	if (this != &copy)
	{
		const_cast<std::string&>(this->_name) = copy._name;
		this->_signed = copy._signed;
		this->_gradeToSign = copy._gradeToSign;
		this->_gradeToExecute = copy._gradeToExecute;
	}
	return (*this);
}

std::string const	Form::getName() const
{
	return (this->_name);
}

bool				Form::getSigned() const
{
	return (this->_signed);
}

int					Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int					Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void				Form::beSigned(Bureaucrat const &burocrat)
{
	if (this->_signed) {
		std::cout << GREEN << "Form already signed" << END <<std::endl;
		return ;
	}
	if (burocrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	std::cout << GREEN << "Form signed by " << burocrat.getName() << END <<std::endl;
	this->_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}


std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << "---------- Form Info-----------" << std::endl;
	out << "Name: " << form.getName() << std::endl;
	out << "Signed: " << form.getSigned() << std::endl;
	out << "Grade to sign: " << form.getGradeToSign() << std::endl;
	out << "Grade to execute: " << form.getGradeToExecute() << std::endl;
	out << "-------------------------------" << std::endl;
	return (out);
}