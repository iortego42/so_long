/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:17:02 by iortego-          #+#    #+#             */
/*   Updated: 2023/05/31 20:20:08 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	put_pixel(t_img *d, int x, int y, int color)
{
	char	*dst;

	dst = d->addr + (y * d->line_length + x * (d->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
