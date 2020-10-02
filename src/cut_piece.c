/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:24:52 by aljigmon          #+#    #+#             */
/*   Updated: 2019/10/20 07:26:06 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		check_lines_reverse(char **tab, int y, int x)
{
	while (x >= 0)
	{
		if (tab[y][x] == '*')
			return (0);
		x--;
	}
	x = 0;
	while (tab[y][x])
	{
		tab[y][x] = '1';
		x++;
	}
	return (1);
}

static int		check_columns_reverse(char **tab, int y, int x)
{
	while (y >= 0)
	{
		if (tab[y][x] == '*')
			return (0);
		y--;
	}
	y = 0;
	while (tab[y])
	{
		tab[y][x] = '1';
		y++;
	}
	return (1);
}

static int		check_lines(char **tab, int y, int x)
{
	while (tab[y][x])
	{
		if (tab[y][x] == '*')
			return (0);
		x++;
	}
	x--;
	while (x >= 0)
	{
		tab[y][x] = '1';
		x--;
	}
	return (1);
}

static int		check_columns(char **tab, int y, int x)
{
	while (tab[y] && tab[y][x])
	{
		if (tab[y][x] == '*')
			return (0);
		y++;
	}
	y--;
	while (y >= 0)
	{
		tab[y][x] = '1';
		y--;
	}
	return (1);
}

void			cut_piece(char **tab, int y, int x)
{
	y--;
	x -= 2;
	while (check_columns_reverse(tab, y, x))
		x--;
	while (check_lines_reverse(tab, y, x))
		y--;
	y = 0;
	x = 0;
	while (check_columns(tab, y, x))
		x++;
	while (check_lines(tab, y, x))
		y++;
}
