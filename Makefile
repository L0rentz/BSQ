##
## EPITECH PROJECT, 2019
## bsq
## File description:
## makefile
##

NAME	=	bsq

SRCS	=	algo_bsq.c \
		count_cols_and_check.c \
		get_number_first_line.c \
		load_file_in_mem.c \
		main.c \

OBJS	=	$(SRCS:.c=.o)

CFLAGS = 	-Wall -Werror -Wextra

all:	$(NAME)

$(NAME):	$(OBJS) $(SRCS)
		gcc -o $(NAME) $(OBJS)

clean:
		rm algo_bsq.o
		rm count_cols_and_check.o
		rm get_number_first_line.o
		rm load_file_in_mem.o
		rm main.o

fclean:
		rm $(NAME)
		rm algo_bsq.o
		rm count_cols_and_check.o
		rm get_number_first_line.o
		rm load_file_in_mem.o
		rm main.o

re: fclean all
