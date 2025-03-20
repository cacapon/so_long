/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:50:14 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/20 15:14:57 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "error.h"
# include "glx.h"
# include <fcntl.h>

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
}				t_map;

typedef struct s_game_data
{
	t_map		*map;
	t_pos		p_pos;
	int			coin;
	int			count;
	bool		is_clear;
}				t_game_data;

t_sl_result		get_map(char *map_path, char *map);
bool			is_valid_data(t_map map);
t_err_code		is_valid_map_count(t_map map);

#endif