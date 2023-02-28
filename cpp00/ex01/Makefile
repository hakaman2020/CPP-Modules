CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

#project info
NAME = phonebook

#sourc code
SRC_FILES = main.cpp contact.cpp phonebook.cpp

all : $(NAME)

$(NAME): $(SRC_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(NAME) 

fclean: 
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re
