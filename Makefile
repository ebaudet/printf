# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/21 21:38:26 by ebaudet           #+#    #+#              #
#    Updated: 2019/01/23 21:02:30 by ebaudet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
SRCS	= ft_printf.c put.c
OBJS	= ${SRCS:%.c=.obj/%.o}
INC		= ./includes/ -I ./libft/includes
LIB		=  -L libft -lft
FLAGS	 = -Wall -Wextra -Werror -fno-builtin -fno-stack-protector -pedantic -ansi
FLAGS_LESS = -Wall -Wextra -Werror
DEBUGFLG = -v -da -Q
CC		= gcc
AR		= ar rc
RANLIB	= ranlib

all: $(NAME)

$(NAME): make_libft $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@$(RANLIB) $(NAME)
	@echo "\n\n > Compilation \033[36mlibftprintf.a\033[m [\033[32mDONE\033[m]"

.obj/%.o: %.c
	@mkdir -p .obj
	@$(CC) -c $< -o $@ $(FLAGS_LESS) -I $(INC)
	@echo -n .

make_libft:
	@echo "Compilation de la libft :"
	@make -C libft

clean:
	@rm -rf .obj
	make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@rm -f test
	make -C libft fclean
	@echo "fclean : [\033[32mDONE\033[m]"

re: fclean all

test: all
	@cc $(FLAGS_LESS) main.c -o test -I $(INC) $(LIB) -L . libftprintf.a
	@echo "\n > \033[36mtest\033[m compilation [\033[32mDONE\033[m]\n"

file_right:
	@chmod -R +rw . includes/
	@echo "\n\n > apply correct right [\033[32mDONE\033[m]"

.PHONY: all clean fclean re test file_right
