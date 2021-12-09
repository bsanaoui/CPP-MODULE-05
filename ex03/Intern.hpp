#ifndef __INTERN__
#define __INTERN__

#include <iostream>

#include "Form.hpp"

class Form;

class Intern
{
    public :
    static Form * makeForm( std::string form_name, std::string target);
};

#endif