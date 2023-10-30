NAME 			= RPN
SRCS 			= ./RPN.cpp ./main.cpp
OBJS 			= $(SRCS:.cpp=.o)
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -std=c++98
CXX				= c++

.cpp.o:
	$(CXX) $(CFLAGS) -c $< -o ${<:.cpp=.o}

$(NAME): $(OBJS)
	$(CXX) -fsanitize=address $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) -f $(OBJS) $(OBJS_B)

re: fclean all

test: re
	./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
	./RPN "7 7 * 7 -"
	./RPN "1 2 * 2 / 2 * 2 4 - +"
	./RPN "(1 + 1)"

.PHONY: all clean fclean re .cpp.o