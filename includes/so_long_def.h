/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_def.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:45:38 by ttsubo            #+#    #+#             */
/*   Updated: 2025/02/10 11:46:32 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_DEF_H
# define SO_LONG_DEF_H

# include <X11/keysym.h>

typedef enum e_err_code
{
	GEN_000,
	GEN_001,
	ITM_000,
	ITM_001,
	MAP_000,
	MAP_001,
	MAP_002,
	MAP_003,
	MAP_004,
	MAP_005,
}	t_err_code;

typedef enum e_keycode
{
	KEY_Q = XK_q,
	KEY_ESC = XK_Escape,
	KEY_W = XK_w,
	KEY_S = XK_s,
	KEY_A = XK_a,
	KEY_D = XK_d,
	KEY_R = XK_r,
	KEY_UP = XK_Up,
	KEY_DOWN = XK_Down,
	KEY_LEFT = XK_Left,
	KEY_RIGHT = XK_Right,
}	t_keycode;

#endif