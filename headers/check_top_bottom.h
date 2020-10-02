/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_top_bottom.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:30:49 by aljigmon          #+#    #+#             */
/*   Updated: 2019/10/26 11:36:13 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_TOP_BOTTOM_H
# define CHECK_TOP_BOTTOM_H

# include "struct.h"

int			check_top(t_info *map, int i, int j, t_info piece);
int			check_bottom(t_info *map, int i, int j, t_info piece);

#endif
