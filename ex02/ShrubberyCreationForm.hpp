#ifndef __ShrubberyCreationForm__
#define __ShrubberyCreationForm__

#include <iostream>
#include "Form.hpp"

class Form;

class ShrubberyCreationForm : public Form
{
    private:
    std::string _target;

    public:
    ShrubberyCreationForm( std::string target );
    ShrubberyCreationForm();
    ShrubberyCreationForm( const ShrubberyCreationForm &form );
    ~ShrubberyCreationForm();

    // ---------- Assignement operator ------------------------ //
    ShrubberyCreationForm& operator = ( const ShrubberyCreationForm  &form);
    
    // --------------- Public Members Function --------------- //
    void    execute( Bureaucrat const & executor) const;
    const std::string getTarget() const;
};

#endif