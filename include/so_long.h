/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:56:01 by iortego-          #+#    #+#             */
/*   Updated: 2023/06/07 19:09:03 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG
# define IMG_SIZE 60
# define ITEMS "01CEP"
# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include "get_next_line.h"


typedef enum {F,W,C,E,P, NITEMS} t_item;

typedef struct s_coor {
	int	x;
	int	y;
}	t_coor;
typedef struct s_img {
	void	*img;
	char	*path;
}	t_img;

typedef struct s_player {
	void	*img;
	t_coor	next;
	t_coor	pos;
}	t_player;

typedef	struct s_map {
	char	**map;
	t_coor	dim;
	int		item;
	t_bool	exit;
}	t_map;

typedef	struct s_mlx {
	void	*mlx;
	void	*win;
}	t_mlx;

//
//	Parseo del mapa
//		- Simetria
//		- Caracteres validos
//		- Salida valida
//		- Rodeado de pared
//	
t_map	*get_map(char	*path);
int		get_line_lenght(char	*line);
t_bool	is_item(t_map	*map);
t_bool	is_sym(t_map	*map);
t_bool	is_walled(t_map	*map);
t_map	parse_map(char	*path);
//
//	Impresion del mapa 
//
void	print_floor(t_map	map, t_img	floor, t_mlx	*mlx);
void	print_static(t_map	map, t_img	*images, t_mlx	*mlx);
void	print_player(t_map	map, t_player	*one, t_mlx	*mlx);
void	print_map(t_map	map, t_mlx	*mlx);
//
//	Movimiento del jugador
//
t_bool	check_move(t_map	map, t_player	one); 
t_bool	move_player(t_map	*map, t_player	*one, t_mlx	*mlx);
//
// Errores
//
void	clear_strmap(t_map);
#endif
