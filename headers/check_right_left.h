/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_right_left.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:28:18 by aljigmon          #+#    #+#             */
/*   Updated: 2019/10/26 11:35:49 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_RIGHT_LEFT_H
# define CHECK_RIGHT_LEFT_H

# include "struct.h"

int	c_left(t_info *map, int i, int j, t_info piece);
int	c_right(t_info *map, int i, int j, t_info piece);

#endif
