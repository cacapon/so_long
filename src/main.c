/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:48:48 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/19 18:22:33 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw(void *param)
{
	t_game_data	*data;
	t_glx		*glx;

	(void)data;
	glx = get_glx();
	data = (t_game_data *)param;
	glx->cls();
	glx->text("so_long", (t_pos){250, 250}, GLX_COLOR_MINT_GREEN);
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
	(void)param;
	return (0);
}

int	main(int ac, char **av)
{
	t_glx		*glx;
	t_game_data	*data;

	(void)ac;
	(void)av;
	data = ft_calloc(1, sizeof(t_data));
	glx = glx_init("so_long", 500, 500, 1000);
	glx->hook(update, draw, clean);
	glx->run(data);
	return (0);
}
