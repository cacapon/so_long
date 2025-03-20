/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:48:48 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/20 13:11:20 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw(void *param)
{
	t_game_data	*data;
	t_glx		*glx;
	t_pos		draw_pos;
	int			i;

	glx = get_glx();
	data = (t_game_data *)param;
	draw_pos = (t_pos){.x=0, .y=0};
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
			continue;
		}
		i++;
		draw_pos.x += 16;
	}
	glx->text("so_long", (t_pos){250, 16}, GLX_COLOR_MINT_GREEN);
	return (0);
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
	return (0);
}

int	clean(void *param)
{
	free(param);
	return (0);
}

void	set_texture(void)
{
	t_glx		*glx;

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

	(void)ac;
	data = ft_calloc(1, sizeof(t_data));
	data->map = ft_calloc(1, sizeof(t_map));
	data->map->data = get_map(av[1]);
	glx = glx_init("so_long", 500, 500, 1000);
	set_texture();
	glx->hook(update, draw, clean);
	glx->run(data);
	return (0);
}
