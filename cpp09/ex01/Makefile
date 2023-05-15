CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

#project info
NAME = RPN 

#sourc code
SRC_FILES = main.cpp RPN.cpp
HEADER_FILES = RPN.hpp

all : $(NAME)

$(NAME): $(SRC_FILES) $(HEADER_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(NAME) 

fclean: 
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re
