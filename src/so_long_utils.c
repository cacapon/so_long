/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:32:26 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/20 21:36:45 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_utoa(unsigned int num, char *str)
{
	t_util_index	index;
	char			temp;

	index.i = 0;
	if (num == 0)
	{
		str[index.i++] = '0';
		str[index.i] = '\0';
		return ;
	}
	while (num > 0)
	{
		str[index.i++] = (num % 10) + '0';
		num /= 10;
	}
	str[index.i] = '\0';
	index = (t_util_index){.i = index.i, .j = 0, .k = index.i - 1};
	while (index.j < index.k)
	{
		temp = str[index.j];
		str[index.j++] = str[index.k];
		str[index.k--] = temp;
	}
}

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
