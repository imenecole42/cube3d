/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:54:35 by hferjani          #+#    #+#             */
/*   Updated: 2023/06/30 17:15:02 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// # include "libs/minilibx/mlx.h"
# include "libs/libft/get_next_line.h"
# include "libs/libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>

/* Colors */
# define DEFAULT "\001\e[00;39m\002"
# define GREY "\001\e[1;90m\002"
# define RED "\001\e[1;91m\002"
# define GREEN "\001\e[0;92m\002"
# define YELLOW "\001\e[1;93m\002"
# define BLUE "\001\e[1;94m\002"
# define MAGENTA "\001\e[1;95m\002"
# define PINK "\001\e[0;35m\002"
# define PURPLE "\001\e[0;34m\002"
# define CYAN "\001\e[1;96m\002"
# define WHITE "\001\e[0;97m\002"

/*Display*/

# define DISPLAY_HEIGHT 400
# define DISPLAY_WIDTH 640

# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3

# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define A_KEY 97
# define W_KEY 119
# define S_KEY 115
# define D_KEY 100

# define ROTATE_LEFT 65361
# define ROTATE_RIGHT 65363
# define FORWARD_W 119
# define BACK_S 115
# define RIGHT_D 100
# define LEFT_A 97
# define ESCAPE 65307

/*Textures*/

# define TEX_NBR 8
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

# define PI 3.14159265359
# define TWO_PI 6.28318530718
//# define FOV_ANGLE (60 * (PI / 180))
# define SPEED 0.09
# define ROT_SPEED 0.09

/*Structures*/
typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct s_texture
{
	int			texdir;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
}				t_texture;

typedef struct s_ray
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	t_vector	ray_dir;
	double		camera_x;
	int			map_x;
	int			map_y;
	t_vector	side_dist;
	t_vector	delta_dist;
	int			step_x;
	int			step_y;
	int			side;
	int			hit;
	double		perp_wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		move_speed;
	double		rot_speed;
	int			x;
	int			texture;
}				t_ray;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*mlx_win;
	void		*img;
	void		*img_swap;
	int			*addr;
	int			*addr_swap;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;

	int			forward;
	int			back;
	int			left;
	int			right;
	int			rotate_left;
	int			rotate_right;
	int			scale;
}				t_mlx;

typedef struct s_pos
{
	int			n;
	int			s;
	int			e;
	int			w;

}				t_pos;

typedef struct s_data
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		**tab_fd;
	char		**tab;
	char		**dup;
	int			nbr_line;
	char		*c;
	char		*f;
	char		starting_pos;
	int			c_rgb[3];
	int			f_rgb[3];
	int			height;
	int			width;
	int			dx;
	int			dy;
	int			count2;
	int			size_line;
	int			ceiling;
	int			floor;
	int			r;
	int			g;
	int			b;
	int			count;
	int			pos_x;
	int			pos_y;
	int			begin;
	t_ray		ray;
	t_mlx		wall_north;
	t_mlx		wall_south;
	t_mlx		wall_east;
	t_mlx		wall_west;
	t_mlx		texture[4];
	t_mlx		mlx;
	t_mlx		minimap;
	t_pos		direction;
	t_texture	t;
	int			fdn;
	int			fds;
	int			fdw;
	int			fde;
	int			negatif;
	int			n;
	int			s;
	int			w;
	int			e;
}				t_data;

void			close_fd(t_data *map);
int				ft_check_cub(char *str);
int				ft_check_dir(char **str, t_data *map);
int				ft_check_tab_fd(t_data *map);
int				check_in_color_arg(char *str);
int				parse_rgb(t_data *map, char **tmp, char c);
int				check_color_format(char *str, char c, t_data *map);
int				ft_check_color_arg(char *str, char c);
int				ft_check_argcolor(char **str, t_data *map);
void			check_dir(char *str, int *j, t_data *map);
int				ft_check_map_dir(char **str, t_data *map);
void			setup_game(t_data *data);
int				ft_check_line_fd(char *str);
int				ft_check_fd(t_data *map);
int				ft_parsing_fd(t_data *map, char **argv);
int				ft_parsing_fd2(t_data *map, char **argv);
int				ft_parsing_fd3(t_data *map, char **argv);
//int				ft_check_parse_dir(char **str);
int				ft_check_parse_dir(t_data *map);
int				ft_check_carte_line_empty(t_data *map);
int				ft_check_line_empty(char *str);
int				ft_check_parse_rgb(char **str);
void			count_ligne_valid(char *str, int *j, int *i);
int				ft_check_map_fd(t_data *map, char **str);
int				check_map(char *str);
int				parse_map(t_data *map);
int				msg_err(char *msg, char *argv);
int				ft_isspace(char c);
void			ft_free(char **str);
int				ft_check_char(char *str);
long int		count_lines(char *argv);
void			get_fd(char **argv, t_data *map, long int size);
void			destroy_mlx(t_data *map);
int				ft_check_carte_line_empty(t_data *map);
int				ft_check_nbr_player(char **str);
int				pos_player(char **str, t_data *map);
int				check_player(t_data *map);
void			ft_init_pos(t_data *data);
void			ft_bzero_dup(char *dup);
int				ft_dup(t_data *map);
int				ft_check_symbol(t_data *map);
void			ft_free_dir(t_data *map);
void			check_dir2(char **split, int *j, t_data *map);
void			ft_sidedist2(t_data *game);

void			assign_direction(t_data *data);

void			init_img(t_data *map);
int				verif_env(char **env);
void			ft_set_minimap(t_data *map);
void			initialise_img(t_data *data);
void			initialise_window(t_data *data);
void			initialise_minimap(t_data *data);
int				ft_initialise_and_create_window(t_data *data);
int				exit_game(t_data *map);
void			set_player_pos(t_data *data, char **map);
void			ft_setup(t_data *data);
void			setup_player(t_data *data);
// void			mlx_render_draw_line(void *mlx_ptr, void *win_ptr, int x1,
// 					int y1, int x2, int y2, int color);
int				press_key(int key_code, t_data *map);
int				release_key(int key_code, t_data *map);
void			img_pix_put_color(t_data *data, int x, int y, int color);

void			init_north(t_data *data);
void			init_south(t_data *data);
void			init_east(t_data *data);
void			init_west(t_data *data);

/* Render */
int				render_all(t_data *data);
void			ft_color_sky_and_floor(t_data *data);

/* Raycasting */
void			raycasting(t_data *data);
void			init_raycasting_var(t_data *data, int x);
void			calculate_step_and_side_dist(t_data *data);
void			calculate_step(t_data *data);
void			calculate_side_dist(t_data *data);
void			draw_each_column(t_data *data, int x);

/*Draw*/
void			draw(t_data *data, int x, int texture);

/*Moves*/
void			rotate(t_data *data, double rotation_speed);

int				ft_raycasting(t_data *game);
void			ft_init(t_data *game);
void			ft_textures(t_data *game);
void			init_again(t_data *data, int x);
void			init_again2(t_data *game);
void			ft_sidedist(t_data *game);
void			ft_increment_ray(t_data *game);
void			ft_startend(t_data *game);
int				display_column(t_data *game, int x);
void			display_texture(t_data *game, int x, int y);
void			ft_move_forward_back(t_data *data, char sign);
void			ft_move_left_right(t_data *data, char sign);
void			ft_forward_back(t_data *game);
void			ft_left_right(t_data *game);
void			ft_rotate_left(t_data *game);
void			ft_rotate_right(t_data *game);
void			ft_swap(t_data *game);
int				ft_press(int keycode, t_data *game);
int				ft_release(int keycode, t_data *game);
#endif