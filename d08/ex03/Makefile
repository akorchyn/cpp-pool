.PHONY: all clean fclean re

FILES = EndCycle Generator Ignore Input IOperation main Minus NextElement Plus PrevElement Print StartCycle

CC = clang++

FLAGS = -Wall -Wextra -Werror -std=c++98 -c -I includes

NAME = openmind

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
