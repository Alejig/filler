/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 19:32:46 by aljigmon          #+#    #+#             */
/*   Updated: 2019/10/27 17:14:31 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "struct.h"
#include <stdlib.h>
#include "libft.h"
#include "cut_piece.h"
#include "offset.h"
#include "cut_map.h"
#include "check_read.h"
#include "check_piece.h"

static int		get_more_map(int fd, t_info *map)
{
	int		rt;
	char	*buffer;
	int		i;
	int		total;

	i = 0;
	total = map->columns * map->lines;
	if (!(buffer = malloc(map->columns)))
		return (0);
	while ((rt = read(fd, &buffer[i], 1)) && buffer[i] != '\n')
		if (rt > 0)
			i++;
	if (i != map->columns - 1)
		return (0);
	buffer[i] = '\0';
	ft_strdel(&buffer);
	if (!(map->data = malloc(total + 1)))
		return (0);
	map->data[total] = '\0';
	i = 0;
	while (i < total && ((rt = read(fd, &map->data[i], 1))))
		if (rt > 0)
			i++;
	return (check_read(map->data, map->columns - 1));
}

static int		get_map(int fd, t_info *map)
{
	char	buffer[4096];
	int		rt;
	int		i;

	i = 0;
	rt = 0;
	ft_bzero(buffer, 4096);
	while (((rt = read(fd, &buffer[i], 1))) && buffer[i] != '\n')
		if (rt > 0)
			i++;
	buffer[i] = '\0';
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] >= '0' && buffer[i] <= '9' && map->lines == 0)
			map->lines = ft_atoi(&buffer[i]);
		else if (buffer[i] >= '0' && buffer[i] <= '9' && map->columns == 0)
			map->columns = ft_atoi(&buffer[i]) + 5;
		while (buffer[i] >= '0' && buffer[i] <= '9')
			i++;
		i++;
	}
	if (map->lines <= 0)
		return (0);
	return (get_more_map(fd, map));
}

static int		get_more_piece(int fd, t_info *piece)
{
	int		rt;
	int		i;
	int		total;

	rt = 0;
	i = 0;
	total = piece->columns * piece->lines;
	if (!(piece->data = malloc(total + 1)))
		return (0);
	piece->data[total] = '\0';
	while (i < total && ((rt = read(fd, &piece->data[i], 1))))
		if (rt > 0)
			i++;
	return (check_read(piece->data, piece->columns - 1));
}

static int		get_piece(int fd, t_info *piece)
{
	int		rt;
	char	buffer[4096];
	int		i;

	i = 0;
	ft_bzero(buffer, 4096);
	while (((rt = read(fd, &buffer[i], 1))) && buffer[i] != '\n')
		if (rt > 0)
			i++;
	buffer[i] = '\0';
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] >= '0' && buffer[i] <= '9' && piece->lines == 0)
			piece->lines = ft_atoi(&buffer[i]);
		else if (buffer[i] >= '0' && buffer[i] <= '9' && piece->columns == 0)
			piece->columns = ft_atoi(&buffer[i]) + 1;
		while (buffer[i] >= '0' && buffer[i] <= '9')
			i++;
		i++;
	}
	if (piece->lines <= 0)
		return (0);
	return (get_more_piece(fd, piece));
}

int				get_infos(int fd, t_info *map, t_info *piece)
{
	if (!(get_map(fd, map)))
		return (0);
	if (!(get_piece(fd, piece)))
		return (0);
	if (!(map->tab_2d = ft_strsplit(map->data, '\n')))
		return (0);
	if (!(piece->tab_2d = ft_strsplit(piece->data, '\n')))
		return (0);
	cut_map(map->tab_2d);
	if (!check_piece(piece->data))
		return (0);
	while (map->tab_2d[map->size_y])
		map->size_y++;
	cut_piece(piece->tab_2d, piece->lines, piece->columns);
	piece->offset_y = get_offset_y(piece->tab_2d);
	piece->offset_x = get_offset_x(piece->tab_2d);
	map->size_x = ft_strlen(map->tab_2d[0]);
	return (1);
}
