##
## EPITECH PROJECT, 2019
## PSU_minishell1_2018
## File description:
## __Makefile__
##

CC	=	@gcc -g3 -O3

MAKEFLAGS	+=	--no-print-directory

RM	=	rm -f

ECHO		=	/bin/echo -e
DEFAULT		=	"\033[00m"
GREEN		=	"\033[1;32m"
YELLOW		=	"\033[0;01;033m"
TEAL		=	"\033[1;01;35m"
RED			=	"\033[1;01;31m"

CFLAGS	+=	-I./include

NAME	=	lem_in

SRC		=	src/main.c

LINK	=	src/link/size_list.c		\
			src/link/found_start_end.c	\
			src/link/create_link.c		\
			src/link/laps_counter.c		\
			src/link/moove_ant.c		\
			src/link/moove_on_tree.c	\
			src/link/link_create.c

DEST	=	src/destroy/destroy.c

SORT	=	src/sort/sort.c

LIB		=	src/mini_lib/my_str_to_word_array.c		\
			src/mini_lib/init_game_board.c			\
			src/mini_lib/get_next_line.c			\
			src/mini_lib/lib_functions.c			\
			src/mini_lib/to_tab_link.c				\
			src/mini_lib/print_function.c

DISP	=	src/display/print_answer.c	\
			src/display/display_moove.c

HAND	=	src/handling/handling.c

SRCS	=	$(SRC)	\
			$(LINK)	\
			$(DEST)	\
			$(SORT)	\
			$(LIB)	\
			$(DISP)	\
			$(HAND)

OBJS	=	$(SRCS:.c=.o)

all		:	title $(NAME) endt
			@echo ""

title		:
			@$(ECHO) $(YELLOW)"\n → Projet : Lem-in\n" $(DEFAULT)

endt:
			@$(ECHO) $(RED)"\n → [LEM-IN CREATE]\n" $(DEFAULT)

$(NAME)		:	$(OBJS)
			@$(CC) $(OBJS) -o $(NAME) $(CFLAGS) &&			\
			$(ECHO) $(GREEN) "[OK]" $(TEAL) $(NAME) $(DEFAULT) ||	\
			$(ECHO) $(RED) "[KO]" $(TEAL) $(NAME) $(DEFAULT)
			@make clean

.c.o		:
			@$(CC) $(CFLAGS) -c $< -o $@ &&				\
			$(ECHO) $(GREEN) "[OK]" $(TEAL) $< $(DEFAULT) ||	\
			$(ECHO) $(RED) "[KO]" $(TEAL) $< $(DEFAULT)

tests_run	:
			make -C./tests/ all

clean:
			@$(RM) $(OBJS)

fclean:			clean
			@$(RM) $(NAME)

re		:	fclean all

.PHONY	: all clean fclean re
