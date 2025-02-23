/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:45:38 by hferjani          #+#    #+#             */
/*   Updated: 2023/06/30 17:17:59 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	setup_more(t_data *data)
{
	data->mlx.img = NULL;
	data->mlx.img_swap = NULL;
	data->mlx.addr = NULL;
	data->mlx.addr_swap = NULL;
	data->texture[0].img = NULL;
	data->texture[1].img = NULL;
	data->texture[2].img = NULL;
	data->texture[3].img = NULL;
	data->texture[4].img = NULL;
	data->texture[0].addr = NULL;
	data->texture[1].addr = NULL;
	data->texture[2].addr = NULL;
	data->texture[3].addr = NULL;
	data->texture[4].addr = NULL;
	data->mlx.mlx_win = NULL;
	data->mlx.mlx_ptr = NULL;
	data->ray.ray_dir.x = 0;
	data->ray.ray_dir.y = 0;
	data->ray.plane.x = 0;
	data->ray.plane.y = 0;
	data->ray.draw_start = 0;
	data->ray.draw_end = 0;
	data->mlx.bits_per_pixel = 0;
	data->mlx.line_length = 0;
	data->mlx.endian = 0;
}

void	setup_game(t_data *data)
{
	data->north = NULL;
	data->south = NULL;
	data->west = NULL;
	data->east = NULL;
	data->height = 0;
	data->floor = -1;
	data->ceiling = -1;
	data->r = -1;
	data->g = -1;
	data->b = -1;
	data->nbr_line = 0;
	data->size_line = 0;
	data->tab = NULL;
	data->f = NULL;
	data->c = NULL;
	data->dx = 0;
	data->dy = 0;
	data->count = 0;
	data->pos_x = 0;
	data->pos_y = 0;
	data->tab_fd = NULL;
	data->begin = 0;
	data->dup = NULL;
	data->negatif = 0;
	setup_more(data);
}

void	ft_init_pos(t_data *data)
{
	data->direction.e = 0;
	data->direction.w = 0;
	data->direction.s = 0;
	data->direction.n = 0;
}

int	verif_env(char **env)
{
	int	i;

	i = 0;
	if (!env || !env[0])
		return (0);
	while (env[i])
	{
		if (ft_strcmp("USER=hferjani", env[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
