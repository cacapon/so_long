/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:28:25 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/26 17:48:15 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RESULT_H
# define FT_RESULT_H

typedef enum e_result_sts
{
	OK,
	NG,
}					t_result_sts;

typedef union u_data
{
	int				i_val;
	char			s_val[256];
}					t_data;

typedef struct e_result
{
	t_result_sts	sts;
	t_data			data;
}					t_result;

#endif