# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 12:00:31 by ttsubo            #+#    #+#              #
#    Updated: 2025/03/20 12:36:55 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=so_long
CC		=cc
W_FLG	=-Wall -Wextra -Werror

INC_PTH	=inc/
GLX_PTH =lib/glx/
SRC_PTH =src/
TST_PTH =tests/
BLD_PTH =build/

GLX		=libglx.a
GLX_H	=glx.h

I_FLG	=-I$(INC_PTH) -I$(GLX_PTH)
L_FLG	=-lX11 -lXext

SRC 	=main.c error.c

SRCS = $(addprefix $(SRC_PTH), $(SRC))
OBJS = $(addprefix $(BLD_PTH), $(SRC:.c=.o))

T_SRC	= test_error.c
T_SRCS	= $(addprefix $(TST_PTH), $(T_SRC))
T_OUT	= $(addprefix $(TST_PTH), $(T_SRC:.c=.out))

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
	rm -rf $(TST_PTH)*.out
	$(MAKE) -C $(GLX_PTH) $@

re: fclean all

# tests
test: $(T_OUT)
	@echo "Running tests..."
	@for test_bin in $(T_OUT); do \
		echo "Exec $$test_bin"; \
		./$$test_bin; \
	done

$(TST_PTH)%.out: $(TST_PTH)%.c $(GLX_PTH)$(GLX)
	@echo "Compiling test: $<"
	@src_file=$(SRC_PTH)$(patsubst test_%,%,$(notdir $<)); \
	echo "Looking for corresponding source file: $$src_file"; \
	if [ -f $$src_file ]; then \
		echo "Compiling with source: $$src_file"; \
		$(CC) $(W_FLG) $< $$src_file $(GLX_PTH)$(GLX) $(I_FLG) -o $@; \
	else \
		echo "Error: Matching source file $$src_file not found" >&2; \
		exit 1; \
	fi

.PHONE: all clean fclean re test