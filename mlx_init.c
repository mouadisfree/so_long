/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:02:57 by mokatfi           #+#    #+#             */
/*   Updated: 2025/04/09 22:46:36 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movestr(t_so *p)
{
	char	*s;
	int		i;

	s = ft_itoa(p->mim);
	i = ft_strlen(s);
	p->mim++;
	write(1, "move number : ", 14);
	write(1, s, i);
	write(1, "\n", 1);
	free(s);
}

void	fcheck_texture(t_so *p)
{
	if (!p->img1 || !p->img2 || !p->img3 || !p->img4 || !p->img5 || !p->img6)
		ft_putstrerror("Error\ninvalid textures\n", p);
}

void	file_image1(t_so *p)
{
	p->img1 = mlx_xpm_file_to_image(p->mlx_ptr, "./textures/wall.xpm", &p->w,
			&p->h);
	p->img2 = mlx_xpm_file_to_image(p->mlx_ptr, "./textures/space.xpm", &p->w,
			&p->h);
	p->img3 = mlx_xpm_file_to_image(p->mlx_ptr, "./textures/collectible.xpm",
			&p->w, &p->h);
	p->img4 = mlx_xpm_file_to_image(p->mlx_ptr, "./textures/door_closed.xpm",
			&p->w, &p->h);
	p->img5 = mlx_xpm_file_to_image(p->mlx_ptr, "./textures/player.xpm", &p->w,
			&p->h);
	p->img6 = mlx_xpm_file_to_image(p->mlx_ptr, "./textures/door_open.xpm",
			&p->w, &p->h);
	fcheck_texture(p);
}

void	util(t_so *p)
{
	p->mim = 0;
	p->mlx_ptr = mlx_init();
	if (!p->mlx_ptr)
	{
		ft_free_it_all(p);
		return ;
	}
	file_image1(p);
	p->mlx_win = mlx_new_window(p->mlx_ptr, ft_strlen(p->map[0]) * p->w,
			count_word(p->buff, '\n') * p->h, "$ freedom $");
	if (!p->mlx_win)
	{
		ft_free_it_all(p);
		return ;
	}
	positions(p);
	movestr(p);
}

void	image_win(t_so *p)
{
	p->i = 0;
	while (p->map[p->i])
	{
		p->j = 0;
		while (p->map[p->i][p->j])
		{
			if (p->map[p->i][p->j] == '0')
				mlx_put_image_to_window(p->mlx_ptr, p->mlx_win, p->img2, p->j
					* p->w, p->i * p->h);
			if (p->map[p->i][p->j] == '1')
				mlx_put_image_to_window(p->mlx_ptr, p->mlx_win, p->img1, p->j
					* p->w, p->i * p->h);
			if (p->map[p->i][p->j] == 'C')
				mlx_put_image_to_window(p->mlx_ptr, p->mlx_win, p->img3, p->j
					* p->w, p->i * p->h);
			if (p->map[p->i][p->j] == 'E')
				mlx_put_image_to_window(p->mlx_ptr, p->mlx_win, p->img4, p->j
					* p->w, p->i * p->h);
			if (p->map[p->i][p->j] == 'P')
				mlx_put_image_to_window(p->mlx_ptr, p->mlx_win, p->img5, p->j
					* p->w, p->i * p->h);
			p->j++;
		}
		p->i++;
	}
}
