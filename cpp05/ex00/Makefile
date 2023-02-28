CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

#project info
NAME = bureaucrat 

#sourc code
SRC_FILES = main.cpp Bureaucrat.cpp

all : $(NAME)

$(NAME): $(SRC_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(NAME) 

fclean: 
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re
