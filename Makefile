# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 12:00:31 by ttsubo            #+#    #+#              #
#    Updated: 2025/03/19 18:19:54 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=so_long
CC		=cc
W_FLG	=-Wall -Wextra -Werror

INC_PTH	=inc/
GLX_PTH =lib/glx/
SRC_PTH =src/
BLD_PTH =build/

GLX		=libglx.a
GLX_H	=glx.h

I_FLG	=-I$(INC_PTH) -I$(GLX_PTH)
L_FLG	=-lX11 -lXext

SRC 	=main.c error.c

SRCS = $(addprefix $(SRC_PTH), $(SRC))
OBJS = $(addprefix $(BLD_PTH), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) $(GLX_PTH)$(GLX)
	$(CC) $(W_FLG) $^ $(L_FLG) -o $@

$(GLX_PTH)$(GLX): $(GLX_PTH)$(GLX_H)
	$(MAKE) -C $(GLX_PTH)

$(BLD_PTH)%.o: $(SRC_PTH)%.c
	$(CC) $(W_FLG) $^ -c $(I_FLG) -o $@

$(GLX_PTH)$(GLX_H):
	git submodule update -i --recursive

clean:
	rm -rf $(BLD_PTH)*.o
	$(MAKE) -C $(GLX_PTH) $@

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(GLX_PTH) $@

re: fclean all

.PHONE: all clean fclean re