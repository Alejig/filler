/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 03:45:24 by aljigmon          #+#    #+#             */
/*   Updated: 2019/10/24 18:28:18 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <string.h>

void	init_tpos(t_pos *ptr)
{
	ptr->c = 0;
	ptr->y = 0;
	ptr->x = 0;
}

void	init_tinfo(t_info *ptr)
{
	ptr->lines = 0;
	ptr->columns = 0;
	ptr->data = NULL;
	ptr->offset_y = 0;
	ptr->offset_x = 0;
	ptr->tab_2d = NULL;
	ptr->tab_i = NULL;
	ptr->size_y = 0;
	ptr->size_x = 0;
}
