#include "Bureaucrat.hpp"

    // ---------------- Constructors & Destructors ------------- //
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade < 1)
        throw "Bureaucrat::GradeTooHighException";
    else if (grade > 150)
        throw "Bureaucrat::GradeTooLowException";
    else
        this->_grade = grade;
}
 
Bureaucrat::~Bureaucrat(){}

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
        throw "Bureaucrat::GradeTooHighException";
    else
        this->_grade--;
}

void    Bureaucrat::decrementGrade()
{
    if ((this->_grade + 1) > 150)
        throw "Bureaucrat::GradeTooLowException";
    else
        this->_grade++;
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
