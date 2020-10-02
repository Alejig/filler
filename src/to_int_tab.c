/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_int_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 10:48:17 by aljigmon          #+#    #+#             */
/*   Updated: 2019/10/26 18:25:06 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "defines.h"
#include "libft.h"
#include <stdlib.h>

static int	**fill_tab(char **tab, int **new_tab, t_pos *player, t_pos *enemy)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			if (tab[i][j] == player->c)
				new_tab[i][j] = PLAYER_CHAR;
			else if (tab[i][j] == enemy->c)
				new_tab[i][j] = ENEMY_CHAR;
			else if (tab[i][j] == '.')
				new_tab[i][j] = POINT;
			else
				new_tab[i][j] = WC;
			j++;
		}
		i++;
		j = 0;
	}
	return (new_tab);
}

int			**to_int_tab(char **tab, t_pos *player, t_pos *enemy)
{
	int		size_y;
	int		size_x;
	int		i;
	int		**new_tab;

	size_y = ft_strlen(tab[0]);
	i = 0;
	size_x = 0;
	while (tab[size_x])
		size_x++;
	if (!(new_tab = malloc(sizeof(int*) * size_x)))
		return (NULL);
	while (i < size_x)
	{
		if (!(new_tab[i] = malloc(sizeof(int) * size_y)))
		{
			i--;
			while (i >= 0)
				free(new_tab[i--]);
			return (NULL);
		}
		i++;
	}
	return (fill_tab(tab, new_tab, player, enemy));
}
