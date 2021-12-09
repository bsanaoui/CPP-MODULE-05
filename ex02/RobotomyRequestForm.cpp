#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( std::string target ) 
    : _target(target), Form("RobotomyRequest", 72, 45){}

// --------------- Public Members Function ---------------//
void    RobotomyRequestForm::execute( Bureaucrat const & executor) const
{
    if (this->getSignature())
        throw FormAlreadySignedException(this->getName());
    else if (executor.getGrade() > this->getExecutedGrade())
        throw GradeTooLowException();
    else
         std::cout << this->_target << " has been robotomized successfully 50% of the time" << std::endl;
}