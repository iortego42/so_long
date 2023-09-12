/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:24:11 by iortego-          #+#    #+#             */
/*   Updated: 2023/09/12 19:46:22 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_matrix(void	***m, int index)
{
	if (m == NULL)
		return ;
	if (*m == NULL)
		return (free(m));
	while (--index >= 0)
	{
		free((*m)[index]);
		(*m)[index] = NULL;
	}
	free(*m);
	*m = NULL;
}

void	clear_imgs(t_img	**imgs)
{
	int	index;

	index = 0;
	if (!imgs || !*imgs)
		return ;
	while (index < N_ITEMS)
	{
		if ((*imgs)[index].path)
		{
			free((*imgs)[index].path);
			(*imgs)[index].path = NULL;
		}
		if ((*imgs)[index].img != NULL)
		{
			free((*imgs)[index].img);
			(*imgs)[index].img = NULL;
		}
		index++;
	}
	free(*imgs);
	*imgs = NULL;
}