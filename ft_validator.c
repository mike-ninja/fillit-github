/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:35:34 by mbarutel          #+#    #+#             */
/*   Updated: 2022/02/03 18:00:21 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define BUFF_SIZE 21

static void	ft_error(void)
{
	ft_putstr("Error.\n");
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
	int	f_h;
	int	ret;

	ret = 0;
	if (!hash)
		f_h = i;
	if (i > 0 && buff[-1] == '#')
		ret++;
	if (i < 19 && buff[1] == '#')
		ret++;
	if (i < 14 && buff[5] == '#')
		ret++;
	if (i > 4 && buff[-5] == '#')
		ret++;
	if (hash > 0)
	{
		tetri->x[hash - 1] = (i % 5) - (f_h % 5);
		tetri->y[hash - 1] = (i / 5) - (f_h / 5);
	}
	return (ret);
}

static void	ft_terminos_checker(char *buff, t_tetris *tetri)
{
	int	i;
	int	hash;

	i = 0;
	hash = 0;
	ft_nl_check(buff);
	while (buff[i] == '.' || buff[i] == '\n' || buff[i] == '#')
	{
		if (buff[i] == '#')
		{
			if (ft_check_adjacent(&buff[i], i, tetri, hash))
				hash++;
			else
				ft_error();
		}
		i++;
	}
	if (hash != 4 || buff[i] != '\0')
		ft_error();
}

int	ft_validator(int fd, t_tetris *head)
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
		ft_terminos_checker(buff, &head[i]);
		head[i].i = i;;
		i++;
		total_bytes += bytes_read;
		bytes_read = read(fd, buff, BUFF_SIZE);
	}
	if (total_bytes > 546 || (total_bytes % 21) != 20)
		ft_error();
	return (i);
}
