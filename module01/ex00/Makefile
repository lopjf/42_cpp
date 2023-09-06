NAME 			= zombie
SRCS 			= ./newZombie.cpp ./randomChump.cpp ./Zombie.cpp ./main.cpp
OBJS 			= $(SRCS:.cpp=.o)
RM				= rm -f
FLAGS			= -Wall -Wextra -Werror -std=c++98
CC				= c++

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

.PHONY: all clean fclean re .cpp.o