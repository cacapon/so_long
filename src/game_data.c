/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:13:16 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/22 17:47:24 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game_data	*game_data_init(void)
{
	t_game_data	*data;

	data = ft_calloc(1, sizeof(t_game_data));
	if (!data)
		return (NULL);
	data->map = ft_calloc(1, sizeof(t_map));
	if (!data->map)
		return (data);
	data->map->data = ft_strdup("");
	data->count = 0;
	data->has_items = 0;
	data->is_clear = false;
	data->p_pos = (t_sl_vec){-1, -1};
	return (data);
}

void	game_data_dest(t_game_data *data)
{
	if (!data)
		return ;
	free(data->map->data);
	free(data->map);
	free(data);
}

t_sl_result	is_valid_game_data(t_game_data *data)
{
	if (!data && data->map && data->map->data)
		return ((t_sl_result){false, GEN_002});
	return ((t_sl_result){true, NO_ERR});
}
