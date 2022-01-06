#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp" 

int main ()
{
    Intern someRandomIntern;
    Form* rrf;
    
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");

    // ---------- create bureaucrate ----------- //
    Bureaucrat bureaucrat("CMOS", 5);

    // ----------- execute the Form ------------ //
    try
    {
        if (rrf)
        {
            bureaucrat.signForm(rrf);
            bureaucrat.executeForm(*rrf);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << *rrf << std::endl;
    return (0);
}