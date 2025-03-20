/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:50:14 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/20 13:12:55 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "error.h"
# include "ft_result.h"
# include "glx.h"
# include <fcntl.h>

typedef struct s_map
{
	char	*data;
	int		w;
	int		h;
}			t_map;

typedef struct s_game_data
{
	t_map	*map;
	t_pos	p_pos;
	int		coin;
	int		count;
	bool	is_clear;
}			t_game_data;

char		*get_map(char *map_path);

#endif