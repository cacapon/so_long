/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:32:26 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/20 20:07:13 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_vec	get_player_index(t_map map)
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

int	get_elem_count(t_map map, char elem)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!map.data || map.data[i] == '\0')
		return (0);
	while (map.data[i])
	{
		if (map.data[i] == elem)
			count++;
		i++;
	}
	return (count);
}
