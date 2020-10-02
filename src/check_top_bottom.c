/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_top_bottom.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:29:19 by aljigmon          #+#    #+#             */
/*   Updated: 2019/10/26 18:46:18 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_right_left.h"
#include "struct.h"
#include "defines.h"

static int	check_bottom_end(t_info *map, int i, t_info piece)
{
	if (i == map->size_y && piece.tab_2d[piece.size_y]
			&& piece.tab_2d[piece.size_y][piece.size_x] != '1')
		return (0);
	return (1);
}

int			check_bottom(t_info *map, int i, int j, t_info piece)
{
	piece.size_y = piece.size_y + 1;
	while (i < map->size_y && piece.tab_2d[piece.size_y]
			&& piece.tab_2d[piece.size_y][piece.size_x] != '1')
	{
		if (map->tab_i[i][j] != PLAYER_CHAR && map->tab_i[i][j] != ENEMY_CHAR
				&& map->tab_i[i][j] != USED_POINT && map->tab_i[i][j] != WC
				&& piece.tab_2d[piece.size_y][piece.size_x] == '*')
		{
			if (!c_right(map, i, j + 1, piece)
					|| !c_left(map, i, j - 1, piece))
				return (0);
			i++;
			piece.size_y++;
		}
		else if (piece.tab_2d[piece.size_y][piece.size_x] == '.')
		{
			if (!c_right(map, i, j + 1, piece) || !c_left(map, i, j - 1, piece))
				return (0);
			i++;
			piece.size_y++;
		}
		else
			return (0);
	}
	return (check_bottom_end(map, i, piece));
}

static int	check_top_end(int i, t_info piece)
{
	if (i < 0 && piece.size_y >= 0
			&& piece.tab_2d[piece.size_y][piece.size_x] != '1')
		return (0);
	return (1);
}

int			check_top(t_info *map, int i, int j, t_info piece)
{
	piece.size_y = piece.size_y - 1;
	while (i >= 0 && piece.size_y >= 0
			&& piece.tab_2d[piece.size_y][piece.size_x] != '1')
	{
		if (map->tab_i[i][j] != PLAYER_CHAR && map->tab_i[i][j] != ENEMY_CHAR
				&& map->tab_i[i][j] != USED_POINT && map->tab_i[i][j] != WC
				&& piece.tab_2d[piece.size_y][piece.size_x] == '*')
		{
			if (!c_right(map, i, j + 1, piece)
					|| !c_left(map, i, j - 1, piece))
				return (0);
			i--;
			piece.size_y--;
		}
		else if (piece.tab_2d[piece.size_y][piece.size_x] == '.')
		{
			if (!c_right(map, i, j + 1, piece) || !c_left(map, i, j - 1, piece))
				return (0);
			i--;
			piece.size_y--;
		}
		else
			return (0);
	}
	return (check_top_end(i, piece));
}
