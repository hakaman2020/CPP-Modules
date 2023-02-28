CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

#project info
NAME = convert

#sourc code
SRC_FILES = convert.cpp \
			printing.cpp
HEADER_FILES =	convert_structs.hpp \
				convert.hpp \
				printing.hpp
all : $(NAME)

$(NAME): $(SRC_FILES) $(HEADER_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(NAME) 

fclean: 
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re
