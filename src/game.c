/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:02:24 by ttsubo            #+#    #+#             */
/*   Updated: 2025/02/10 12:31:04 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/**
 * @brief gameを初期化します。
 *
 * @param title
 * @param size
 * @return t_game*
 * @note	一部の情報を決め打ちにしています。
 */
t_game	*game_init(char *title, t_vec size, char (*map)[6])
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	game->func = (t_func){.exit = game_exit, .reset = game_reset};
	game->sys.mlx = mlx_init();
	game->sys.win = mlx_new_window(game->sys.mlx, size.x, size.y, title);
	game->data.count = 0;
	game->data.coin = 2;
	game->data.player = (t_vec){.x = 1, .y = 2};
	game->data.is_clear = false;
	game->data.map = map;
	return (game);
}

/**
 * @brief メモリを開放し、ゲームを終了します。
 *
 * @param self
 */
void	game_exit(t_game *self)
{
	if (self)
		free(self);
	exit(0);
}

/**
 * @brief 最初の画面に戻ります。
 * 
 * @param self
 * @note	TODO 決め打ちで入れている 
 */
void	game_reset(t_game *self)
{
	char map[5][6] = {
		{'1', '1', '1', '1', '1', '1'},
		{'1', '0', '0', 'C', '0', '1'},
		{'1', 'P', '0', '0', 'E', '1'},
		{'1', '0', 'C', '0', '0', '1'},
		{'1', '1', '1', '1', '1', '1'},
	};

	if (self)
		free(self);
	self = game_init("so_long_M1", (t_vec){.x=100, .y=100}, map);
}