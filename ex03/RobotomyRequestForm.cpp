#include "RobotomyRequestForm.hpp"

    // ---------------- Constructors & Destructors ------------- //

RobotomyRequestForm::RobotomyRequestForm( std::string target ) 
    : _target(target), Form("ShrubberyCreation", 72, 45){}

RobotomyRequestForm::RobotomyRequestForm() : _target("Unkonwn"), Form("ShrubberyCreation", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &form )
    : _target(form.getTarget()), Form("ShrubberyCreation", 72, 45)
{
    *this = form;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

  // ------------------------ Getters --------------------------- //

const std::string RobotomyRequestForm::getTarget() const
{
    return (this->_target);
}
  // -------------------- Assignement operator -------------------- //

RobotomyRequestForm&   RobotomyRequestForm::operator = ( const RobotomyRequestForm  &form)
{
    this->_target= form.getTarget();
    return (*this);
}

// --------------- Public Members Function ---------------//
void    RobotomyRequestForm::execute( Bureaucrat const & executor) const
{
    if (!this->getSignature())
        throw FormNotSignedException(this->getName());
    else if (executor.getGrade() > this->getExecutedGrade())
        throw GradeTooLowException();
    else // if modulo 
         std::cout << this->_target << " has been robotomized successfully 50% of the time" << std::endl;
}