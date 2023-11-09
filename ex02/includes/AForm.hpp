#ifndef AFOR_HPP
# define AFOR_HPP

#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"

#define END				"\033[0m"
#define BOLD			"\033[1m"
#define BLACK			"\033[30m"
#define RED				"\033[31m"
#define GREEN			"\033[32m"
#define YELLOW			"\033[33m"
#define BLUE			"\033[34m"
#define MAGENTA			"\033[35m"
#define CYAN			"\033[36m"
#define WHITE			"\033[37m"
#define UNDERLINE		"\033[4m"
#define BOLD_UNDERLINE	"\033[1;4m"

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
		virtual void execute(Bureaucrat const & executor) const = 0;
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
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, AForm const &Aform);

#endif