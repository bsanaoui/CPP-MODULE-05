#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Form * Intern::makeForm( std::string form_name, std::string target)
{
    std::string form_names[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};

    Form *forms[3] = { new RobotomyRequestForm(target),
                        new PresidentialPardonForm(target),
                        new ShrubberyCreationForm(target)};

    for (int i = 0; i < 3; i++)
        if (!form_name.compare(form_names[i]))
        {
            std::cout << "Intern creates " << forms[i]->getName() << "." << std::endl;
            return forms[i];
        }
    std::cout << "The form is unkown" << std::endl;
    return (NULL);
}