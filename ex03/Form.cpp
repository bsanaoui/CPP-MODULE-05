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

Form::Form(): _name("Unkonw") , _executed_grade(5) , _signed_grade(5) {}

Form::Form( const Form &form )
    : _name(form.getName()) , _executed_grade(form.getExecutedGrade()) , _signed_grade(form.getSignedGrade())
{
    *this = form;
}

Form::~Form(){}

  // -------------------- Assignement operator -------------------- //

Form&   Form::operator = ( const Form  &form)
{
    this->_signed = form.getSignature();
    return (*this);
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

void        Form::execute(Bureaucrat const & executor) const
{
    if (!this->_signed)
        throw FormNotSignedException(this->_name);
    else if (executor.getGrade() > this->_executed_grade)
        throw GradeTooLowException();
    else
        std::cout << "The Bureaucrat " << executor.getName() << " execute the default form :"
                    << this->_name << std::endl;  
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

    // ------------------------ Exception implimentation ------------------//

const char * Form::GradeTooHighException::what() const throw ()
{
    return ("The grade is too high !");
}

const char * Form::GradeTooLowException::what() const throw ()
{
    return ("The grade is too low !");
}

Form::FormNotSignedException::FormNotSignedException( std::string form_name)
        : _form_name(form_name){}

Form::FormNotSignedException::~FormNotSignedException() throw()
{
    return ;
}

const char * Form::FormNotSignedException::what () const throw ()
{
    std::string msg = "The form :";
    msg.append(_form_name);
    msg.append(" not signed !");
    return (msg.c_str());
}


