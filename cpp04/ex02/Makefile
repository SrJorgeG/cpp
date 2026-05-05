CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Brain
SRCS = Animal.cpp WrongAnimal.cpp Cat.cpp WrongCat.cpp Dog.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CXX) $(CXXFLAGS) -I$(LIB_DIR) -c $< -o $@

clean:
	rm -f $(OBJS) $(NAME)

re: clean all

.PHONY: all clean re
