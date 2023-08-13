/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:11:53 by iortego-          #+#    #+#             */
/*   Updated: 2023/08/13 18:54:57 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_map(t_map	**map)
{
	clear_matrix((void ***)&(*map)->map, (*map)->dim.y);
	if ((*map)->path != NULL)
	{
		free((*map)->path);
		(*map)->path = NULL;
	}
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
	clear_map(&d->map);
}

t_err_code	error(t_game *d, t_err_code error)
{
	delete_data(d);
	select_error(error);
	return (error);
}
