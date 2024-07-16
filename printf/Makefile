# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/28 18:28:42 by hdelbecq          #+#    #+#              #
#    Updated: 2024/04/28 18:28:45 by hdelbecq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

AR = @ar -rsc

RM = rm -f

SRC =  ft_putnbr_base.c ft_putstr.c ft_putchar.c ft_strlen.c ft_printf.c

SRCSALL = ${SRC} ${SRCB}

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	
$(OBJ) :
	@$(CC) $(CFLAGS) -c $(@:.o=.c) 

clean : 
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
