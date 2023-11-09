#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
	std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExecute()), _target(copy.getTarget())
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy)
{
	std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
	if (this != &copy)
	{
		AForm::operator=(copy);
		this->_target = copy.getTarget();
	}
	return (*this);
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executer) const
{
	if (this->getSigned() == false)
		throw AForm::FormNotSignedException();
	if (executer.getGrade() > this->getGradeToExecute())
		throw Bureaucrat::GradeTooLowException();
	std::ofstream ofs(this->getTarget() + "_shrubbery");
	if (!ofs)
	{
		std::cerr << RED << "Error: could not open file" << END << std::endl;
		std::exit(1);
	}
	ofs << GREEN << "                                               .           " << END << std::endl;
	ofs << GREEN << "                                   .         ;             " << END << std::endl;
	ofs << GREEN << "      .              .              ;%     ;;              " << END << std::endl;
	ofs << GREEN << "        ,           ,                :;%  %;               " << END << std::endl;
	ofs << GREEN << "         :         ;                   :;%;'     .,        " << END << std::endl;
	ofs << GREEN << ",.        %;     %;            ;        %;'    ,;          " << END << std::endl;
	ofs << GREEN << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'           " << END << std::endl;
	ofs << GREEN << "   %;       %;%;      ,  ;       %;  ;%;   ,%;'            " << END << std::endl;
	ofs << GREEN << "    ;%;      %;        ;%;        % ;%;  ,%;'              " << END << std::endl;
	ofs << GREEN << "     `%;.     ;%;     %;'         `;%%;.%;'                " << END << std::endl;
	ofs << GREEN << "      `:;%.    ;%%. %@;        %; ;@%;%'                   " << END << std::endl;
	ofs << GREEN << "         `:%;.  :;bd%;          %;@%;'                     " << END << std::endl;
	ofs << GREEN << "           `@%:.  :;%.         ;@@%;'                      " << END << std::endl;
	ofs << GREEN << "             `@%.  `;@%.      ;@@%;                        " << END << std::endl;
	ofs << GREEN << "               `@%%. `@%%    ;@@%;                         " << END << std::endl;
	ofs << GREEN << "                 ;@%. :@%%  %@@%;                          " << END << std::endl;
	ofs << GREEN << "                   %@bd%%%bd%%:;                           " << END << std::endl;
	ofs << GREEN << "                     #@%%%%%:;;                            " << END << std::endl;
	ofs << GREEN << "                     %@@%%%::;                             " << END << std::endl;
	ofs << GREEN << "                     %@@@%(o);  . '                        " << END << std::endl;
	ofs << GREEN << "                     %@@@o%;:(.,'                          " << END << std::endl;
	ofs << GREEN << "                 `.. %@@@o%::;                             " << END << std::endl;
	ofs << GREEN << "                    `)@@@o%::;                             " << END << std::endl;
	ofs << GREEN << "                     %@@(o)::;                             " << END << std::endl;
	ofs << GREEN << "                    .%@@@@%::;                             " << END << std::endl;
	ofs << GREEN << "                    ;%@@@@%::;.                            " << END << std::endl;
	ofs << GREEN << "                   ;%@@@@%%:;;;.                           " << END << std::endl;
	ofs << GREEN << "               ...;%@@@@@%%:;;;;,..                        " << END << std::endl;
}
