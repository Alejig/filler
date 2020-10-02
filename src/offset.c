/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 04:52:41 by aljigmon          #+#    #+#             */
/*   Updated: 2019/10/22 05:24:22 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_offset_y(char **piece)
{
	int		offset;
	int		i;
	int		j;

	i = 0;
	j = 0;
	offset = 0;
	while (piece[i])
	{
		while (piece[i][j])
		{
			if (piece[i][j] == '*')
				return (offset);
			j++;
		}
		if (piece[i][j] == '\0')
			offset++;
		j = 0;
		i++;
	}
	return (offset);
}

int	get_offset_x(char **piece)
{
	int		i;
	int		j;
	int		offset;

	i = 0;
	j = 0;
	offset = 2147483647;
	while (piece[i])
	{
		while (piece[i][j] && piece[i][j] != '*')
		{
			j++;
		}
		offset = j < offset ? j : offset;
		j = 0;
		i++;
	}
	return (offset);
}

int	get_offset_top(char **piece, int y_piece, int x_piece)
{
	int		offset;

	offset = 0;
	y_piece--;
	while (y_piece >= 0 && piece[y_piece][x_piece] != '1')
	{
		y_piece--;
		offset++;
	}
	return (offset);
}

int	get_offset_left(char *str, int x_piece)
{
	int		offset;

	offset = 0;
	x_piece--;
	while (x_piece >= 0 && str[x_piece] != '1')
	{
		x_piece--;
		offset++;
	}
	return (offset);
}
