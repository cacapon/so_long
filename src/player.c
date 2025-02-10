/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:11:21 by ttsubo            #+#    #+#             */
/*   Updated: 2025/02/10 16:13:42 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

/**
 * @brief プレイヤーが動きます。
 * 
 * @param game 
 * @param d_vec 
 */
void	move(t_game *game, t_vec d_vec)
{
	t_vec	p_mv;
	t_vec	p;

	game->data.is_p_state = false;
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
	game->data.is_p_state = true;
}

/**
 * @brief 時間経過によるプレイヤーの状態変化などを
 * 
 * @param game 
 */
void	player_update(t_game *game)
{
	
}