/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:52:52 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/22 16:32:01 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check(t_sl_result result)
{
	if (!result.sts)
	{
		show_error(result.e_code);
		return (1);
	}
	return (0);
}

void	show_error(t_err_code err_code)
{
	static char	*err_str[] = {
		GEN_000_STR, GEN_001_STR, GEN_002_STR, GEN_003_STR,
		FLE_000_STR, FLE_001_STR,
		ITM_000_STR, ITM_001_STR,
		MAP_000_STR, MAP_001_STR, MAP_002_STR, MAP_003_STR,
		MAP_004_STR, MAP_005_STR, MAP_006_STR, MAP_007_STR,
		XXX_000_STR,
	};

	ft_printf("Error\n");
	if (0 <= err_code && err_code < XXX_000)
		ft_printf(err_str[err_code]);
	else
		ft_printf(err_str[XXX_000]);
}
