/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:56:01 by iortego-          #+#    #+#             */
/*   Updated: 2023/06/01 20:39:35 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG
# define IMG_SIZE 60

# include "mlx.h"
# include "libft.h"



typedef struct s_img {
	void	*img;
	char	*path;
}	t_img;

typedef struct s_player {
	void	*img;
	int		x;
	int		y;
}	t_player;

typedef	struct s_map {
	char	**map;
	int		y;
	int		x;
	int		item;
	t_bool	exit;
}	t_map;

typedef	struct s_mlx {
	void	*mlx;
	void	*win;
}	t_mlx;

void	print_floor(t_map	map, t_img	floor, t_mlx	*mlx);
void	print_static(t_map	map, t_img	*images, t_mlx	*mlx);
void	print_player(t_map	map, t_player	*one, t_mlx	*mlx);
void	print_map(t_map	map, t_mlx	*mlx);


t_bool	check_move(t_map	map, t_player	one); // Repasar logica de movimiento, posible estructura a anadir
t_bool	move_player(t_map	*map,	t_mlx	*mlx);

#endif
