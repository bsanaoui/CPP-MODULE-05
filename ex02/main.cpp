#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()
{

    try
    {       // ------- Create Bureaucrat and Form -------------- //
        Bureaucrat bureaucrat("Markon Veraty", 150); // if Grade < 1 OR Grade > 150 will catch an excep
        Form form("28D", 50, 50);
            // ------------ incrementGrade ------------ //
        bureaucrat.incrementGrade();
          // ------------ decrementGrade ------------ //
        // bureaucrat.decrementGrade();
        // bureaucrat.decrementGrade();
         // ------------ Sign the form ------------ //
        // form.beSigned(bureaucrat);
        bureaucrat.signForm(&form);
          // ----------  Operator Overload << -------//
        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception : " << e.what() << std::endl; 
    }
  
    return (0);
}