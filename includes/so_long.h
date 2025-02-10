/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:50:14 by ttsubo            #+#    #+#             */
/*   Updated: 2025/02/03 12:26:17 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_result.h"
# include "libft.h"
# include "mlx.h"
# include <stdbool.h>
# include <stddef.h>
# include <X11/keysym.h>

typedef struct s_game	t_game;

typedef enum e_err_code
{
	GEN_000,
	GEN_001,
	ITM_000,
	ITM_001,
	MAP_000,
	MAP_001,
	MAP_002,
	MAP_003,
	MAP_004,
	MAP_005,
}						t_err_code;

typedef enum e_keycode
{
	KEY_Q = XK_q,
	KEY_ESC = XK_Escape,
	KEY_W = XK_w,
	KEY_S = XK_s,
	KEY_A = XK_a,
	KEY_D = XK_d,
	KEY_R = XK_r,
	KEY_UP = XK_Up,
	KEY_DOWN = XK_Down,
	KEY_LEFT = XK_Left,
	KEY_RIGHT = XK_Right,
}						t_keycode;

typedef struct e_vec
{
	int					x;
	int					y;
}						t_vec;

typedef struct s_game
{
	char				(*map)[6];
	int					count;
	int					coin;
	t_vec				player;
	bool				is_clear;
	void				(*draw)(t_game *self);
	void				(*update)(t_game *self);

}						t_game;

void					input(t_game *self);
void					draw(t_game *self);
void					update(t_game *self);

#endif