#ifndef __FORM__
#define __FORM__

#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    // Private Members ----- //
    private:
    const std::string   _name;
    const int           _executed_grade;
    const int           _signed_grade;
    bool                _signed;

    // Public Members ------ //
    public:
    // ---------------- Constructors & Destructors ------------- //
    Form( std::string name, int signed_grade, int executed_grade );
    Form();
    Form( const Form &form );
    ~Form();

    // ---------------- Constructors & Destructors ------------- //
    Form&   operator = ( const Form  &form);

    // ----------------- Getters & Setters ------------------------ //
    const std::string&  getName() const;
    const int&          getSignedGrade() const;
    const int&          getExecutedGrade() const;
    const bool&         getSignature() const;

    void                setSignature(bool);

    // ------------------- Members Public functions ---------------- //
    void                beSigned( Bureaucrat const &bureaucrat );
    virtual void        execute(Bureaucrat const & executor) const = 0;

     // Exception GradeTooHighException ------------------------------//
    class GradeTooHighException : public std::exception
    {
        const char * what () const throw ();
    };

     // Exception GradeTooLowhException ------------------------------//
    class GradeTooLowException : public std::exception
    {
        const char * what () const throw ();
    };

    // Exception FormAlreadySignedException ------------------------------//
    class FormNotSignedException : public std::exception
    {
        private:
        std::string _form_name;

        public:
        FormNotSignedException( std::string form_name);
        ~FormNotSignedException() throw();
        const char * what () const throw ();
    };
};

// ------------------  Operator Overload  << ----------------------- //
    std::ostream& operator<< ( std::ostream& os, const Form& form );

#endif