CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

#project info
NAME = violence

#sourc code
SRC_FILES = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

all : $(NAME)

$(NAME): $(SRC_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(NAME) 

fclean: 
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re
