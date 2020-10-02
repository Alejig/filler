/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_directions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 10:33:43 by aljigmon          #+#    #+#             */
/*   Updated: 2019/10/26 11:54:22 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "defines.h"

static void	get_directions_add_j(t_pos *p, t_info *m, t_index dx, int *t)
{
	if (dx.j - 1 >= 0 && m->tab_i[dx.i][dx.j - 1] < *t
			&& m->tab_i[dx.i][dx.j - 1] >= 0)
	{
		p->y = dx.i;
		p->x = dx.j;
		*t = m->tab_i[dx.i][dx.j - 1];
	}
	if (dx.j + 1 < m->size_x && m->tab_i[dx.i][dx.j + 1] < *t
			&& m->tab_i[dx.i][dx.j + 1] >= 0)
	{
		p->y = dx.i;
		p->x = dx.j;
		*t = m->tab_i[dx.i][dx.j + 1];
	}
}

static void	get_directions_add_i(t_pos *p, t_info *m, t_index dx, int *t)
{
	if (dx.i - 1 >= 0 && m->tab_i[dx.i - 1][dx.j] < *t
			&& m->tab_i[dx.i - 1][dx.j] >= 0)
	{
		p->y = dx.i;
		p->x = dx.j;
		*t = m->tab_i[dx.i - 1][dx.j];
	}
	if (dx.i + 1 < m->size_y && m->tab_i[dx.i + 1][dx.j] < *t
			&& m->tab_i[dx.i + 1][dx.j] >= 0)
	{
		p->y = dx.i;
		p->x = dx.j;
		*t = m->tab_i[dx.i + 1][dx.j];
	}
}

int			get_directions(t_pos *player, t_info *map)
{
	t_index	dx;
	int		tempo;

	dx.i = 0;
	dx.j = 0;
	tempo = 2147483647;
	while (dx.i < map->size_y)
	{
		while (dx.j < map->size_x)
		{
			if (map->tab_i[dx.i][dx.j] == PLAYER_CHAR)
			{
				get_directions_add_i(player, map, dx, &tempo);
				get_directions_add_j(player, map, dx, &tempo);
			}
			dx.j++;
		}
		dx.j = 0;
		dx.i++;
	}
	return (tempo != 2147483647 ? 1 : 0);
}

int			get_right_point_piece(char **piece, int *y, int *x)
{
	while (piece[*y])
	{
		while (piece[*y][*x])
		{
			if (piece[*y][*x] == '*')
				return (1);
			(*x)++;
		}
		(*y)++;
		*x = 0;
	}
	return (0);
}
