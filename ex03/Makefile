NAME = Intern

CC = clang++
FLAGS = -Werror -Wextra -Wall

SRC = main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp \
		 RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

all : $(NAME)

$(NAME) : $(SRC)
	@$(CC) $(SRC) $(FLAG) -o $(NAME)

fclean : clean
	@rm -f $(NAME)

clean :

re : fclean all