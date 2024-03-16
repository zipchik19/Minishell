NAME        = minishell
SRCS        = $(wildcard src/*/*.c)
OBJS        = $(SRCS:.c=.o)
CC          = cc
CFLAGS      = -Wall -Werror -Wextra -g
RM          = rm -rf
INCLUDES    = -Ireadline/include
LINKERS     = -Lreadline/lib -lreadline -lhistory
PREFIX      = $(shell pwd)/readline

all: $(NAME)

%.o : %.c readline minishell.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME) : $(OBJS) readline
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME) $(LINKERS)

clean:
	$(RM) $(OBJS)
	make -C readline-8.1 clean
	rm -rf readline

fclean: clean
	$(RM) $(NAME)

readline:
	cd readline-8.1 && ./configure --prefix=$(PREFIX) && make && make install

re: fclean all

.PHONY: all clean fclean re readline