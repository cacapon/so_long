/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:48:48 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/22 17:49:12 by ttsubo           ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_glx		*glx;
	t_game_data	*data;

	if (check(is_file_validate(ac, av[1])))
		return (1);
	data = game_data_init();
	if (check(is_valid_game_data(data))
		|| check(load_map(av[1], &data->map->data))
		|| check(init_map_size(&(data->map)))
		|| check(is_valid_data(*data->map))
		|| check(is_valid_map_count(*data->map))
		|| check(is_arround_wall(*data->map)))
		return (game_data_dest(data), 1);
	data->p_pos = get_player_index(*data->map);
	data->map->items = get_elem_count(*data->map, 'C');
	if (check(path_check(*data->map)))
		return (game_data_dest(data), 1);
	glx = glx_init("so_long", 550, 500, 1000);
	set_texture();
	glx->hook(update, draw, clean);
	glx->run(data);
	return (0);
}
