CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

#project info
NAME = fragTrap 

#sourc code
SRC_FILES = main.cpp ClapTrap.cpp FragTrap.cpp

all : $(NAME)

$(NAME): $(SRC_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(NAME) 

fclean: 
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re
