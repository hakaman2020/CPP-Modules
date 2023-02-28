CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

#project info
NAME = brain 

#sourc code
SRC_FILES = main.cpp Brain.cpp AAnimal.cpp Cat.cpp Dog.cpp

all : $(NAME)

$(NAME): $(SRC_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(NAME) 

fclean: 
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re
