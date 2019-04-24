NAME = ft_retro
SRC = CosmoObject.cpp List.cpp main.cpp Menu.cpp ObjectsGenerator.cpp RetroWindow.cpp
OBJ = $(SRC:.cpp=.o)
CC = clang++
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) -lncurses

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
