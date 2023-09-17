NAME 			= animal
SRCS 			= ./Animal.cpp ./Cat.cpp ./Dog.cpp ./WrongAnimal.cpp ./WrongCat.cpp ./main.cpp
OBJS 			= $(SRCS:.cpp=.o)
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -std=c++98
CXX				= c++

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) -f $(OBJS) $(OBJS_B)

re: fclean all

.PHONY: all clean fclean re .cpp.o