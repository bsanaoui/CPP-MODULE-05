#include "PresidentialPardonForm.hpp"
    // ---------------- Constructors & Destructors ------------- //

PresidentialPardonForm::PresidentialPardonForm( std::string target ) 
    : _target(target), Form("PresidentialPardon", 25, 5){}

PresidentialPardonForm::PresidentialPardonForm() : _target("Unkonwn"), Form("PresidentialPardon", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &form )
    : _target(form.getTarget()), Form("PresidentialPardon", 25, 5)
{
    *this = form;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

  // ------------------------ Getters --------------------------- //

const std::string PresidentialPardonForm::getTarget() const
{
    return (this->_target);
}
  // -------------------- Assignement operator -------------------- //

PresidentialPardonForm&   PresidentialPardonForm::operator = ( const PresidentialPardonForm  &form)
{
    this->_target= form.getTarget();
    return (*this);
}

// --------------- Public Members Function ---------------//
void    PresidentialPardonForm::execute( Bureaucrat const & executor) const
{
    if (!this->getSignature())
        throw FormNotSignedException(this->getName());
    else if (executor.getGrade() > this->getExecutedGrade())
        throw GradeTooLowException();
    else
        std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
