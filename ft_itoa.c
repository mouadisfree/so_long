/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 02:40:30 by mokatfi           #+#    #+#             */
/*   Updated: 2025/04/07 20:25:39 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

long	ft_digit(long int n)
{
	long	i;

	i = 0;
	if (n <= 0)
	{
		n *= -1;
		i++;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*p;
	int			i;
	long int	h;

	h = (long int)n;
	i = ft_digit(h);
	p = malloc(sizeof(char) * i + 1);
	if (!p)
		return (NULL);
	p[i] = '\0';
	i -= 1;
	if (h == 0)
		p[0] = 48;
	if (h < 0)
	{
		h *= -1;
		p[0] = '-';
	}
	while (h != 0)
	{
		p[i] = h % 10 + 48;
		h = h / 10;
		i--;
	}
	return (p);
}
