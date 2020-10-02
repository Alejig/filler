/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_filling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:12:46 by aljigmon          #+#    #+#             */
/*   Updated: 2019/10/26 11:50:18 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "defines.h"
#include "init_struct.h"
#include "get_directions.h"
#include "to_int_tab.h"
#include "match_piece.h"

static int	empty_cases(int **tab, int y, int x)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < y)
	{
		while (j < x)
		{
			if (tab[i][j] == POINT)
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

static void	flood_filling(t_info *map, int nb, int i, int j)
{
	if (i - 1 >= 0 && map->tab_i[i - 1][j] == POINT)
		map->tab_i[i - 1][j] = nb;
	if (i + 1 < map->size_y && map->tab_i[i + 1][j] == POINT)
		map->tab_i[i + 1][j] = nb;
	if (j + 1 < map->size_x && map->tab_i[i][j + 1] == POINT)
		map->tab_i[i][j + 1] = nb;
	if (j - 1 >= 0 && map->tab_i[i][j - 1] == POINT)
		map->tab_i[i][j - 1] = nb;
}

static void	flood_fill(t_info *map, int c, int nb)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < map->size_y)
	{
		while (j < map->size_x)
		{
			if (map->tab_i[i][j] == c)
				flood_filling(map, nb, i, j);
			else if (map->tab_i[i][j] == POINT && nb > 300)
				map->tab_i[i][j] = nb;
			j++;
		}
		i++;
		j = 0;
	}
}

int			algo_filling(t_info *map, t_info *piece, t_pos *player)
{
	t_pos	enemy;
	int		n;

	n = 0;
	init_tpos(&enemy);
	enemy.c = player->c == 'O' ? 'X' : 'O';
	map->tab_i = to_int_tab(map->tab_2d, player, &enemy);
	flood_fill(map, ENEMY_CHAR, n);
	while (empty_cases(map->tab_i, map->size_y, map->size_x))
	{
		flood_fill(map, n, n + 1);
		n++;
	}
	if (!get_directions(player, map))
		return (0);
	while (match_piece(map, player, *piece) == 0)
	{
		map->tab_i[player->y][player->x] = USED_POINT;
		if (!get_directions(player, map))
			return (0);
	}
	return (1);
}
