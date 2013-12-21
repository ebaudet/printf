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

NAME	= ft_printf
SRC		= main.c\
		  ft_printf.c
PATH_OBJ = obj
PATH_SRC = srcs
OBJS	= $(patsubst %.c, $(PATH_OBJ)/%.o, $(SRC))
SRCS	= $(patsubst %.c, $(PATH_SRC)/%.c, $(SRC))
INC		= ./includes/
FLAGS	= -Wall


all: $(NAME)

$(NAME): $(OBJS)
	gcc $(FLAGS) $(SRCS) -o $(NAME) -I includes
$(PATH_OBJ)/%.o: $(addprefix $(PATH_SRC)/, %.c)
	gcc -c $< -o $@ $(FLAGS) -I$(INC)
gdb:
	cc -g $(FLAGS) $(SRCS) -o $(NAME) -I includes
	gdb $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
