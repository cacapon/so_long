/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_define.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:49:52 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/22 16:53:15 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_DEFINE_H
# define SO_LONG_DEFINE_H

typedef enum e_err_code
{
	GEN_000,
	GEN_001,
	GEN_002,
	GEN_003,
	FLE_000,
	FLE_001,
	ITM_000,
	ITM_001,
	MAP_000,
	MAP_001,
	MAP_002,
	MAP_003,
	MAP_004,
	MAP_005,
	MAP_006,
	MAP_007,
	XXX_000,
	NO_ERR
}	t_err_code;

# define GEN_000_STR "想定外のエラー\n"
# define GEN_001_STR "未知のワードを検出しました\n"
# define GEN_002_STR "メモリ割当に失敗しました\n"
# define GEN_003_STR "引数は一つだけ指定できます\n"
# define FLE_000_STR "渡されたファイルは.ber拡張子ではありません\n"
# define FLE_001_STR "渡されたファイル名に拡張子がありませんでした\n"
# define ITM_000_STR "アイテムが存在しません\n"
# define ITM_001_STR "アイテムが収集不可能です\n"
# define MAP_000_STR "開始位置がありません\n"
# define MAP_001_STR "開始位置が複数あります\n"
# define MAP_002_STR "出口がありません\n"
# define MAP_003_STR "出口が複数あります\n"
# define MAP_004_STR "マップが長方形ではありません\n"
# define MAP_005_STR "マップが閉じていません\n"
# define MAP_006_STR "マップファイルを開けませんでした\n"
# define MAP_007_STR "空のマップファイルです\n"
# define XXX_000_STR "存在しないエラーコードを渡されました\n"

#endif