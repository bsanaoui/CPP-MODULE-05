#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern(){}

Intern::Intern( const Intern &form )
{
    *this = form;
}

Intern::~Intern(){}

  // -------------------- Assignement operator -------------------- //

Intern&   Intern::operator = ( const Intern  &intern)
{
    (const Intern)intern;
    return (*this);
}

    // ------------------ Member functions ------------------------ //

Form*  Intern::makeShrubberyCreation(std::string const & target) const {
    return new ShrubberyCreationForm(target);
}

Form*  Intern::makeRobotomyRequest(std::string const & target) const {
    return new RobotomyRequestForm(target);
}

Form*  Intern::makePresidentialPardon(std::string const & target) const {
    return new PresidentialPardonForm(target);
}


Form * Intern::makeForm( std::string form_name, std::string target)
{
    std::string const form_names[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};

    Form* (Intern::*forms[3])(std::string const &) const = {
        &Intern::makeShrubberyCreation,
        &Intern::makeRobotomyRequest, 
        &Intern::makePresidentialPardon
    };
    for (int i = 0; i < 3; i++)
        if (!form_name.compare(form_names[i]))
        {
            std::cout << "Intern creates " << form_name << "." << std::endl;
            return (this->*(forms[i]))(target);
        }
    std::cout << "The form is unkown" << std::endl;
    return (NULL);
}