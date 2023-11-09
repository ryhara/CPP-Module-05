#ifndef AFOR_HPP
# define AFOR_HPP

#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				_signed;
		int	const			_gradeToSign;
		int	const			_gradeToExecute;
	public:
		AForm();
		AForm(std::string const &name, int gradeToSign, int gradeToExecute);
		AForm(AForm const &copy);
		virtual ~AForm();
		AForm &operator=(AForm const &copy);

		std::string const	getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void		beSigned(Bureaucrat const &burocrat);
		virtual void execute(Bureaucrat const & executor) = 0;
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, AForm const &Aform);

#endif