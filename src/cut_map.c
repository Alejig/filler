/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 03:28:30 by aljigmon          #+#    #+#             */
/*   Updated: 2019/10/22 04:27:54 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	cut_map(char **tab)
{
	char	*tempo;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tempo = NULL;
	while (tab[i])
	{
		tempo = tab[i];
		while (tab[i][j] && (tab[i][j] == ' '
					|| (tab[i][j] >= '0' && tab[i][j] <= '9')))
		{
			j++;
		}
		tab[i] = ft_strdup(&tab[i][j]);
		ft_strdel(&tempo);
		j = 0;
		i++;
	}
}
