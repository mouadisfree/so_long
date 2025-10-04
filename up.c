/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:16:02 by mokatfi           #+#    #+#             */
/*   Updated: 2025/04/10 04:03:59 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_up1(t_so *p)
{
	if (p->map[p->p_x - 1][p->p_y] == '0')
	{
		mlx_put_image_to_window(p->mlx_ptr, p->mlx_win, p->img2, p->p_y * p->w,
			p->p_x * p->h);
		p->map[p->p_x][p->p_y] = '0';
		p->p_x = p->p_x - 1;
		mlx_put_image_to_window(p->mlx_ptr, p->mlx_win, p->img5, p->p_y * p->w,
			p->p_x * p->h);
		movestr(p);
	}
	else if (p->map[p->p_x - 1][p->p_y] == 'C')
	{
		p->map[p->p_x][p->p_y] = '0';
		mlx_put_image_to_window(p->mlx_ptr, p->mlx_win, p->img2, p->p_y * p->w,
			p->p_x * p->h);
		p->p_x = p->p_x - 1;
		p->coll--;
		mlx_put_image_to_window(p->mlx_ptr, p->mlx_win, p->img5, p->p_y * p->w,
			p->p_x * p->h);
		movestr(p);
	}
}

void	ft_up(t_so *p)
{
	if (p->map[p->p_x - 1][p->p_y] == 'E')
	{
		if (p->coll == 0)
		{
			movestr(p);
			write(1, "you won!\n", 9);
			ft_free_it_all(p);
			exit(0);
		}
	}
	else
	{
		ft_up1(p);
		if (p->coll == 0)
		{
			mlx_put_image_to_window(p->mlx_ptr, p->mlx_win, p->img6, p->y
				* p->w, p->x * p->h);
		}
	}
}
