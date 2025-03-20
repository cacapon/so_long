/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:32:26 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/20 19:37:09 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_elem_count(t_map map, char elem)
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
