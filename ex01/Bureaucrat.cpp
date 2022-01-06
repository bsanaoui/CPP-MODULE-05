#include "Bureaucrat.hpp"

    // ---------------- Constructors & Destructors ------------- //
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
        this->_grade = grade;
}
 
Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat() : _name("Unkonwn"), _grade(1){}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
    *this = bureaucrat;
}


    // ----------------- Getters & Setters ------------------------ //
const std::string &Bureaucrat::getName() const
{
    return (this->_name);
}

const int         &Bureaucrat::getGrade() const
{
    return (this->_grade);
}


    // ------------------- Members Public functions ---------------- //
void    Bureaucrat::incrementGrade()
{
    if ((this->_grade - 1) < 1)
        throw GradeTooHighException();
    else
        this->_grade--;
}

void    Bureaucrat::decrementGrade()
{
    if ((this->_grade + 1) > 150)
        throw GradeTooLowException();
    else
        this->_grade++;
}

void    Bureaucrat::signForm(Form *form)
{
    // if ( form->getSignature() )
    //     std::cout << this->_name << " cannot signs" << form->getName()
    //             << "because the form :" << form->getName() << " was already signed !" << "." << std::endl;
    if ( this->_grade <= form->getSignedGrade())
    {
        std::cout << this->_name << " signs " << form->getName() << "." << std::endl;
        form->setSignature(true);
    }
    else
        std::cout << this->_name << " cannot signs " << form->getName()
                << ", because his grade is low to sign the form " << form->getName() << "." << std::endl;
}

    // ------------------  Operator Assignement ----------------------- //
Bureaucrat&   Bureaucrat::operator = (Bureaucrat const &bureaucrat) 
{
    this->_grade = bureaucrat._grade;
    return (*this);
}

    // ------------------  Operator Overload  << ----------------------- //
std::ostream& operator<< (std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return os;
}


    // ------------------  Exception class ----------------------- //
const char * Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("The grade is too high");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("The grade is too low");
}