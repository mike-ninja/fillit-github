/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issafe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 05:28:16 by lasalmi           #+#    #+#             */
/*   Updated: 2022/02/04 12:04:18 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_issafe(t_board *board, t_tetris *tetri, int x, int y)
{
	int	square;
	int	i;
	int	n;

	i = 0;
	square = board->size - 1;
	while (i < 3)
	{
		if ((x + tetri->x[i]) > square || (y + tetri->y[i]) > square)
		{
			n = (x + tetri->x[i]) - square * (y + tetri->y[i]) - square;
			printf("%i\n", n);
			return (0);
		}
		if ((x + tetri->x[i]) < 0 || (y + tetri->y[i]) < 0)
		{
			printf("hash lesser than zero\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_isvacant(t_board *board, t_tetris *tetri, int x, int y)
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

int	ft_instetri(t_board *board, t_tetris *tetri, int x, int y) // when is loc_x and loc_y updated?
{
	// printf("-- %i {%i, %i}\n", tetri->i, y, x);
	if (!ft_issafe(board, tetri, x, y) || !ft_isvacant(board, tetri, x, y))
	{
		return (0);
	}
	tetri->loc_x = x;
	tetri->loc_y = y;
	board->board[y][x] = tetri->i;
	board->board[y + tetri->y[0]][x + tetri->x[0]] = tetri->i;
	board->board[y + tetri->y[1]][x + tetri->x[1]] = tetri->i;
	board->board[y + tetri->y[2]][x + tetri->x[2]] = tetri->i;
	return (1);
}
