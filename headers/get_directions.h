/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_directions.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 10:34:55 by aljigmon          #+#    #+#             */
/*   Updated: 2019/10/26 11:37:22 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_DIRECTIONS_H
# define GET_DIRECTIONS_H

# include "struct.h"

int	get_directions(t_pos *player, t_info *map);
int	get_right_point_piece(char **piece, int *y, int *x);

#endif
