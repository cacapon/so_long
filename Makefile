# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 13:58:16 by ttsubo            #+#    #+#              #
#    Updated: 2025/02/10 15:16:16 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# args
NAME	= so_long
CC		= cc -Wall -Wextra -Werror

INC_PTH	= includes/
FT_PTH	= lib/libft/
MLX_PTH = lib/minilibx-linux/
SRC_PTH = src/
BLD_PTH = build/

MLX_A	= $(MLX_PTH)/libmlx.a
FT_A	= $(FT_PTH)/libft.a

I_FLG	= -I$(INC_PTH) -I$(MLX_PTH) -I$(FT_PTH)
L_FLG	= -L$(MLX_PTH) -L$(FT_PTH)
l_FLG	= -lmlx -lft -lX11 -lXext

SRC		= main.c key_input.c game.c error.c
SRCS 	= $(addprefix $(SRC_PTH), $(SRC))
OBJS	= $(addprefix $(BLD_PTH), $(SRCS:.c=.o))

# rules
all: submodule $(FT_A) $(MLX_A) $(NAME)

submodule:
	@if [ -z "$(shell find $(FT_PTH) -type f 2>/dev/null)" ] || \
	     [ -z "$(shell find $(MLX_PTH) -type f 2>/dev/null)" ]; then \
		echo "Initializing git submodules..."; \
		git submodule update --init; \
	fi

$(FT_A):
	make -C $(FT_PTH)

$(MLX_A):
	make -C $(MLX_PTH)

$(NAME): $(OBJS)
	@if [ -z "$(shell find $(FT_PTH) -type f 2>/dev/null)" ] || \
	    [ -z "$(shell find $(MLX_PTH) -type f 2>/dev/null)" ]; then \
		echo "Initializing git submodules..."; \
		git submodule update --init; \
	fi
	@if [ ! -f $(FT_A) ]; then make -C $(FT_PTH); fi
	@if [ ! -f $(MLX_A) ]; then make -C $(MLX_PTH); fi
	$(CC) $(OBJS) -o $@ $(L_FLG) $(l_FLG)

$(BLD_PTH)%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@ $(I_FLG)

clean:
	@echo "clean object"
	rm -rf $(BLD_PTH)
	@$(MAKE) -C $(FT_PTH) clean
	@echo "clean object done"

fclean: clean
	rm -rf $(NAME)
	@$(MAKE) -C $(FT_PTH) fclean
	@$(MAKE) -C $(MLX_PTH) clean

re: fclean all

.PHONY: all init fclean re submodule