/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:45:41 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/20 18:01:46 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_sl_vec	_get_player_index(t_map map)
{
	t_sl_vec	pos;
	int			i;

	pos = (t_sl_vec){0, 0};
	i = pos.x + pos.y + (pos.y * map.w);
	while (map.data[i])
	{
		i = pos.x + pos.y + (pos.y * map.w);
		if (map.data[i] == 'P')
			return (pos);
		if (pos.x == map.w - 1)
		{
			pos = (t_sl_vec){0, pos.y + 1};
			continue ;
		}
		pos.x++;
	}
	return ((t_sl_vec){-1, -1});
}

// void	path_check_rec(t_map map, t_sl_vec pos)
// {
	// int	index;
// }

t_sl_result	path_check(t_map map)
{
	t_sl_vec pos;
	pos = _get_player_index(map);
	ft_printf("(%d,%d)\n", pos.x, pos.y);
	return ((t_sl_result){true, NO_ERR});
}