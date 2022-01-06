#include "Bureaucrat.hpp"

int main ()
{

    try
    {     // ---------- Create Bureaucrat -------------- //
        Bureaucrat bureaucrat("Markon Veraty", 150); // if Grade < 1 OR Grade > 150 will catch an excep
          // -------------- incrementGrade ------------ //
        bureaucrat.incrementGrade();
          // ------------ decrementGrade -------------- //
        bureaucrat.decrementGrade();
        bureaucrat.decrementGrade();
          // ----------  Operator Overload << --------- //
        std::cout << bureaucrat << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception : " << e.what() << std::endl; 
    }
  
    return (0);
}