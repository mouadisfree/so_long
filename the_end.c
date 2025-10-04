/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:27:53 by mokatfi           #+#    #+#             */
/*   Updated: 2025/04/09 22:46:29 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstrerror(char *str, t_so *so)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	ft_free_it_all(so);
	exit(1);
}

void	ft_img_free(t_so *p)
{
	if (p->img1)
		mlx_destroy_image(p->mlx_ptr, p->img1);
	if (p->img2)
		mlx_destroy_image(p->mlx_ptr, p->img2);
	if (p->img3)
		mlx_destroy_image(p->mlx_ptr, p->img3);
	if (p->img4)
		mlx_destroy_image(p->mlx_ptr, p->img4);
	if (p->img5)
		mlx_destroy_image(p->mlx_ptr, p->img5);
	if (p->img6)
		mlx_destroy_image(p->mlx_ptr, p->img6);
}

void	ft_map_free(char **p)
{
	int	i;

	i = 0;
	while (p[i])
		free(p[i++]);
	free(p);
}

void	ft_free_it_all(t_so *p)
{
	if (p->buff)
		free(p->buff);
	if (p->img1 || p->img2 || p->img3 || p->img4 || p->img5 || p->img6)
		ft_img_free(p);
	if (p->map)
		ft_map_free(p->map);
	if (p->map2)
		ft_map_free(p->map2);
	if (p->mlx_win)
		mlx_destroy_window(p->mlx_ptr, p->mlx_win);
	if (p->mlx_ptr)
	{
		mlx_destroy_display(p->mlx_ptr);
		free(p->mlx_ptr);
	}
	if (p)
		free(p);
}
