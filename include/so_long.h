/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:56:01 by iortego-          #+#    #+#             */
/*   Updated: 2023/07/23 16:27:56 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG
# define IMG_WIDTH 50
# define IMG_HEIGHT 50
# define ITEMS "01CEP"
# define ALLOWED_EXT ".ber"
# define PATH "/Users/nachh/github/so_long/"
# define MAP_PATH "map.ber"
# define IMG_PATH "./img/"
# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2


# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include "get_next_line.h"





typedef enum {F,W,C,E,P, N_ITEMS} t_item;

typedef struct s_coor {
	int	y;
	int	x;
}	t_coor;
typedef struct s_img {
	void	*img;
	char	*path;
	int		width;
	int		height;
}	t_img;

typedef struct s_player {
	t_img	*img_s;
	t_coor	pos;
	int		move_counter;
}	t_player;

typedef	struct s_map {
	char	**map;
	t_coor	dim;
	int		item;
	t_coor	exit;
	char 	*path;
}	t_map;

typedef	struct s_mlx {
	void	*mlx;
	void	*win;
}	t_mlx;

typedef	struct s_game {
	int			collectionable;
	int			players;
	t_bool		can_exit;
	t_player	*player;
	t_map		*map;
	t_mlx		*mlx;
	t_img		*imgs;
}	t_game;


static const char* g_imgfiles[N_ITEMS] = 
{
		[F] = "floor.xpm",
		[W] = "wall.xpm",
		[C] = "collectionable.xpm",
		[E] = "exit.xpm",
		[P] = "player.xpm"
};
t_game	*init();
//
//	Parseo del mapa
//		- Simetria
//		- Caracteres validos
//		- Salida valida
//		- Rodeado de pared
//	
void	*open_file(char *file, void	*(*fun)(int)); 
t_map	*get_map(int	fd);
int		get_line_lenght(char	*line);
t_bool	is_valid_char(t_map	*map);
t_bool	is_sym(t_map	*map);
t_bool	is_walled(t_map	*map);
t_bool	is_one_player_exit(t_map	*map);
t_bool	parse_map(t_map	*map);
//
//	Impresion del mapa 
//
t_img	*get_imgs(t_mlx	*mlx, char	*pathtoimgs);
void	print_floor(t_map	map, t_img	floor, t_mlx	*mlx);
void	print_static(t_map	map, t_img	*images, t_mlx	*mlx);
void	print_player(t_player	*one, t_mlx	*mlx);
void	reload_map(t_map	map, t_img *images, t_player *one, t_mlx	*mlx);
//
//	Jugador
//
t_player	*player_constructor(t_map	map, t_img	*img);
void		collect(t_game	*game);
//	Movimiento del jugador
//
int			listener(int	keycode, t_game	*game);
t_bool		is_reacheble(t_coor	pos, t_coor	next_pos);
t_bool		check_move(t_game	*game, t_coor	next_pos);
void		move_player(t_game	*game, t_coor	move);
void		print_moves(int	moves);
//
// Errores
//
void	clear_strmap(t_map);
void	clear_matrix(void	***m, int index);
#endif
