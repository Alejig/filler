/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 07:58:18 by aljigmon          #+#    #+#             */
/*   Updated: 2019/10/24 18:27:51 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "libft.h"

static void	free_tab_char(char ***tab)
{
	int		i;

	i = 0;
	while ((*tab)[i])
	{
		ft_strdel(&(*tab)[i]);
		i++;
	}
	free(*tab);
	*tab = NULL;
}

static void	free_tab_int(int ***tab, int y)
{
	int		i;

	i = 0;
	while (i < y)
	{
		free((*tab)[i]);
		i++;
	}
	free(*tab);
	*tab = NULL;
}

int			free_infos(t_info *ptr, t_info *ptr2)
{
	if (ptr)
	{
		if (ptr->data != NULL)
			ft_strdel(&ptr->data);
		if (ptr->tab_2d != NULL)
			free_tab_char(&ptr->tab_2d);
		if (ptr->tab_i != NULL)
			free_tab_int(&ptr->tab_i, ptr->size_y);
	}
	if (ptr2)
	{
		if (ptr2->data != NULL)
			ft_strdel(&ptr2->data);
		if (ptr2->tab_2d != NULL)
			free_tab_char(&ptr2->tab_2d);
		if (ptr2->tab_i != NULL)
			free_tab_int(&ptr2->tab_i, ptr2->size_y);
	}
	return (-1);
}
