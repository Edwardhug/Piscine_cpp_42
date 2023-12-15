NAME = megaphone

CC = c++

CFLAG = -Wall -Wextra -Werror -std=c++98

SRCS =	megaphone.cpp

OBJS = $(SRCS:%.cpp=$(PATH_OBJS)%.o)

PATH_SRCS = ./

PATH_OBJS = obj/

all: $(NAME)

$(NAME) : $(PATH_OBJS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


$(OBJS)	: $(PATH_OBJS)%.o: $(PATH_SRCS)%.cpp
				$(CC) $(CFLAG) -c $< -o $@

$(PATH_OBJS) :
				mkdir -p $(PATH_OBJS)

clean:
	rm -rf ${OBJS} $(PATH_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

FORCE: 

.PHONY: all re bonus clean fclean