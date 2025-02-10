/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:38:46 by ttsubo            #+#    #+#             */
/*   Updated: 2025/02/10 16:11:48 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



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
	mlx_string_put(game->sys.mlx, game->sys.win, 0, 100, 0xFFFFFF,
		ft_itoa(game->sys.timer));
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
	if (game->data.is_p_state)
		if 
	if (game->data.is_move)
	{
		if (game->sys.key_ctrl.up && game->sys.timer % WAIT_TIME == 1)
			move(game, (t_vec){.x = 0, .y = -1});
		else if (game->sys.key_ctrl.down && game->sys.timer % WAIT_TIME == 1)
			move(game, (t_vec){.x = 0, .y = 1});
		else if (game->sys.key_ctrl.left && game->sys.timer % WAIT_TIME == 1)
			move(game, (t_vec){.x = -1, .y = 0});
		else if (game->sys.key_ctrl.right && game->sys.timer % WAIT_TIME == 1)
			move(game, (t_vec){.x = 1, .y = 0});
	}
	else
	{
		if (game->sys.key_ctrl.up)
			move(game, (t_vec){.x = 0, .y = -1});
		else if (game->sys.key_ctrl.down)
			move(game, (t_vec){.x = 0, .y = 1});
		else if (game->sys.key_ctrl.left)
			move(game, (t_vec){.x = -1, .y = 0});
		else if (game->sys.key_ctrl.right)
			move(game, (t_vec){.x = 1, .y = 0});

	}
	return (0);
}

int	game_loop(t_game *game)
{
	game->sys.timer = game->sys.timer + 1 % ULONG_MAX;
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
	(void)argc;
	(void)argv;
	app();
	return (0);
}