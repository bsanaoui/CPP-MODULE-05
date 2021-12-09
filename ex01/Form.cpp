#include "Form.hpp"

    // ---------------- Constructors & Destructors ------------- //
Form::Form(std::string name, int signed_grade, int executed_grade)
    : _name(name) , _executed_grade(executed_grade) , _signed_grade(signed_grade)
{
    if (executed_grade < 1 || signed_grade < 1)
        throw GradeTooHighException();
    else if (executed_grade > 150 || signed_grade > 150)
        throw GradeTooLowException();
    this->_signed = false;
}

    // ----------------- Getters & Setters ------------------------ //
const std::string&  Form::getName() const
{
    return (this->_name);
}

const int&          Form::getExecutedGrade() const
{
    return (this->_executed_grade);
}

const int&         Form::getSignedGrade() const
{
    return (this->_signed_grade);
}

const bool&         Form::getSignature() const
{
    return (this->_signed);
}

void                Form::setSignature(bool b)
{
    this->_signed = b;
}

    // ------------------- Members Public functions ---------------- //
void                Form::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->_signed_grade)
        this->_signed = true;
    else
        throw GradeTooLowException();
}

    // ------------------  Exception class ----------------------- //
const char * Form::GradeTooHighException::what() const throw()
{
    return ("The grade is too high");
}

const char * Form::GradeTooLowException::what() const throw()
{
    return ("The grade is too low");
}

    // ------------------  Operator Overload  << ----------------------- //
std::ostream& operator<< (std::ostream& os, const Form& form)
{
    if (form.getSignature())
        os << "The Form " << form.getName() << ", require " << form.getSignedGrade() << " to signe it and "
            << form.getExecutedGrade() << " to execute it, was signed";
    else
        os << "The Form " << form.getName() << ", require " << form.getSignedGrade() << " to signe it and "
            << form.getExecutedGrade() << " to execute it, was \"not signed\"";
    return (os);
}


