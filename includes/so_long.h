/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:50:14 by ttsubo            #+#    #+#             */
/*   Updated: 2025/02/01 15:12:10 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_result.h"
# include "libft.h"
# include <stddef.h>
# include <stdbool.h>
# include "mlx.h"

typedef struct s_game	t_game;

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
}						t_err_code;

typedef struct e_vector
{
	int					x;
	int					y;
}						t_vector;

typedef struct s_game
{
	char				**map;
	int					count;
	int					coin;
	t_vector			player;
	bool				is_clear;
	void				(*draw)(t_game *self);
	void				(*update)(t_game *self);

}						t_game;

void					input(t_game *self);
void					draw(t_game *self);
void					update(t_game *self);

#endif