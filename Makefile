# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prastoin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/07 11:13:09 by prastoin          #+#    #+#              #
#    Updated: 2019/01/11 13:16:31 by prastoin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ls

SRC = main.c tools.c zeroac.c just_files.c data.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

LIB = libft/libft.a

INC = -I./libft/

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
		gcc $(FLAG) $(LIB) $(LIB2) $(INC) $(OBJ) $(LIBX) -o $(NAME)

$(LIB):
		make -C libft/ fclean
			make -C ./libft/

%.o: %.c
		gcc $(FLAG) $(INC) -o $@ -c $<

clean:
		make -C libft/ clean
			rm -rf $(OBJ)

fclean: clean
		make -C libft/ fclean
			rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
