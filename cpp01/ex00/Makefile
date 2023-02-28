CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

#project info
NAME =  zombie

#sourc code
SRC_FILES = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

all : $(NAME)

$(NAME): $(SRC_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(NAME) 

fclean: 
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re
