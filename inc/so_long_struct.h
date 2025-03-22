/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:51:47 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/22 17:21:40 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCT_H
# define SO_LONG_STRUCT_H

# include "so_long_define.h"
# include <stdbool.h>

typedef struct s_util_index
{
	int			i;
	int			j;
	int			k;
}				t_util_index;

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
	t_sl_vec	p_pos;
	int			has_items;
	int			count;
	bool		is_clear;
	char		count_s[12];
}				t_game_data;

#endif