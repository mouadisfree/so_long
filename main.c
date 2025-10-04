/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 02:29:51 by mokatfi           #+#    #+#             */
/*   Updated: 2025/04/09 22:46:18 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_null(t_so *p)
{
	(void)p;
	return (NULL);
}

void	ft_initializations(t_so *p)
{
	p->mlx_ptr = NULL;
	p->mlx_win = NULL;
	p->img1 = NULL;
	p->img2 = NULL;
	p->img3 = NULL;
	p->img4 = NULL;
	p->img5 = NULL;
	p->img6 = NULL;
	p->map = NULL;
	p->map2 = NULL;
	p->buff = NULL;
}

int	ft(int key, t_so *p)
{
	if (key == 65307)
	{
		ft_free_it_all(p);
		exit(0);
	}
	if (key == 65362 || key == 119)
		ft_up(p);
	if (key == 65364 || key == 115)
		ft_down(p);
	if (key == 65363 || key == 100)
		ft_right(p);
	if (key == 65361 || key == 97)
		ft_left(p);
	return (0);
}

int	destroy(t_so *p)
{
	ft_free_it_all(p);
	exit(0);
}

int	main(int ac, char **av)
{
	t_so	*p;

	p = malloc(sizeof(t_so));
	if (!p)
		ft_null(p);
	ft_initializations(p);
	if (ac == 2)
	{
		gnl(av[1], p);
		check_ber(av[1], p);
		check_01pec(p->map, p);
		check_1(p->map, p);
		check_map_lines(p->map, p);
		positions(p);
		check_path(p->p_x, p->p_y, p->map2);
		check_coll(p->map2, p);
		util(p);
		image_win(p);
		mlx_hook(p->mlx_win, 17, 0, destroy, p);
		mlx_hook(p->mlx_win, 2, 1, ft, p);
		mlx_loop(p->mlx_ptr);
	}
	else
		ft_putstrerror("Error\ninvalid number of arguments\n", p);
}
