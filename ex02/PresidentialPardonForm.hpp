#ifndef __PresidentialPardonForm__
#define __PresidentialPardonForm__

#include <iostream>
#include "Form.hpp"

class Form;

class PresidentialPardonForm : public Form
{
    private:
    std::string _target;

    public:
    PresidentialPardonForm( std::string target );
    PresidentialPardonForm();
    PresidentialPardonForm( const PresidentialPardonForm &form );
    ~PresidentialPardonForm();

    // ---------------- Constructors & Destructors ------------- //
    PresidentialPardonForm&   operator = ( const PresidentialPardonForm  &form);

    // --------------- Public Members Function ---------------//
    void    execute( Bureaucrat const & executor) const;
    const std::string getTarget() const;

};

#endif