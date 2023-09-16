/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:11:53 by iortego-          #+#    #+#             */
/*   Updated: 2023/09/16 11:07:17 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_map(t_map	**map)
{
	if (map != NULL && *map != NULL)
	{
		if ((*map)->map != NULL)
			clear_matrix((void ***)&(*map)->map, (*map)->dim.y);
	}
	free(*map);
	*map = NULL;
}

void	spawn_error_message(const char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd((char *)message, 2);
}

void	select_error(t_err_code code)
{
	if (code == OK)
		code = EC_UNDEFINED;
	spawn_error_message(g_error_mess[code]);
}

void	delete_data(t_game *d)
{
	if (d->map != NULL)
		clear_map(&d->map);
	if (d->player != NULL)
	{
		if (d->player->img_s->path)
			free(d->player->img_s->path);
		free(d->player);
		d->player = NULL;
	}
	if (d->imgs)
		clear_imgs(d->mlx, &d->imgs);
	if (d->mlx)
	{
		mlx_destroy_window(d->mlx->mlx, d->mlx->win);
		d->mlx->win = NULL;
		free(d->mlx);
	}
	free(d);
}

t_err_code	error(t_game *d, t_err_code error)
{
	if (d)
		delete_data(d);
	select_error(error);
	exit(error);
}
