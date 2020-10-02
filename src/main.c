/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 09:20:36 by aljigmon          #+#    #+#             */
/*   Updated: 2019/10/26 11:57:31 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_infos.h"
#include "get_who_am_i.h"
#include "algo_filling.h"
#include "struct.h"
#include "init_struct.h"
#include "free.h"
#include "print_coor.h"

int				main(void)
{
	t_info	map;
	t_info	piece;
	t_pos	player;

	init_tpos(&player);
	if (!(get_who_am_i(0, &player)))
		return (-1);
	while (1)
	{
		init_tinfo(&map);
		init_tinfo(&piece);
		if (!get_infos(0, &map, &piece))
		{
			print_coordinates(0, 0);
			return (free_infos(&map, &piece));
		}
		if (!algo_filling(&map, &piece, &player))
		{
			print_coordinates(0, 0);
			return (free_infos(&map, &piece));
		}
		free_infos(&map, &piece);
	}
	return (0);
}
