/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:39:17 by ttsubo            #+#    #+#             */
/*   Updated: 2025/02/10 11:43:52 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_input.h"

static void set_key_state(int keycode, t_game *game, bool state)
{
	if (keycode == KEY_ESC)
		game->sys.key_ctrl.exit = state;
	else if (keycode == KEY_R)
		game->sys.key_ctrl.reset = state;
	else if (keycode == KEY_UP || keycode == KEY_W)
		game->sys.key_ctrl.up = state;
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		game->sys.key_ctrl.down = state;
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		game->sys.key_ctrl.left = state;
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		game->sys.key_ctrl.right = state;
}

int key_press(int keycode, t_game *game)
{
	set_key_state(keycode, game, true);
	return (0);
}

int key_rel(int keycode, t_game *game)
{
	set_key_state(keycode, game, false);
	return (0);
}
