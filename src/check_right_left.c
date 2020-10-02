/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_right_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:27:23 by aljigmon          #+#    #+#             */
/*   Updated: 2019/10/26 18:44:05 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "struct.h"

int	c_right(t_info *map, int i, int j, t_info piece)
{
	piece.size_x = piece.size_x + 1;
	while (j < map->size_x && piece.tab_2d[piece.size_y][piece.size_x]
			&& piece.tab_2d[piece.size_y][piece.size_x] != '1')
	{
		if (map->tab_i[i][j] != ENEMY_CHAR && map->tab_i[i][j]
				!= PLAYER_CHAR && map->tab_i[i][j] != USED_POINT
				&& map->tab_i[i][j] != WC
				&& piece.tab_2d[piece.size_y][piece.size_x] == '*')
		{
			j++;
			piece.size_x++;
		}
		else if (piece.tab_2d[piece.size_y][piece.size_x] == '.')
		{
			j++;
			piece.size_x++;
		}
		else
			return (0);
	}
	if (j == map->size_x && piece.tab_2d[piece.size_y][piece.size_x]
			&& piece.tab_2d[piece.size_y][piece.size_x] != '1')
		return (0);
	return (1);
}

int	c_left(t_info *map, int i, int j, t_info piece)
{
	piece.size_x = piece.size_x - 1;
	while (j >= 0 && piece.size_x >= 0
			&& piece.tab_2d[piece.size_y][piece.size_x] != '1')
	{
		if (map->tab_i[i][j] != ENEMY_CHAR && map->tab_i[i][j]
				!= PLAYER_CHAR && map->tab_i[i][j] != USED_POINT
				&& map->tab_i[i][j] != WC
				&& piece.tab_2d[piece.size_y][piece.size_x] == '*')
		{
			j--;
			piece.size_x--;
		}
		else if (piece.tab_2d[piece.size_y][piece.size_x] == '.')
		{
			j--;
			piece.size_x--;
		}
		else
			return (0);
	}
	if (j < 0 && piece.size_x >= 0
			&& piece.tab_2d[piece.size_y][piece.size_x] != '1')
		return (0);
	return (1);
}
