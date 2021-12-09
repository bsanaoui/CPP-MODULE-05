#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string target ) 
    : _target(target), Form("PresidentialPardon", 25, 5){}

// --------------- Public Members Function ---------------//
void    PresidentialPardonForm::execute( Bureaucrat const & executor) const
{
    if (this->getSignature())
        throw FormAlreadySignedException(this->getName());
    else if (executor.getGrade() > this->getExecutedGrade())
        throw GradeTooLowException();
    else
        std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}