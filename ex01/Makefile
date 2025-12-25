# My First Class in Orthodox Canonical Form
NAME = ex01
SRCS = main.cpp Fixed.cpp
OBJS = $(SRCS:.cpp=.o)
# Compiler
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors

# Rules
all: $(NAME)

$(NAME):	$(OBJS) 
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclea