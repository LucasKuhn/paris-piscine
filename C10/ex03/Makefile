NAME	=	ft_hexdump
SRCS 	= 	main.c ft_hexdump.c print_hexdump.c utils.c print_error.c
CC		= gcc
CFLAGS	+= -Wall -Wextra -Werror
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY: clean fclean