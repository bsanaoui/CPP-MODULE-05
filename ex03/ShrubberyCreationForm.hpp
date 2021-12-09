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

    // --------------- Public Members Function ---------------//
    void    execute( Bureaucrat const & executor) const;
};

#endif