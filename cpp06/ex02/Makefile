CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

#project info
NAME = identify 

#sourc code
SRC_FILES = identify.cpp
HEADER_FILES = identify.hpp

all : $(NAME)

$(NAME): $(SRC_FILES) $(HEADER_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(NAME) 

fclean: 
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re
