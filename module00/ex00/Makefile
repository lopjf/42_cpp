NAME 			= megaphone
SRCS 			= ./megaphone.cpp
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

test: re
	./megaphone "shhhhh... I think the students are asleep..."
	./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
	./megaphone

.PHONY: all clean fclean re .cpp.o