NAME = Form

CC = clang++
FLAGS = -Werror -Wextra -Wall

SRC = main.cpp Bureaucrat.cpp Form.cpp

all : $(NAME)

$(NAME) : $(SRC)
	@$(CC) $(SRC) $(FLAG) -o $(NAME)

fclean : clean
	@rm -f $(NAME)

clean :

re : fclean all