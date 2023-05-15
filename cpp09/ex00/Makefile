CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 #-g

#project info
NAME = btc

#sourc code
SRC_FILES = main.cpp BitCoinExchange.cpp
HEADER_FILES = BitCoinExchange.hpp

all : $(NAME)

$(NAME): $(SRC_FILES) $(HEADER_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(NAME) 

fclean: 
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re
