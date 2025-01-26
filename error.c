/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:52:52 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/26 17:23:54 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_error(t_err_code err_code)
{
	ft_printf("Error\n");
	if (err_code == GEN_000)
		ft_printf("想定外のエラー\n");
	else if (err_code == GEN_001)
		ft_printf("未知のワードを検出しました\n");
	else if (err_code == ITM_000)
		ft_printf("アイテムが存在しません\n");
	else if (err_code == ITM_001)
		ft_printf("アイテムが収集不可能です\n");
	else if (err_code == MAP_000)
		ft_printf("開始位置がありません\n");
	else if (err_code == MAP_001)
		ft_printf("開始位置が複数あります\n");
	else if (err_code == MAP_002)
		ft_printf("出口がありません\n");
	else if (err_code == MAP_003)
		ft_printf("出口が複数あります\n");
	else if (err_code == MAP_004)
		ft_printf("マップが長方形ではありません\n");
	else if (err_code == MAP_005)
		ft_printf("マップが閉じていません\n");
	else
		ft_printf("存在しないエラーコードを渡されました\n");
}
