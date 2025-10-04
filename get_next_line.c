/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 02:33:08 by mokatfi           #+#    #+#             */
/*   Updated: 2025/04/09 22:46:14 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*g;
	int		i;
	int		j;

	i = 0;
	g = malloc(sizeof(char) * (ft_strlen(s2) + ft_strlen(s1)) + 1);
	if (!g)
	{
		free(s1);
		return (NULL);
	}
	while (s1 && s1[i])
	{
		g[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
		g[i++] = s2[j++];
	g[i] = '\0';
	free(s1);
	return (g);
}

char	*ft_read(int fd, char *container)
{
	char	*buff;
	int		i;

	i = 1;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			free(container);
			return (NULL);
		}
		buff[i] = '\0';
		container = ft_strjoin(container, buff);
		if (!container)
			return (NULL);
	}
	free(buff);
	return (container);
}

char	*get_next_line(int fd)
{
	static char	*s;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s = ft_read(fd, s);
	if (!s)
		return (NULL);
	return (s);
}

void	gnl(char *srt, t_so *p)
{
	int	fd;

	fd = open(srt, O_RDWR);
	if (fd == -1)
		ft_putstrerror("Error\ncan't open file\n", p);
	p->buff = get_next_line(fd);
	if (!p->buff)
		ft_putstrerror("gnl failed\n", p);
	check_new_line(p);
	p->map = ft_split(p->buff, '\n');
	p->map2 = ft_split(p->buff, '\n');
	if (!p->map || !p->map2)
		ft_putstrerror("split failed\n", p);
}
