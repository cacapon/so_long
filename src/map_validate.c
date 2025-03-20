/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:57:18 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/20 17:51:40 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief 0,1,C,E,P(\n)のみで構成されているかチェックします。
 *
 * @param map
 * @return true		:有効な文字だけで構成されている
 * @return false 	:無効な文字を含む
 */
t_sl_result	is_valid_data(t_map map)
{
	int	i;

	i = 0;
	if (!map.data || map.data[i] == '\0')
		return ((t_sl_result){false, MAP_007});
	while (map.data[i])
	{
		if (map.data[i] == '0' || map.data[i] == '1' || map.data[i] == 'C'
			|| map.data[i] == 'E' || map.data[i] == 'P' || map.data[i] == '\n')
			i++;
		else
			return ((t_sl_result){false, GEN_001});
	}
	return ((t_sl_result){true, NO_ERR});
}

static int	_get_elem_count(t_map map, char elem)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!map.data || map.data[i] == '\0')
		return (0);
	while (map.data[i])
	{
		if (map.data[i] == elem)
			count++;
		i++;
	}
	return (count);
}

/**
 * @brief map要素の個数が正しいかチェックします。
 *
 * @param map
 */
t_sl_result	is_valid_map_count(t_map map)
{
	int	c_count;
	int	e_count;
	int	p_count;

	c_count = _get_elem_count(map, 'C');
	e_count = _get_elem_count(map, 'E');
	p_count = _get_elem_count(map, 'P');
	if (c_count == 0)
		return ((t_sl_result){false, ITM_000});
	if (e_count == 0)
		return ((t_sl_result){false, MAP_002});
	if (e_count > 1)
		return ((t_sl_result){false, MAP_003});
	if (p_count == 0)
		return ((t_sl_result){false, MAP_000});
	if (p_count > 1)
		return ((t_sl_result){false, MAP_001});
	return ((t_sl_result){true, NO_ERR});
}

/**
 * @brief 周囲が壁に囲まれているかチェックします。
 *
 * @param map
 * @return t_sl_result
 * @note indexはi=x+(yw)+yで求められるので簡略化可能かも
 */
t_sl_result	is_arround_wall(t_map map)
{
	int			lf_count;
	int			index;
	t_sl_vec	vec;

	vec = (t_sl_vec){0, 0};
	lf_count = 0;
	index = 0;
	while (map.data[index] && vec.y < map.h)
	{
		index = vec.x + (vec.y * map.w) + lf_count;
		if (vec.y == 0 || vec.y == map.h - 1)
		{
			if (map.data[index] != '1')
				return ((t_sl_result){false, MAP_005});
		}
		else if (vec.x == 0 || vec.x == map.w - 1)
		{
			if (map.data[index] != '1')
				return ((t_sl_result){false, MAP_005});
		}
		if (vec.x == map.w - 1)
		{
			vec = (t_sl_vec){0, vec.y + 1};
			lf_count++;
			continue ;
		}
		vec.x++;
	}
	return ((t_sl_result){true, NO_ERR});
}
