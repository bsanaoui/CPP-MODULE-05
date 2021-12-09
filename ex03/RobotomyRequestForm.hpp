#ifndef __RobotomyRequestForm__
#define __RobotomyRequestForm__

#include <iostream>
#include "Form.hpp"

class Form;

class RobotomyRequestForm : public Form
{
    private:
    std::string _target;

    public:
    RobotomyRequestForm( std::string target );

    // --------------- Public Members Function ---------------//
    void    execute( Bureaucrat const & executor) const;
};

#endif