/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:36:25 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/20 20:50:43 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	_put_map_img(char data, t_pos draw_pos)
{
	t_glx	*glx;

	glx = get_glx();
	if (data == '0')
		glx->put_img(0, draw_pos);
	if (data == '1')
		glx->put_img(1, draw_pos);
	if (data == 'C')
		glx->put_img(2, draw_pos);
	if (data == 'E')
		glx->put_img(3, draw_pos);
	if (data == 'P')
		glx->put_img(4, draw_pos);
}

static bool	_new_line_draw_pos(char data, t_pos *draw_pos, int *i)
{
	if (data == '\n')
	{
		draw_pos->y += 16;
		draw_pos->x = 0;
		(*i)++;
		return (true);
	}
	return (false);
}

int	draw(void *param)
{
	t_game_data	*data;
	t_glx		*glx;
	t_pos		draw_pos;
	int			i;

	glx = get_glx();
	data = (t_game_data *)param;
	draw_pos = (t_pos){.x = 0, .y = 32};
	glx->cls();
	i = 0;
	while (data->map->data[i])
	{
		_put_map_img(data->map->data[i], draw_pos);
		if (_new_line_draw_pos(data->map->data[i], &draw_pos, &i))
			continue ;
		i++;
		draw_pos.x += 16;
	}
	glx->text("move:", (t_pos){16, 16}, GLX_COLOR_CORN_FLOWER_BLUE);
	glx->text(ft_itoa(data->count), (t_pos){48, 16},
		GLX_COLOR_CORN_FLOWER_BLUE);
	glx->text("so_long", (t_pos){250, 16}, GLX_COLOR_MINT_GREEN);
	return (0);
}
