.PHONY: all clean fclean re

FILES = Division IToken main Minus Multiply Number ParClose ParOpen Plus TokenGenerator

CC = clang++

FLAGS = -Wall -Wextra -Werror -std=c++98 -c -I includes

NAME = notation

SRC = $(addprefix src/, $(addsuffix .cpp, $(FILES)))

OBJ = $(SRC:.cpp=.o)

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
