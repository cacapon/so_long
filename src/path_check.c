/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:45:41 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/21 00:37:36 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	_free_path_s(t_sl_path *path_s)
{
	free(path_s->queue);
	free(path_s);
}

void	path_check_rec(t_sl_path *path_s, t_sl_vec pos)
{
	int	i;

	i = pos.x + pos.y + (path_s->map.w * pos.y);
	if (path_s->queue[i] == true)
		return ;
	if (path_s->map.data[i] == '1')
		return ;
	if (pos.x < 0 || path_s->map.w <= pos.x)
		return ;
	if (pos.y < 0 || path_s->map.h <= pos.y)
		return ;
	path_s->queue[i] = true;
	if (path_s->map.data[i] == 'C')
		path_s->item_c++;
	if (path_s->map.data[i] == 'E')
	{
		path_s->exit_c++;
		return ;
	}
	path_check_rec(path_s, (t_sl_vec){pos.x + 1, pos.y});
	path_check_rec(path_s, (t_sl_vec){pos.x - 1, pos.y});
	path_check_rec(path_s, (t_sl_vec){pos.x, pos.y + 1});
	path_check_rec(path_s, (t_sl_vec){pos.x, pos.y - 1});
}

t_sl_result	path_check(t_map map)
{
	t_sl_path	*path_s;
	t_sl_vec	pos;
	bool		*q;

	q = ft_calloc(map.h * map.w, sizeof(t_sl_vec));
	path_s = ft_calloc(1, sizeof(t_sl_path));
	if (!q || !path_s)
		return ((t_sl_result){false, GEN_002});
	*path_s = (t_sl_path){.exit_c = 0, .item_c = 0, .map = map, .queue = q};
	pos = get_player_index(map);
	path_check_rec(path_s, pos);
	if (map.items != path_s->item_c)
		return (_free_path_s(path_s), (t_sl_result){false, ITM_001});
	if (path_s->exit_c == 0)
		return (_free_path_s(path_s), (t_sl_result){false, MAP_002});
	_free_path_s(path_s);
	return ((t_sl_result){true, NO_ERR});
}
