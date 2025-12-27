# Now we’re talking
NAME = ex02
SRCS = main.cpp Fixed.cpp
OBJS = $(SRCS:.cpp=.o)
# Compiler
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

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

.PHONY: all clean fclean re