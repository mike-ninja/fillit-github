/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:35:34 by mbarutel          #+#    #+#             */
/*   Updated: 2022/03/06 11:06:43 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(1);
}

static void	ft_nl_check(char *buff)
{
	if (buff[4] != '\n')
		ft_error();
	if (buff[9] != '\n')
		ft_error();
	if (buff[14] != '\n')
		ft_error();
	if (buff[19] != '\n')
		ft_error();
}

static int	ft_check_adjacent(char *buff, int i, t_tetris *tetri, int hash)
{
	static int	f_h;
	int			ret;

	if (!hash)
		f_h = i;
	ret = 0;
	if (hash > 0)
	{
		tetri->x[hash - 1] = (i % 5) - (f_h % 5);
		tetri->y[hash - 1] = (i / 5) - (f_h / 5);
	}
	if (i > 0 && buff[-1] == '#')
		ret++;
	if (i < 19 && buff[1] == '#')
		ret++;
	if (i < 14 && buff[5] == '#')
		ret++;
	if (i > 4 && buff[-5] == '#')
		ret++;
	return (ret);
}

static void	ft_terminos_checker(char *buff, t_tetris *tetri)
{
	int	i;
	int	dots;
	int	hash;
	int	touch;

	i = 0;
	dots = 0;
	hash = 0;
	touch = 0;
	ft_nl_check(buff);
	while (buff[i] == '.' || buff[i] == '\n' || buff[i] == '#')
	{
		if (buff[i] == '.')
			dots++;
		if (buff[i] == '#')
		{
			touch = touch + ft_check_adjacent(&buff[i], i, tetri, hash);
			hash++;
		}
		i++;
	}
	if (hash != 4 || buff[i] != '\0' || dots != 12 || touch < 6)
		ft_error();
}

int	ft_validator(int fd, t_tetris *tetris)
{
	int		i;
	int		bytes_read;
	int		total_bytes;
	char	buff[BUFF_SIZE + 1];

	i = 0;
	total_bytes = 0;
	bytes_read = read(fd, buff, BUFF_SIZE);
	while (bytes_read > 0)
	{
		buff[bytes_read] = '\0';
		ft_terminos_checker(buff, &tetris[i]);
		ft_presets(&tetris[i]);
		tetris[i].i = i;
		i++;
		total_bytes += bytes_read;
		if (total_bytes > 545)
			ft_error();
		bytes_read = read(fd, buff, BUFF_SIZE);
	}
	tetris[i].i = -1;
	if (total_bytes > 545 || (total_bytes % 21) != 20)
		ft_error();
	return (i);
}
