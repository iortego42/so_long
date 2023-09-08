/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:56:01 by iortego-          #+#    #+#             */
/*   Updated: 2023/09/05 18:43:30 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define IMG_WIDTH 50
# define IMG_HEIGHT 50
# define ITEMS "01CEP"
# define ALLOWED_EXT ".ber"
# define PATH "/Users/iortego-/github/so_long/"
# define MAP_PATH "./map.ber"
# define IMG_PATH "./img/"
# define KEY_ESC	53
# define CLOSE_WIN	17
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2


# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include "get_next_line.h"

typedef enum s_item {
	F,
	W,
	C,
	E,
	P,
	N_ITEMS
}	t_item;

typedef enum s_err {
	OK,
	EC_UNDEFINED,
	EC_INVALID_CHAR,
	EC_NO_EXIT,
	EC_NO_PLAYER,
	EC_WALLED,
	EC_NOT_SYM,
	EC_MALLOC,
	EC_NOT_VALID_MAP,
	EC_NOT_FILE,
	EC_NOT_IMG,
	EC_INVALID_ARGS,
	EC_SIZE
}	t_err_code;

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

typedef struct s_map {
	char	**map;
	t_coor	dim;
	int		items;
	t_coor	exit;
	char	*path;
}	t_map;

typedef struct s_mlx {
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_game {
	t_bool		can_exit;
	t_player	*player;
	t_map		*map;
	t_mlx		*mlx;
	t_img		*imgs;
}	t_game;



static const char* g_imgfiles[N_ITEMS] = {
[C] = "floor.xpm",
[P] = "wall.xpm",
[F] = "collectionable.xpm",
[W] = "exit.xpm",
[E] = "player.xpm"
};

static const char* g_error_mess[EC_SIZE] = {
[EC_UNDEFINED] = "\033[35mUndefined\033[0m\n",
[EC_INVALID_CHAR] = "Invalid char on map\n",
[EC_NO_EXIT] = "Invalid number of exit on map\n",
[EC_NO_PLAYER] = "Invalid number of player on map\n",
[EC_WALLED] = "Map not walled\n",
[EC_NOT_SYM] = "Map not symmetric\n",
[EC_MALLOC] = "Malloc\n",
[EC_NOT_VALID_MAP] = "Not valid map\n",
[EC_NOT_FILE] = "File not found\n",
[EC_NOT_IMG] = "Could not find images\n",
[EC_INVALID_ARGS] = "Invalid number of arguments\n",
};
t_err_code	get_map_path(int	argc, char	*argv[]);
t_err_code	init(t_game **game, char	*map_path);
//
//	Parseo del mapa
//		- Simetria
//		- Caracteres validos
//		- Salida valida
//		- Rodeado de pared
//	
t_err_code	open_file(char *file, void	*(*fun)(int), void	**data);
t_map		*get_map(int fd);
int			get_line_lenght(char	*line);
t_bool		is_valid_char(t_map	*map);
t_bool		is_sym(t_map	*map);
t_bool		is_walled(t_map	*map);
t_bool		is_one_player_exit(t_map	*map);
t_err_code	parse_map(t_map	*map);
t_map		*copy_map(t_map map);
t_bool		check_map(t_map *map, t_coor pos, t_bool *exit_is_reach);
//
//	Impresion del mapa 
//
int			get_items(t_map	map);
t_img		*get_imgs(t_mlx	*mlx, char	*pathtoimgs);
void		print_floor(t_map	map, t_img	floor, t_mlx	*mlx);
void		print_static(t_map	map, t_img	*images, t_mlx	*mlx);
void		print_player(t_player	*one, t_mlx	*mlx);
int			reload_map(t_game	*game);
//
//	Jugador
//
t_player	*player_constructor(t_map	map, t_img	*img);
void		collect(t_game	*game);
int			is_exit(t_game	*game);
//	Movimiento del jugador
//
int			listener(int keycode, t_game	*game);
t_bool		is_reacheble(t_coor	pos, t_coor	next_pos);
t_bool		check_move(t_game	*game, t_coor	next_pos);
void		move_player(t_game	*game, t_coor	move);
void		print_moves(int moves);
//
// Errores
//
void		clear_matrix(void	***m, int index);
void		clear_map(t_map	**map);
void		delete_data(t_game	*d);
void		spawn_error_message(const char *message);
void		select_error(t_err_code code);
t_err_code	error(t_game *d, t_err_code error);
#endif
