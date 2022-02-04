/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 23:05:06 by lasalmi           #+#    #+#             */
/*   Updated: 2022/02/04 11:46:47 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void	ft_malloccheck(t_board *board, int i)
{
	if (board->board[i])
		return ;
	while (i-- > 0)
		free(board->board[i]);
	free (board);
	exit(1);
}

static	void	ft_initboard(t_board *board, int n)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < n)
	{
		while (j < n)
		{
			board->board[i][j] = -1;
			j++;
		}
		j = 0;
		i++;
	}
}

t_board	*ft_createboard(int n)
{
	t_board	*board;
	int		index;

	printf("ft_createboard %i\n", n);
	index = 0;
	board = (t_board *)malloc(sizeof(t_board));
	if (!board)
		exit(1);
	board->size = n;
	board->board = (int **)malloc(n * sizeof(int **));
	if (!board->board)
	{
		free(board);
		exit(1);
	}
	while (index < n)
	{
		board->board[index] = (int *)malloc(sizeof(int) * n);
		ft_malloccheck(board, index);
		index++;
	}
	ft_initboard(board, n);
	return (board);
}
