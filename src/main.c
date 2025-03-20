/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:48:48 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/20 20:09:52 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// TODO: TOO_MANY_LINES
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
		if (data->map->data[i] == '0')
			glx->put_img(0, draw_pos);
		if (data->map->data[i] == '1')
			glx->put_img(1, draw_pos);
		if (data->map->data[i] == 'C')
			glx->put_img(2, draw_pos);
		if (data->map->data[i] == 'E')
			glx->put_img(3, draw_pos);
		if (data->map->data[i] == 'P')
			glx->put_img(4, draw_pos);
		if (data->map->data[i] == '\n')
		{
			draw_pos.y += 16;
			draw_pos.x = 0;
			i++;
			continue ;
		}
		i++;
		draw_pos.x += 16;
	}
	glx->text("so_long", (t_pos){250, 16}, GLX_COLOR_MINT_GREEN);
	return (0);
}

void	move(t_game_data *data, t_sl_vec mv)
{
	int			i;
	int			mv_i;
	t_sl_vec	p_mv;

	p_mv = (t_sl_vec){data->p_pos.x + mv.x, data->p_pos.y + mv.y};
	if (p_mv.x < 0 || p_mv.x >= data->map->w || p_mv.y < 0
		|| p_mv.y >= data->map->h)
		return ;
	i = data->p_pos.x + data->p_pos.y + (data->p_pos.y * data->map->w);
	mv_i = p_mv.x + p_mv.y + (p_mv.y * data->map->w);
	if (data->map->data[mv_i] == '1')
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
}

int	update(void *param)
{
	t_game_data	*data;
	t_glx		*glx;

	(void)data;
	data = (t_game_data *)param;
	glx = get_glx();
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

int	clean(void *param)
{
	free(param);
	return (0);
}

void	set_texture(void)
{
	t_glx	*glx;

	glx = get_glx();
	glx->load_img("texture/0.xpm", 16, 16);
	glx->load_img("texture/1.xpm", 16, 16);
	glx->load_img("texture/c.xpm", 16, 16);
	glx->load_img("texture/e.xpm", 16, 16);
	glx->load_img("texture/p.xpm", 16, 16);
}

int	check(t_sl_result result)
{
	if (!result.sts)
	{
		show_error(result.e_code);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_glx		*glx;
	t_game_data	*data;

	(void)ac;
	data = ft_calloc(1, sizeof(t_game_data));
	data->map = ft_calloc(1, sizeof(t_map));
	if (check(get_map(av[1], &data->map->data)))
		return (1);
	if (check(init_map_size(&(data->map))))
		return (1);
	if (check(is_valid_data(*data->map)))
		return (1);
	if (check(is_valid_map_count(*data->map)))
		return (1);
	if (check(is_arround_wall(*data->map)))
		return (1);
	data->p_pos = get_player_index(*data->map);
	data->map->items = get_elem_count(*data->map, 'C');
	if (check(path_check(*data->map)))
		return (1);
	glx = glx_init("so_long", 500, 500, 1000);
	set_texture();
	glx->hook(update, draw, clean);
	glx->run(data);
	return (0);
}
