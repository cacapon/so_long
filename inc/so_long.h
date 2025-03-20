/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:50:14 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/20 19:32:57 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "error.h"
# include "glx.h"
# include <fcntl.h>

typedef struct s_sl_vec
{
	int			x;
	int			y;
}				t_sl_vec;

typedef struct s_sl_result
{
	bool		sts;
	t_err_code	e_code;
}				t_sl_result;

typedef struct s_map
{
	char		*data;
	int			w;
	int			h;
	int			items;
}				t_map;

typedef struct s_sl_path
{
	t_map		map;
	bool		*queue;
	int			item_c;
	int			exit_c;
}				t_sl_path;

typedef struct s_game_data
{
	t_map		*map;
	t_pos		p_pos;
	int			coin;
	int			count;
	bool		is_clear;
}				t_game_data;

int				get_elem_count(t_map map, char elem);
t_sl_result		get_map(char *map_path, char **map);
t_sl_result		is_valid_data(t_map map);
t_sl_result		is_valid_map_count(t_map map);
t_sl_result		init_map_size(t_map **map);
t_sl_result		is_arround_wall(t_map map);
t_sl_result		path_check(t_map map);

#endif