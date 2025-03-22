/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:15:36 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/22 16:56:37 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief 渡された引数が2(実行パスと引数が一つ)かチェックします。
 *
 * @param ac
 * @return t_sl_result
 */
static t_sl_result	_is_args_2(int ac)
{
	if (ac != 2)
		return ((t_sl_result){false, GEN_003});
	return ((t_sl_result){true, NO_ERR});
}

/**
 * @brief 拡張子が.berかチェックします。
 *
 * @param filepath
 * @return t_sl_result
 */
static t_sl_result	_is_ext_ber(char *filepath)
{
	char	*ext;

	if (!filepath)
		return ((t_sl_result){false, FLE_000});
	ext = ft_strrchr(filepath, '.');
	if (!ext)
		return ((t_sl_result){false, FLE_001});
	if (ft_strncmp(ext, ".ber", 5) != 0)
		return ((t_sl_result){false, FLE_000});
	return ((t_sl_result){true, NO_ERR});
}

/**
 * @brief マップファイル名が問題ないかチェックします。
 * 
 * @param ac 
 * @param filepath 
 * @return t_sl_result 
 */
t_sl_result	is_file_validate(int ac, char *filepath)
{
	t_sl_result	result;

	result = _is_args_2(ac);
	if (!result.sts)
		return (result);
	result = _is_ext_ber(filepath);
	return (result);
}
