.PHONY: all clean fclean re

FILES = CattyDisplay CpuLoadDisplay CpuLoadModule DateDisplay DateModule HostnameUsernameDisplay HostnameUsernameModule\
        IMonitorDisplay IMonitorModule main MonitorGenerator MotivatorDisplay NetDisplay NetModule OsDisplay OsModule \
        RamLoadDisplay RamLoadModule Window

CC = clang++

FLAGS = -Wall -Wextra -Werror -std=c++98 -c -I includes

LIB = -lncurses

NAME = ft_gkrellm

SRC = $(addprefix src/, $(addsuffix .cpp, $(FILES)))

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(LIB)

%.o: %.cpp
	@$(CC) $(FLAGS) -o $@ $<

clean:
	@/bin/rm -rf $(OBJ)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all
