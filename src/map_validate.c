/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:57:18 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/20 14:42:21 by ttsubo           ###   ########.fr       */
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
bool	is_valid_data(t_map map)
{
	int	i;

	i = 0;
	if (!map.data || map.data[i] == '\0')
		return (false);
	while (map.data[i])
	{
		if (map.data[i] == '0' || map.data[i] == '1' || map.data[i] == 'C'
			|| map.data[i] == 'E' || map.data[i] == 'P' || map.data[i] == '\n')
			i++;
		else
			return (false);
	}
	return (true);
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
 * @return t_err_code : err_codeを返します。
 */
t_err_code	is_valid_map_count(t_map map)
{
	int	c_count;
	int	e_count;
	int	p_count;

	c_count = _get_elem_count(map, 'C');
	e_count = _get_elem_count(map, 'E');
	p_count = _get_elem_count(map, 'P');
	if (c_count == 0)
		return (ITM_000);
	if (e_count == 0)
		return (MAP_002);
	if (e_count > 1)
		return (MAP_003);
	if (p_count == 0)
		return (MAP_000);
	if (p_count > 1)
		return (MAP_001);
	return (NO_ERR);
}
