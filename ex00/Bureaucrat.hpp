#ifndef __BUREAUCRAT__
#define __BUREAUCRAT__

#include <iostream>
#include <exception>

class Bureaucrat
{
    // Private Members ----- //
    private:
    const std::string   _name;
    int                 _grade;

    // Public Members ------ //
    public:
    // ---------------- Constructors & Destructors ------------- //
    Bureaucrat(std::string name, int grade);
    Bureaucrat();
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat &bureaucrat);

    // ----------------- Getters & Setters ------------------------ //
    const std::string& getName() const;
    const int&  getGrade() const;

    // ------------------- Members Public functions ---------------- //
    void    incrementGrade();
    void    decrementGrade();

    // ------------------  Operator Assignement ----------------------- //
    Bureaucrat& operator= (Bureaucrat const &bureaucrat);

    // Exception GradeTooHighException
    class GradeTooHighException : public std::exception
    {
        const char * what () const throw ();

    };
     // Exception GradeTooLowhException
    class GradeTooLowException : public std::exception
    {
        const char * what () const throw ();
    };
};

// ------------------  Operator Overload  << ----------------------- //
    std::ostream& operator<< (std::ostream& os, const Bureaucrat& bureaucrat);

#endif