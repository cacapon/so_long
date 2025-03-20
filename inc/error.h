/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:49:16 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/20 12:03:36 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include "glx.h"

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
	XXX_000,
}			t_err_code;

# define GEN_000_STR "想定外のエラー\n"
# define GEN_001_STR "未知のワードを検出しました\n"
# define ITM_000_STR "アイテムが存在しません\n"
# define ITM_001_STR "アイテムが収集不可能です\n"
# define MAP_000_STR "開始位置がありません\n"
# define MAP_001_STR "開始位置が複数あります\n"
# define MAP_002_STR "出口がありません\n"
# define MAP_003_STR "出口が複数あります\n"
# define MAP_004_STR "マップが長方形ではありません\n"
# define MAP_005_STR "マップが閉じていません\n"
# define XXX_000_STR "存在しないエラーコードを渡されました\n"

void	show_error(t_err_code err_code);

#endif