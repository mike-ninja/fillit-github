/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 05:28:16 by lasalmi           #+#    #+#             */
/*   Updated: 2022/02/08 13:23:33 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_issafe(t_board *board, t_tetris *tetri, int x, int y)
{
	int	square;
	int	i;

	i = 0;
	square = board->size - 1;
	while (i < 3)
	{
		if ((x + tetri->x[i]) > square || (y + tetri->y[i]) > square)
			return (0);
		if ((x + tetri->x[i]) < 0 || (y + tetri->y[i]) < 0)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_isvacant(t_board *board, t_tetris *tetri, int x, int y)
{
	if (board->board[y][x] != -1)
		return (0);
	if (board->board[y + tetri->y[0]][x + tetri->x[0]] != -1)
		return (0);
	if (board->board[y + tetri->y[1]][x + tetri->x[1]] != -1)
		return (0);
	if (board->board[y + tetri->y[2]][x + tetri->x[2]] != -1)
		return (0);
	return (1);
}

int	ft_instetri(t_board *board, t_tetris *tetri, int y, int x)
{
	if (!ft_issafe(board, tetri, x, y) || !ft_isvacant(board, tetri, x, y))
		return (0);
	board->board[y][x] = tetri->i;
	board->board[y + tetri->y[0]][x + tetri->x[0]] = tetri->i;
	board->board[y + tetri->y[1]][x + tetri->x[1]] = tetri->i;
	board->board[y + tetri->y[2]][x + tetri->x[2]] = tetri->i;
	tetri->loc_y = y;
	tetri->loc_x = x;
	return (1);
}
