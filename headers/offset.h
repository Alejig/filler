/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 04:53:38 by aljigmon          #+#    #+#             */
/*   Updated: 2019/10/22 04:56:29 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFSET_H
# define OFFSET_H

int	get_offset_y(char **piece);
int	get_offset_x(char **piece);
int	get_offset_top(char **piece, int y_piece, int x_piece);
int	get_offset_left(char *str, int x_piece);

#endif
