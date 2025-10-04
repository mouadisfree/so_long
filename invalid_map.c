/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 02:34:00 by mokatfi           #+#    #+#             */
/*   Updated: 2025/04/08 16:55:32 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_1_extra(char **map, t_so *p)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			ft_putstrerror("Error\ninvalid boundaries\n", p);
		i++;
	}
}

void	check_1(char **map, t_so *p)
{
	int	i;
	int	len;

	len = 0;
	while (map[len])
		len++;
	i = 0;
	while (map[0][i] && map[len - 1][i])
	{
		if (map[0][i] != '1' || map[len - 1][i] != '1')
			ft_putstrerror("Error\ninvalid boundaries\n", p);
		i++;
	}
	check_1_extra(map, p);
}

void	check_01pec(char **str, t_so *p)
{
	p->collectible = 0;
	p->exit = 0;
	p->play = 0;
	p->a = -1;
	while (str[++p->a])
	{
		p->b = -1;
		while (str[p->a][++p->b])
		{
			if (str[p->a][p->b] == 'C')
				p->collectible++;
			else if (str[p->a][p->b] == 'E')
				p->exit++;
			else if (str[p->a][p->b] == 'P')
				p->play++;
			else if (str[p->a][p->b] != '0' && str[p->a][p->b] != '1')
				ft_putstrerror("Error\ninvalid character\n", p);
		}
	}
	if (p->exit != 1 || p->play != 1 || p->collectible < 1)
		ft_putstrerror("Error\nmissing elements\n", p);
}

void	check_ber(char *str, t_so *p)
{
	int		i;
	char	*s;
	char	*ss;

	i = 0;
	s = ft_strrchr(str, '.');
	if (str[0] == '.' || ft_strncmp(s, ".ber") != 0)
		ft_putstrerror("Error\ninvalid extention (.ber)\n", p);
	ss = ft_strrchr(str, '/');
	if (!ss)
		return ;
	while (ss[i])
		i++;
	if (i < 6)
		ft_putstrerror("Error\ninvalid extention (.ber)\n", p);
}

void	check_new_line(t_so *p)
{
	int	i;

	i = 0;
	while (p->buff[i])
	{
		if (p->buff[0] == '\n')
			ft_putstrerror("Error\nthere is a new line\n", p);
		else if (p->buff[i] == '\n' && p->buff[i + 1] == '\n')
			ft_putstrerror("Error\nthere is a new line\n", p);
		else if (p->buff[i] == '\n' && p->buff[i + 1] == '\0')
			ft_putstrerror("Error\nthere is a new line\n", p);
		i++;
	}
}
