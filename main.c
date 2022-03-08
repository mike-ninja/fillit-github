/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:46:42 by lasalmi           #+#    #+#             */
/*   Updated: 2022/03/06 10:38:38 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_delboard(t_board *board)
{
	int	i;

	i = board->size - 1;
	while (i >= 0)
		free (board->board[i--]);
	free (board->board);
	free (board);
}

void	ft_usage(void)
{
	ft_putstr("usage: fillit target_file\n");
	exit(1);
}

int	main(int argc, char **argv)
{
	int			n;
	int			fd;
	t_board		*boardi;
	t_tetris	tetroes[27];

	if (argc != 2)
		ft_usage();
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error();
	n = ft_square(ft_validator(fd, tetroes) * 4);
	close (fd);
	boardi = ft_createboard(n);
	while (ft_solver(boardi, tetroes) == 0)
	{
		ft_delboard(boardi);
		boardi = ft_createboard(++n);
	}
	ft_printboard(boardi);
	ft_delboard(boardi);
	return (0);
}
