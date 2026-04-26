CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = humans

SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp 
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS) $(NAME)

re: clean all

.PHONY: all clean re
