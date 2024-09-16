/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_carte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <imraoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:57:06 by hferjani          #+#    #+#             */
/*   Updated: 2023/11/06 14:43:38 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strlen2(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_backtacking(t_data *data, int i, int j)
{
	if (i >= 0 && i < data->height && j >= 0 && j < ft_strlen2(data->dup[i])
		&& data->dup[i][j])
	{
		if (data->dup[i][j] == '0' || data->dup[i][j] == 'N'
			|| data->dup[i][j] == 'E' || data->dup[i][j] == 'S'
			|| data->dup[i][j] == 'W')
			data->dup[i][j] = 'P';
		else
			return (0);
		ft_backtacking(data, i, j + 1);
		ft_backtacking(data, i, j - 1);
		ft_backtacking(data, i + 1, j);
		ft_backtacking(data, i - 1, j);
	}
	return (0);
}

int	check_p(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->dup[i])
	{
		j = 0;
		while (data->dup[i][j])
		{
			if (data->dup[i][j] == 'P' && (i == 0 || i == data->height - 1))
				return (1);
			else if (data->dup[i][j] == 'P' && (j == 0 || data->dup[i][j
						+ 1] == '\n' || data->dup[i][j + 1] == '\0'
						|| data->dup[i][j + 1] == ' '))
				return (1);
			else if (i - 1 <= 0)
				if (data->dup[i][j] == 'P' && ((data->dup[i + 1][j] == ' ')
						|| (data->dup[i - 1][j] == ' ')))
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_dup(t_data *map)
{
	int	i;

	i = 0;
	map->dup = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->dup)
		return (1);
	map->dup[map->height] = NULL;
	while (map->tab[i])
	{
		map->dup[i] = ft_strdup(map->tab[i]);
		i++;
	}
	map->dup[i] = '\0';
	i = 0;
	ft_backtacking(map, map->pos_x, map->pos_y);
	check_p(map);
	if (check_p(map) == 1)
		return (1);
	return (0);
}
