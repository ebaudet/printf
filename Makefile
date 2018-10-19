# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/21 21:38:26 by ebaudet           #+#    #+#              #
#    Updated: 2013/12/21 21:38:26 by ebaudet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
SRCS	= ft_printf.c\
		ft_atoi.c\
		ft_itoa.c\
		ft_putchar.c\
		ft_strcpy.c\
		ft_strlen.c\
		ft_strdup.c\
		ft_lutohex.c
OBJS	= ${SRCS:.c=.o}
INC		= ./includes/
FLAGS	 = -Wall -Wextra -Werror -fno-builtin -fno-stack-protector -pedantic -ansi
FLAGS_LESS = -Wall -Wextra -Werror
DEBUGFLG = -v -da -Q
CC		= gcc
AR		= ar rc
RANLIB	= ranlib

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@$(RANLIB) $(NAME)
	@echo "\n\n > Compilation \033[36mlibftprintf.a\033[m [\033[32mDONE\033[m]"

%.o: %.c
	@$(CC) -c $< -o $@ $(FLAGS_LESS) -I $(INC)
	@echo -n .

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@echo "fclean : [\033[32mDONE\033[m]"

re: fclean all

test: re
	@cc $(FLAGS_LESS) main.c -o test -I $(INC) -L libftprintf libftprintf.a
	@echo "\n > \033[36mtest\033[m compilation [\033[32mDONE\033[m]\n"

file_right:
	@chmod -R +rw . includes/
	@echo "\n\n > apply correct right [\033[32mDONE\033[m]"

.PHONY: all clean fclean re test file_right
