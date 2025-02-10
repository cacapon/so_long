/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:50:14 by ttsubo            #+#    #+#             */
/*   Updated: 2025/02/10 11:51:59 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// header includes
// 	std lib
# include <stdbool.h>
# include <stddef.h>
// 	custom lib
# include "libft.h"
# include "mlx.h"
//	so_long headers
# include "so_long_def.h"
# include "key_input.h"
# include "so_long_gamedata.h"

// functions
int				draw(t_game *self);
int				update(t_game *self);

#endif