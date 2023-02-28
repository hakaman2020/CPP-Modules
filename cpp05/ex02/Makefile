CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

#project info
NAME = executor

#sourc code
SRC_FILES = main.cpp Bureaucrat.cpp Form.cpp \
			PresidentialPardonForm.cpp \
			RobotomyRequestForm.cpp \
			ShrubberyCreationForm.cpp

all : $(NAME)

$(NAME): $(SRC_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(NAME) 

fclean: 
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re
