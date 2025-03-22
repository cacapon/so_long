/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:50:14 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/22 17:49:02 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "glx.h"
# include "so_long_define.h"
# include "so_long_struct.h"
# include <fcntl.h>

t_game_data	*game_data_init(void);
void		game_data_dest(t_game_data *data);
t_sl_result	is_valid_game_data(t_game_data *data);
int			check(t_sl_result result);
void		show_error(t_err_code err_code);
void		sl_utoa(unsigned int num, char *str);
int			draw(void *param);
int			update(void *param);
t_sl_vec	get_player_index(t_map map);
int			get_elem_count(t_map map, char elem);
t_sl_result	is_file_validate(int ac, char *filepath);
t_sl_result	load_map(char *map_path, char **map);
t_sl_result	is_valid_data(t_map map);
t_sl_result	is_valid_map_count(t_map map);
t_sl_result	init_map_size(t_map **map);
t_sl_result	is_arround_wall(t_map map);
t_sl_result	path_check(t_map map);

#endif