#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) 
    : _target(target), Form("ShrubberyCreation", 145, 137){}

// --------------- Public Members Function ---------------//
void    ShrubberyCreationForm::execute( Bureaucrat const & executor) const
{
    if (this->getSignature())
        throw FormAlreadySignedException(this->getName());
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