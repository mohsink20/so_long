/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:14:27 by mokhan            #+#    #+#             */
/*   Updated: 2023/12/31 16:14:29 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//includes

# include "../mylib/libft/libft.h"
# include "../mylib/get_next_line/get_next_line.h"
# include "../mylib/ft_printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <time.h>

//defines

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define WALL "./src/textures/rock.xpm"
# define WALL_S "./src/textures/rock.xpm"
# define ROCK "./src/textures/rock.xpm"
# define CORNER_TR "./src/textures/rock.xpm"
# define CORNER_TL "./src/textures/rock.xpm"
# define CORNER_BL "./src/textures/rock.xpm"
# define CORNER_BR "./src/textures/rock.xpm"
# define FLOOR "./src/textures/floor.xpm"
# define CHARACTER_W "./src/textures/charfront.xpm"
# define CHARACTER_A "./src/textures/charleft.xpm"
# define CHARACTER_S "./src/textures/charback.xpm"
# define CHARACTER_D "./src/textures/charright.xpm"
# define COLLECTIBLE "./src/textures/apple.xpm"
# define COLLECTIBLE_2 "./src/textures/apple.xpm"
# define ENEMY_W "./src/textures/enemy4.xpm"
# define ENEMY_A "./src/textures/enemy2.xpm"
# define ENEMY_S "./src/textures/enemy1.xpm"
# define ENEMY_D "./src/textures/enemy3.xpm"
# define EXIT "./src/textures/exit.xpm"
# define BLACK "./src/textures/black.xpm"

//struct

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*wall_img;
	void	*wall_s_img;
	void	*rock_img;
	void	*corner_tl;
	void	*corner_tr;
	void	*corner_bl;
	void	*corner_br;
	void	*floor_img;
	void	*char_f_img;
	void	*char_r_img;
	void	*char_l_img;
	void	*char_b_img;
	void	*enemy_w_img;
	void	*enemy_a_img;
	void	*enemy_s_img;
	void	*enemy_d_img;
	void	*coll_img;
	void	*coll_2_img;
	void	*exit_img;
	void	*black_img;
	int		x;
	int		y;
	int		p_x;
	int		p_y;
	int		lines;
	int		columns;
	char	**map;
	int		total_collectibles;
	int		caught_collectibles;
	char	last_side;
	int		moves;
	int		exits;
	int		player;
	int		fd;
}				t_data;

//load_map

int		do_move(t_data *mlx, char flag);
void	load_map(t_data *mlx, char *file);

//moves

void	move_w(t_data *mlx);
void	move_s(t_data *mlx);
void	move_a(t_data *mlx);
void	move_d(t_data *mlx);

//utils_map

int		line_count(char *line, int fd);
char	**map_fill(int fd, char *line, t_data *mlx);
void	player_coordinates(t_data *mlx);
int		check_wall(t_data *mlx, char flag);
void	print_map(char **map);

//free

int		free_the_map(char **map, t_data *mlx);
int		ft_xbutton(t_data *mlx);
int		free_invalid_map(t_data *mlx);
void	free_map(char **map);
int		free_invalid_fd(t_data *mlx);

//free2

void	free_elements(char **map);
int		free_invalid_chars(t_data *mlx);
int		free_invalid_map2(t_data *mlx);

//utils

void	struct_initialize(t_data *mlx);
void	free_elements(char **map);
int		ft_keypress(int keysym, t_data *mlx);
size_t	ft_len(const char *str);
int		check_for_players(t_data *mlx, char c);

//utils2

int		map_verifications(t_data *mlx);
int		mapname(char *str);
int		line_length(t_data *mlx);
void	three_columns(t_data *mlx, char *move_number);

//utils3

int		valid_path(t_data *mlx, char **map, int x, int y);
char	**duplicate_map(t_data *mlx);
int		closed_map(t_data *mlx);
int		check_letters(char *str, char c);
int		map_verifications2(t_data *mlx);

//utils4

void	xpm_to_image(t_data *mlx);
void	xpm_to_image2(t_data *mlx);
int		check_invalid_chars(char **map);
void	map_prepare(t_data *mlx, char *file);
void	insert_wall(t_data *mlx, int i, int j);

//utils5

void	insert_others(t_data *mlx, int i, int j);
int		put_walls(t_data *mlx, int i, int j);
int		ft_animation(t_data *mlx);
void	collectible_coordinates(t_data *mlx, int flag);
void	check_position(t_data *mlx);

//enemies

void	ft_enemies(t_data *mlx);
void	scan_for_enemies(t_data *mlx, int flag);
void	enemy_move(t_data *mlx, int flag, int y, int x);
int		do_enemy_move(t_data *mlx, char flag, int y, int x);
void	put_enemy(t_data *mlx, int y, int x, char flag);

//get_next_line

char	*get_next_line(int fd);

#endif
