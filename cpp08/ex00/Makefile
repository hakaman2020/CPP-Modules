CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 #-g

#project info
NAME = easyfind

#sourc code
SRC_FILES = main.cpp
HEADER_FILES = easyfind.hpp

all : $(NAME)

$(NAME): $(SRC_FILES) $(HEADER_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(NAME) 

fclean: 
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re
