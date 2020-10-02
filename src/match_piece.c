/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:17:16 by aljigmon          #+#    #+#             */
/*   Updated: 2019/10/26 11:58:16 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "offset.h"
#include "check_right_left.h"
#include "check_top_bottom.h"
#include "get_directions.h"
#include "defines.h"
#include "print_coor.h"

static int	match(t_info *map, t_pos *player, t_info piece)
{
	int		i;
	int		j;

	i = player->y;
	j = player->x;
	if (map->tab_i[i][j] == PLAYER_CHAR
			&& piece.tab_2d[piece.size_y][piece.size_x] == '*')
	{
		if (!c_right(map, i, j + 1, piece)
				|| !c_left(map, i, j - 1, piece))
			return (0);
	}
	else
		return (0);
	if (!check_bottom(map, i + 1, j, piece))
		return (0);
	if (!check_top(map, i - 1, j, piece))
		return (0);
	i = player->y - piece.offset_y
		- get_offset_top(piece.tab_2d, piece.size_y, piece.size_x);
	j = player->x - piece.offset_x
		- get_offset_left(&piece.tab_2d[piece.size_y][0], piece.size_x);
	print_coordinates(i, j);
	return (1);
}

int			match_piece(t_info *map, t_pos *player, t_info piece)
{
	piece.size_y = 0;
	piece.size_x = 0;
	if (!get_right_point_piece(piece.tab_2d, &piece.size_y, &piece.size_x))
		return (0);
	while (!match(map, player, piece))
	{
		piece.size_x++;
		if (piece.tab_2d[piece.size_y][piece.size_x] == '\0')
		{
			if (piece.tab_2d[piece.size_y] && piece.tab_2d[piece.size_y + 1])
			{
				piece.size_y++;
				piece.size_x = 0;
			}
			else
				return (0);
		}
		if (!get_right_point_piece(piece.tab_2d, &piece.size_y, &piece.size_x))
			return (0);
	}
	return (1);
}
