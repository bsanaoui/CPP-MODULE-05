#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main ()
{

    try
    {   
         // ------- Create Bureaucrat and Forms -------------- //
        Bureaucrat bureaucrat("Markon Veraty", 5); // if Grade < 1 OR Grade > 150 will catch an excep
        ShrubberyCreationForm shrubberyCreationForm("home");
        RobotomyRequestForm robotomyRequestForm("robot");
        PresidentialPardonForm presidentialPardonForm("president");

        // ------------ incrementGrade ------------ //
        bureaucrat.incrementGrade();

        // ------------ decrementGrade ------------- //
        // bureaucrat.decrementGrade();
        // bureaucrat.decrementGrade();

        // ------------ Sign the form --------------- //
        // presidentialPardonForm.beSigned(bureaucrat);
        bureaucrat.signForm(&shrubberyCreationForm);
        
        // ------------ Execute the form --------------- //
        // shrubberyCreationForm.execute(bureaucrat);
        bureaucrat.executeForm(shrubberyCreationForm);
        // ----------  Operator Overload << ---------//
        std::cout << "\n// ---------------  Info Bureaucrats & Forms ------------------ //\n" << std::endl;
        std::cout << bureaucrat << std::endl;

        std::cout << shrubberyCreationForm << std::endl;
        std::cout << presidentialPardonForm << std::endl;
        std::cout << robotomyRequestForm << std::endl;

    }
    catch (std::exception &e)
    {
        std::cout << "Exception : " << e.what() << std::endl; 
    }
  
    return (0);
}