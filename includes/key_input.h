/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:42:59 by ttsubo            #+#    #+#             */
/*   Updated: 2025/02/10 11:43:40 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_INPUT_H
# define KEY_INPUT_H
# include "so_long.h"

int	key_press(int keycode, t_game *game);
int	key_rel(int keycode, t_game *game);

#endif