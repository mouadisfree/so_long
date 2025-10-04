/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 02:29:28 by mokatfi           #+#    #+#             */
/*   Updated: 2025/04/10 04:11:39 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/usr/include/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct so_long
{
	char	*buff;
	char	**map;
	char	**map2;
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	void	*img6;
	int		w;
	int		h;
	int		i;
	int		j;
	int		mim;
	int		p_x;
	int		p_y;
	int		x;
	int		y;
	int		a;
	int		b;
	int		coll;
	int		collectible;
	int		exit;
	int		play;
}			t_so;

// parsing
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_read(int fd, char *container);
char		*ft_strdup(const char *s1);
long		ft_digit(long int n);
char		*get_next_line(int fd);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(const char *s);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *str1, const char *str2);
int			count_word(char const *str, char c);
void		check_path(int pos_x, int pos_y, char **map);
void		check_coll(char **map2, t_so *p);
void		positions(t_so *p);
char		*ft_itoa(int n);
void		check_01pec(char **str, t_so *p);
void		check_ber(char *str, t_so *p);
void		check_map_lines(char **str, t_so *p);
void		check_1_extra(char **map, t_so *p);
void		check_1(char **map, t_so *p);
void		player_exit_positions(t_so *p, int x, int y);
void		gnl(char *srt, t_so *p);
void		check_new_line(t_so *p);
// execution
int			ft(int key, t_so *p);
void		ft_left(t_so *p);
void		ft_left1(t_so *p);
void		ft_right(t_so *p);
void		ft_right1(t_so *p);
void		ft_down(t_so *p);
void		ft_down1(t_so *p);
void		ft_up(t_so *p);
void		ft_up1(t_so *p);
void		image_win(t_so *p);
void		util(t_so *p);
void		movestr(t_so *p);
void		file_image1(t_so *p);
void		fcheck_texture(t_so *p);
void		ft_free_it_all(t_so *p);
void		ft_img_free(t_so *p);
void		ft_map_free(char **p);
void		ft_putstrerror(char *str, t_so *so);

#endif