/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:07:44 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/22 17:48:28 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	_set_first_width(t_map **map, int *i)
{
	while ((*map)->data[*i] && (*map)->h == 0)
	{
		if ((*map)->data[*i] == '\n')
		{
			(*map)->h++;
			(*i)++;
			break ;
		}
		(*map)->w++;
		(*i)++;
	}
}

/**
 * @brief ft_strjoinのマイナー改造Ver. 内部でs1をメモリ開放してます。
 *
 * @param s1
 * @param s2
 * @return char*
 */
static char	*sl_strjoin(char *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = malloc(s1_len + s2_len + 1);
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s1, s1_len + 1);
	ft_strlcat(new_str, s2, s1_len + s2_len + 1);
	free(s1);
	return (new_str);
}

/**
 * @brief map_pathのファイルをmap文字列ポインタに書き込みます。
 * 
 * @param map_path 
 * @param map 
 * @return t_sl_result 
 */
t_sl_result	load_map(char *map_path, char **map)
{
	char	*line;
	int		fd;

	line = "";
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return ((t_sl_result){.sts = false, .e_code = MAP_006});
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		*map = sl_strjoin(*map, line);
		free(line);
	}
	free(line);
	close(fd);
	if (*map[0] == '\0')
		return ((t_sl_result){.sts = false, .e_code = MAP_007});
	return ((t_sl_result){.sts = true, .e_code = NO_ERR});
}

/**
 * @brief mapの高さ・幅を初期化します。 長方形ではない場合エラーになります。
 *
 * @param map
 * @return t_sl_result
 */
t_sl_result	init_map_size(t_map **map)
{
	int	i;
	int	tmp_w;

	(*map)->w = 0;
	(*map)->h = 0;
	i = 0;
	tmp_w = 0;
	_set_first_width(map, &i);
	while ((*map)->data[i])
	{
		if ((*map)->data[i] == '\n')
		{
			if (tmp_w != (*map)->w)
				return ((t_sl_result){false, MAP_004});
			(*map)->h++;
			tmp_w = 0;
			i++;
		}
		tmp_w++;
		i++;
	}
	(*map)->h++;
	if (tmp_w != (*map)->w)
		return ((t_sl_result){false, MAP_004});
	return ((t_sl_result){true, NO_ERR});
}
