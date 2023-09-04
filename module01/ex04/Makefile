NAME 			= sed
SRCS 			= ./main.cpp
OBJS 			= $(SRCS:.cpp=.o)
RM				= rm -f
FLAGS			= -Wall -Wextra -Werror -std=c++98
CC				= clang++

.cpp.o:
	$(CC) $(FLAGS) -c $< -o ${<:.cpp=.o}

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) -f $(OBJS) $(OBJS_B)

re: fclean all

test: re
	./sed && echo
	./sed file && echo
	./sed file ok && echo
	./sed fele hello "42 students" && echo
	echo "hey hello, you're awesome" > file && cat file && echo
	./sed file hello "42 students" && cat file.replace && echo
	./sed file "you're awesome" "wassup?" && cat file.replace && echo

.PHONY: all clean fclean re .cpp.o