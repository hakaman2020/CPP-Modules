CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

#project info
NAME = serialize

#sourc code
SRC_FILES = serial.cpp
HEADER_FILES = serial.hpp
all : $(NAME)

$(NAME): $(SRC_FILES) $(HEADER_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(NAME) 

fclean: 
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re
