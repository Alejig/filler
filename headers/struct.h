/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:10:41 by aljigmon          #+#    #+#             */
/*   Updated: 2019/10/24 18:41:24 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_info
{
	int		lines;
	int		columns;
	char	*data;
	int		offset_y;
	int		offset_x;
	char	**tab_2d;
	int		**tab_i;
	int		size_y;
	int		size_x;
}					t_info;

typedef struct		s_pos
{
	int		c;
	int		y;
	int		x;
}					t_pos;

typedef struct		s_index
{
	int		i;
	int		j;
}					t_index;

#endif
