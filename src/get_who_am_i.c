/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_who_am_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:49:28 by aljigmon          #+#    #+#             */
/*   Updated: 2019/10/20 07:26:40 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include "struct.h"

int		get_who_am_i(int fd, t_pos *player)
{
	char	buffer[4096];
	int		rt_read;
	int		i;

	rt_read = 0;
	i = 0;
	ft_bzero(buffer, 4096);
	while ((rt_read = read(fd, &buffer[i], 1)) >= 0 && buffer[i] != '\n')
	{
		if (rt_read == -1)
			return (0);
		if (rt_read > 0)
			i++;
	}
	buffer[i] = '\0';
	if (rt_read > 0)
	{
		if (ft_strstr(buffer, "$$$") && ft_strstr(buffer, "p1"))
			player->c = 'O';
		else
			player->c = 'X';
	}
	else
		return (0);
	return (1);
}
