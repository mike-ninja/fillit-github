/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:25:50 by mbarutel          #+#    #+#             */
/*   Updated: 2022/02/07 09:37:46 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_term_del(t_board *board, t_tetris *tetri)
{
	int	i;
	int	y;
	int	x;

	i = 2;
	while (i >= 0)
	{
		y = tetri->y[i];
		x = tetri->x[i];
		board->board[tetri->loc_y + y][tetri->loc_x + x] = -1;
		i--;
	}
	board->board[tetri->loc_y][tetri->loc_x] = -1;
	tetri->loc_x = -1;
	tetri->loc_y = -1;
}
