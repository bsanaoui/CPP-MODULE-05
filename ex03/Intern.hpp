#ifndef __INTERN__
#define __INTERN__

#include <iostream>

#include "Form.hpp"

class Form;

class Intern
{
    public :

    // ---------------- Constructors & Destructors ------------- //

    Intern();
    Intern( const Intern &intern );
    ~Intern();
    
    // ---------------- member Function ------------------ //
    Form * makeForm( std::string form_name, std::string target);

    // ---------------- Assignement operator ------------- //
    Intern&   operator= ( const Intern  &intern);


    Form*  makeShrubberyCreation(std::string const & target) const ;
    Form*  makeRobotomyRequest(std::string const & target) const ;
    Form*  makePresidentialPardon(std::string const & target) const ;

};

#endif