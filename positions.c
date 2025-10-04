/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 09:39:56 by mokatfi           #+#    #+#             */
/*   Updated: 2025/04/07 20:26:33 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_exit_positions(t_so *p, int x, int y)
{
	if (p->map[x][y] == 'E')
	{
		p->x = x;
		p->y = y;
	}
	if (p->map[x][y] == 'P')
	{
		p->p_x = x;
		p->p_y = y;
	}
}

void	positions(t_so *p)
{
	int	i;
	int	j;
	int	coll;

	coll = 0;
	i = 0;
	while (p->map[i])
	{
		j = 0;
		while (p->map[i][j])
		{
			player_exit_positions(p, i, j);
			if (p->map[i][j] == 'C')
				coll++;
			j++;
		}
		i++;
	}
	p->coll = coll;
}
