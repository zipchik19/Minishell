NAME		= minishell
SRCS		= $(wildcard src/*/*.c)
#SRCS		+= $(wildcard src/*.c)
OBJS		= $(SRCS:.c=.o)
INCLUDES	= ./includes -I ./readlian/include
CFLAGS		=  -Wall -Wextra -Werror #-fsanitize=address -g #-ggdb3#-lreadline  
RD			= ${shell find ${HOME} -name readlian 2>/dev/null}
RM			= rm -f
CC			= cc
LINKER		= -L./readlian/lib -lreadline

all: $(NAME)

%.o : %.c readline minishel.h Makefile
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

$(NAME) : $(OBJS)
		@echo "\n\t\t\033[0;32mCompiling minishell"
		$(CC) $(CFLAGS) -I $(INCLUDES) $(LINKER) $(OBJS) -o $(NAME)  -lreadline
		@echo "\n\t\t\033[0;32mDone !"

clean	:
		@echo "\n\t\t\033[0;31mCleaning"
		$(RM) $(OBJS)

fclean	: 	clean
			@echo "\n\t\t\033[0;31mRemoving"
			$(RM) $(NAME)  

install:
	cd readline-master && make clean && ./configure --prefix=${RD} && make && make install



re		:fclean all

.PHONY: all clean fclean re