/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_presets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:44:02 by mbarutel          #+#    #+#             */
/*   Updated: 2022/02/08 17:30:27 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_presets(t_tetris *tetri)
{
	int	i;

	i = 0;
	tetri->max_y = 0;
	tetri->max_x = 0;
	tetri->preset_x = 0;
	while (i < 3)
	{
		if (tetri->y[i] > tetri->max_y)
			tetri->max_y = tetri->y[i];
		if (tetri->x[i] > tetri->max_x)
			tetri->max_x = tetri->x[i];
		if (tetri->x[i] < tetri->preset_x)
			tetri->preset_x = tetri->x[i];
		i++;
	}
	tetri->preset_x = tetri->preset_x * -1;
}
