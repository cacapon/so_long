/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:48:48 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/20 21:51:02 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	clean(void *param)
{
	t_game_data	*data;

	data = param;
	free(data->map->data);
	free(data->map);
	free(data);
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
	glx = glx_init("so_long", 800, 500, 1000);
	set_texture();
	glx->hook(update, draw, clean);
	glx->run(data);
	return (0);
}
