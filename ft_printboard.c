/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printboard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 07:19:22 by lasalmi           #+#    #+#             */
/*   Updated: 2022/02/28 10:58:30 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_initalphabet(char *arr)
{
	char	c;
	int		i;

	i = 0;
	c = 'A';
	while (i < 26)
	{
		arr[i] = c++;
		i++;
	}
}

void	ft_printboard(t_board *board)
{
	char	arr[26];
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_initalphabet(arr);
	while (j < board->size)
	{
		while (i < board->size)
		{
			if (board->board[j][i] == -1)
				write (1, ".", 1);
			else
				write(1, &arr[board->board[j][i]], 1);
			i++;
		}
		write(1, "\n", 1);
		i = 0;
		j++;
	}
}
