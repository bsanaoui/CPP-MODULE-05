#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp" 

int main ()
{
    Intern someRandomIntern;
    Form* rrf;
    
    rrf = someRandomIntern.makeForm("robotomy reest", "Bender");

    // ---------- create bureaucrate ----------- //
    Bureaucrat bureaucrat("CMOS", 5);

    // ----------- execute the Form ------------ //
    if (rrf)
        bureaucrat.executeForm(*rrf);
    return (0);
}