/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:07:44 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/20 13:52:21 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

char	*get_map(char *map_path)
{
	char	*line;
	char	*lines;
	int		fd;

	line = "";
	lines = ft_strdup(line);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (show_error(MAP_006), NULL);
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		lines = sl_strjoin(lines, line);
		free(line);
	}
	free(line);
	close(fd);
	if (lines[0] == '\0')
		return (show_error(MAP_007), NULL);
	return (lines);
}
