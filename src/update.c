/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:24:19 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/20 20:35:20 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	_is_not_move(t_sl_vec p_mv, t_map *map, int mv_i)
{
	if (p_mv.x < 0 || p_mv.x >= map->w)
		return (true);
	if (p_mv.y < 0 || p_mv.y >= map->h)
		return (true);
	if (map->data[mv_i] == '1')
		return (true);
	return (false);
}

static void	move(t_game_data *data, t_sl_vec mv)
{
	int			i;
	int			mv_i;
	t_sl_vec	p_mv;

	p_mv = (t_sl_vec){data->p_pos.x + mv.x, data->p_pos.y + mv.y};
	i = data->p_pos.x + data->p_pos.y + (data->p_pos.y * data->map->w);
	mv_i = p_mv.x + p_mv.y + (p_mv.y * data->map->w);
	if (_is_not_move(p_mv, data->map, mv_i))
		return ;
	if (data->map->data[mv_i] == 'C')
		data->has_items++;
	if (data->map->data[mv_i] == 'E')
	{
		if (data->map->items == data->has_items)
			data->is_clear = true;
		else
			return ;
	}
	data->map->data[i] = '0';
	data->map->data[mv_i] = 'P';
	data->p_pos = p_mv;
	data->count++;
	ft_printf("move:%d\n", data->count);
}

int	update(void *param)
{
	t_game_data	*data;
	t_glx		*glx;

	(void)data;
	data = (t_game_data *)param;
	glx = get_glx();
	if (data->is_clear)
		glx->quit(0);
	if (glx->btnp(XK_Escape))
		glx->quit(EXIT_SUCCESS);
	if (glx->btnp(XK_w))
		move(data, (t_sl_vec){0, -1});
	if (glx->btnp(XK_a))
		move(data, (t_sl_vec){-1, 0});
	if (glx->btnp(XK_s))
		move(data, (t_sl_vec){0, 1});
	if (glx->btnp(XK_d))
		move(data, (t_sl_vec){1, 0});
	return (0);
}
