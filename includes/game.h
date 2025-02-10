/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:50:02 by ttsubo            #+#    #+#             */
/*   Updated: 2025/02/10 12:04:54 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <stdbool.h>
# include <stddef.h>

typedef struct s_game	t_game;

typedef struct s_key_ctrl
{
	bool				up;
	bool				down;
	bool				left;
	bool				right;
	bool				reset;
	bool				exit;
}						t_key_ctrl;

typedef struct s_vec
{
	int					x;
	int					y;
}						t_vec;

typedef struct s_sys
{
	void				*mlx;
	void				*win;
	t_key_ctrl			key_ctrl;
}						t_sys;

typedef struct s_data
{
	char (*map)[6];
	int					count;
	int					coin;
	t_vec				player;
	bool				is_clear;
}						t_data;

typedef struct s_func
{
	void				(*exit)(t_game *self);
	void				(*reset)(t_game *self);
}						t_func;

typedef struct s_game
{
	t_sys				sys;
	t_data				data;
	t_func				func;
}						t_game;

t_game					*game_init(char *title, t_vec size, char *map[]);
void					game_exit(t_game *self);
void					game_reset(t_game *self);

#endif