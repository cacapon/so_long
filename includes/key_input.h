/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:42:59 by ttsubo            #+#    #+#             */
/*   Updated: 2025/02/10 12:31:57 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_INPUT_H
# define KEY_INPUT_H
# include "game.h"
# include "so_long_def.h"

int	key_press(int keycode, t_game *game);
int	key_rel(int keycode, t_game *game);

#endif