#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "AForm constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(AForm const &copy) : _name(copy.getName()), _signed(copy.getSigned()), _gradeToSign(copy.getGradeToSign()), _gradeToExecute(copy.getGradeToExecute())
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(AForm const &copy)
{
	std::cout << "AForm assignation operator called" << std::endl;
	if (this != &copy)
	{
		const_cast<std::string&>(this->_name) = copy._name;
		this->_signed = copy._signed;
		const_cast<int&>(this->_gradeToSign) = copy._gradeToSign;
		const_cast<int&>(this->_gradeToExecute) = copy._gradeToExecute;
	}
	return (*this);
}

std::string const	AForm::getName() const
{
	return (this->_name);
}

bool				AForm::getSigned() const
{
	return (this->_signed);
}

int					AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int					AForm::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void				AForm::beSigned(Bureaucrat const &burocrat)
{
	if (this->_signed) {
		std::cout << GREEN << "AForm already signed" << END <<std::endl;
		return ;
	}
	if (burocrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	std::cout << GREEN << "AForm signed by " << burocrat.getName() << END <<std::endl;
	this->_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed");
}


std::ostream &operator<<(std::ostream &out, AForm const &Aform)
{
	out << "---------- Form Info-----------" << std::endl;
	out << "Name: " << Aform.getName() << std::endl;
	out << "Signed: " << Aform.getSigned() << std::endl;
	out << "Grade to sign: " << Aform.getGradeToSign() << std::endl;
	out << "Grade to execute: " << Aform.getGradeToExecute() << std::endl;
	out << "-------------------------------" << std::endl;
	return (out);
}