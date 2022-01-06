#include "ShrubberyCreationForm.hpp"
#include <fstream>

    // ---------------- Constructors & Destructors ------------- //


ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) 
    : _target(target), Form("ShrubberyCreation", 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm() : _target("Unkonwn"), Form("ShrubberyCreation ", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &form )
    : _target(form.getTarget()), Form("ShrubberyCreation", 145, 137)
{
    *this = form;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

  // ------------------------ Getters --------------------------- //

const std::string ShrubberyCreationForm::getTarget() const
{
    return (this->_target);
}
  // -------------------- Assignement operator -------------------- //

ShrubberyCreationForm&   ShrubberyCreationForm::operator = ( const ShrubberyCreationForm  &form)
{
    this->_target= form.getTarget();
    return (*this);
}
// --------------- Public Members Function ---------------//
void    ShrubberyCreationForm::execute( Bureaucrat const & executor) const
{
    if (!this->getSignature())
        throw FormNotSignedException(this->getName());
    else if (executor.getGrade() > this->getExecutedGrade())
        throw GradeTooLowException();
    else
    {
        std::ofstream file(this->_target);
        // ---------------- Draw ASCII Tree in the file target ------------- //
        file 
        << "                                                         . \n"
        << "                                          .         ;    \n"
        << "             .              .              ;%     ;;     \n"
        << "               ,           ,                :;%  %;     \n"
        << "                :         ;                   :;%;'     ., \n"  
        << "       ,.        %;     %;            ;        %;'    ,;  \n"
        << "         ;       ;%;  %%;        ,     %;    ;%;    ,%'  \n"
        << "          %;       %;%;      ,  ;       %;  ;%;   ,%;'   \n"
        << "           ;%;      %;        ;%;        % ;%;  ,%;'  \n"
        << "            `%;.     ;%;     %;'         `;%%;.%;'  \n"
        << "             `:;%.    ;%%. %@;        %; ;@%;%'  \n"
        << "                `:%;.  :;bd%;          %;@%;'  \n"
        << "                  `@%:.  :;%.         ;@@%;'     \n"
        << "                    `@%.  `;@%.      ;@@%;           \n"
        << "                      `@%%. `@%%    ;@@%;          \n"
        << "                        ;@%. :@%%  %@@%;         \n"
        << "                          %@bd%%%bd%%:;       \n"
        << "                            #@%%%%%:;;  \n"
        << "                            %@@%%%::;  \n"
        << "                            %@@@%(o);  . '           \n"
        << "                            %@@@o%;:(.,'           \n"
        << "                        `.. %@@@o%::;           \n"
        << "                           `)@@@o%::;           \n"
        << "                            %@@(o)::;          \n"
        << "                           .%@@@@%::;           \n"
        << "                           ;%@@@@%::;.            \n"
        << "                          ;%@@@@%%:;;;.   \n"
        << "                      ...;%@@@@@%%:;;;;,..      \"" << this->_target << "\""
        << std::endl;
        // ------------------------------------------------------------------- //
        file.close(); 
    }
}