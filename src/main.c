/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:38:46 by ttsubo            #+#    #+#             */
/*   Updated: 2025/02/03 12:31:38 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_game *self, t_vec d_vec)
{
	t_vec	p_mv;

	p_mv.x = self->player.x + d_vec.x;
	p_mv.y = self->player.y + d_vec.y;
	if (self->map[p_mv.y][p_mv.x] == '1')
		return ;
	if (self->map[p_mv.y][p_mv.x] == 'C')
		self->coin--;
	if (self->map[p_mv.y][p_mv.x] == 'E')
	{
		if (self->coin == 0)
			self->is_clear = true;
		else
			return ;
	}
	self->map[self->player.y][self->player.x] = '0';
	self->map[p_mv.y][p_mv.x] = 'P';
	self->player = p_mv;
}

int	update(int keycode, t_game *game)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
		exit(0);
	if (keycode == KEY_UP || keycode == KEY_W)
		move(game, (t_vec){.x = 0, .y = -1});
	if (keycode == KEY_DOWN || keycode == KEY_S)
		move(game, (t_vec){.x = 0, .y = 1});
	if (keycode == KEY_LEFT || keycode == KEY_A)
		move(game, (t_vec){.x = -1, .y = 0});
	if (keycode == KEY_RIGHT || keycode == KEY_D)
		move(game, (t_vec){.x = 1, .y = 0});

}

void	app(void)
{
	t_game	*game;
	void	*mlx;
	void	*win;
	char	map[5][6] = {
		{'1', '1', '1', '1', '1', '1'},
		{'1', '0', '0', 'C', '0', '1'},
		{'1', 'P', '0', '0', 'E', '1'},
		{'1', '0', 'C', '0', '0', '1'},
		{'1', '1', '1', '1', '1', '1'},
	};
	game = ft_calloc(1, sizeof(t_game));
	game->count = 0;
	game->coin = 2;
	game->player = (t_vec){.y = 2, .x = 1};
	game->is_clear = false;
	game->map = map;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 100, 100, "so_long_M1");
	mlx_key_hook(win, update, game);
	mlx_loop(mlx);

}

int	main(int argc, char **argv)
{
	app();
}