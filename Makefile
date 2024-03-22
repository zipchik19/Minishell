NAME=minishell
SRC=$(wildcard cmd/*.c) \
	$(wildcard main/*.c) \
	$(wildcard parsing/*.c) \
	$(wildcard utils/*.c)
OBJ=$(SRC:src/%.c=obj/%.o) 
CC=cc
CFLAGS=-Wall -Werror -Wextra #-fsanitize=address -static-libsan -g
#CFLAGS=-Wall -Werror -Wextra -g
RM=rm -rf
INCLUDES = -Ireadline/include
LINKERS	= -Lreadline/lib -lreadline -lhistory
PREFIX = $(shell pwd)/readline

all: $(NAME)

obj/%.o : src/%.c obj/marker readline minishell.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME) : $(OBJ) readline
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) -o $(NAME) $(LINKERS)

clean:
	$(RM) obj
	make -C readline-8.1 clean
	rm -rf readline

fclean: clean
	$(RM) $(NAME)

readline:
	cd readline-8.1  && ./configure --prefix=$(PREFIX) && make && make install

obj/marker:
	mkdir -p obj
	touch obj/marker

re: fclean all

.PHONY: re fclean clean all