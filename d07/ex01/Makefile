.PHONY: all clean fclean re

FILES = iter

CC = clang++

FLAGS = -Wall -Wextra -Werror -std=c++98 -c

NAME = iter

SRC = $(addsuffix .cpp, $(FILES))

OBJ = $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp
	@$(CC) $(FLAGS) -o $@ $<

clean:
	@/bin/rm -rf $(OBJ)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all
