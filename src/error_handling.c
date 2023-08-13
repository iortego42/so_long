/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:24:11 by iortego-          #+#    #+#             */
/*   Updated: 2023/07/10 18:21:46 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_matrix(void	***m, int index)
{
	if (m == NULL)
		return ;
	if (*m == NULL)
		return (free(m));
	while (index >= 0)
	{
		free(m[index]);
		m[index] = NULL;
		index--;
	}
	free(m);
	m = NULL;
}
