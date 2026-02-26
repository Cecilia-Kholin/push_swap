# -------------------------------
# VARIABLES
# -------------------------------
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

SRCS = push_swap.c \
       ksort.c \
	   isdigit.c \
	   new_node.c \
	   push.c \
	   reverse_rotate.c \
	   rotate.c \
	   swap.c \
	   utils.c \
	   movesstack.c \
	   utilsksort.c \
	   ft_split.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re