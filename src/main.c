/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:38:46 by ttsubo            #+#    #+#             */
/*   Updated: 2025/02/10 14:26:20 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_game *game, t_vec d_vec)
{
	t_vec	p_mv;
	t_vec	p;

	p = game->data.player;
	p_mv.x = p.x + d_vec.x;
	p_mv.y = p.y + d_vec.y;
	if (game->data.map[p_mv.y][p_mv.x] == '1')
		return ;
	if (game->data.map[p_mv.y][p_mv.x] == 'C')
		game->data.coin--;
	if (game->data.map[p_mv.y][p_mv.x] == 'E')
	{
		if (game->data.coin == 0)
			game->data.is_clear = true;
		else
			return ;
	}
	game->data.map[p.y][p.x] = '0';
	game->data.map[p_mv.y][p_mv.x] = 'P';
	game->data.player = p_mv;
}

/**
 * @brief 現在のマップを描画します。
 *
 * @param game
 * @return int
 * @note TODO マップサイズは決め打ちです
 */
int	draw(t_game *game)
{
	t_vec	i;
	t_vec	map_size;
	char	out[2];

	mlx_clear_window(game->sys.mlx, game->sys.win);
	i = (t_vec){.y = 0, .x = 0};
	map_size = (t_vec){.y = 5, .x = 6};
	while (i.y < map_size.y)
	{
		while (i.x < map_size.x)
		{
			out[0] = game->data.map[i.y][i.x];
			out[1] = '\0';
			mlx_string_put(game->sys.mlx, game->sys.win, i.x * 8, i.y * 16 + 12,
				0xFFFFFF, out);
			i.x++;
		}
		i.x = 0;
		i.y++;
	}
	return (0);
}

int	update(t_game *game)
{
	if (game->sys.key_ctrl.exit)
		game->func.exit(game);
	else if (game->sys.key_ctrl.reset)
		game->func.reset(game);
	else if (game->sys.key_ctrl.up)
		move(game, (t_vec){.x = 0, .y = -1});
	else if (game->sys.key_ctrl.down)
		move(game, (t_vec){.x = 0, .y = 1});
	else if (game->sys.key_ctrl.left)
		move(game, (t_vec){.x = -1, .y = 0});
	else if (game->sys.key_ctrl.right)
		move(game, (t_vec){.x = 1, .y = 0});
	return (0);
}

int	game_loop(t_game *game)
{
	draw(game);
	update(game);
	return (0);
}

void	app(void)
{
	t_game	*game;

	ft_printf("DEBUG app start\n");
	char map[5][6] = {
		{'1', '1', '1', '1', '1', '1'},
		{'1', '0', '0', 'C', '0', '1'},
		{'1', 'P', '0', '0', 'E', '1'},
		{'1', '0', 'C', '0', '0', '1'},
		{'1', '1', '1', '1', '1', '1'},
	};
	game = game_init("so_long_M1", (t_vec){.x = 400, .y = 400}, map);
	mlx_loop_hook(game->sys.mlx, game_loop, game);
	mlx_hook(game->sys.win, 2, 1L << 0, key_press, game);
	mlx_hook(game->sys.win, 3, 1L << 1, key_rel, game);
	mlx_loop(game->sys.mlx);
	ft_printf("DEBUG app end\n");
}

int	main(int argc, char **argv)
{
	(void)	argc;
	(void)	argv;
	app();
	return (0);
}