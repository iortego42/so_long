/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:55:39 by iortego-          #+#    #+#             */
/*   Updated: 2023/09/05 19:17:43 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_img	img;
// 	int		offset;
// 	int		y;
// 	int		x;
//
// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hola Alvaro que tal estas?");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	mlx_loop(mlx);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// }
t_err_code	init(t_game **game,char	*map_path)
{
	t_err_code	error_code;

	*game = (t_game *)malloc(sizeof(t_game));
	if (!*game)
		return (EC_MALLOC);
	(*game)->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!(*game)->mlx)
		return (EC_MALLOC);
	error_code = open_file(map_path, (void *)get_map, (void	**)&(*game)->map);
	if (error_code)
		return (error_code);
	error_code = parse_map((*game)->map);
	if (error_code)
		return (error_code);
	(*game)->mlx->mlx = mlx_init();
	(*game)->mlx->win = mlx_new_window((*game)->mlx->mlx, (*game)->map->dim.x
			* IMG_WIDTH, (*game)->map->dim.y * IMG_HEIGHT, "so_long");
	(*game)->imgs = get_imgs((*game)->mlx, IMG_PATH);
	if (!(*game)->imgs)
		return (EC_MALLOC);
	(*game)->player = player_constructor(*(*game)->map, &(*game)->imgs[P]);
	if (!(*game)->player)
		return (EC_MALLOC);
	return (OK);
}

static	t_err_code	valid_map(t_game *game)
{
	t_map		*copy;
	t_bool		*exit;

	exit = (t_bool *) malloc(sizeof(t_bool));
	if (!exit)
		return (EC_MALLOC);
	*exit = FALSE;
	copy = copy_map(*game->map);
	if (!copy)
		return (free(exit), EC_MALLOC);
	if (!check_map(copy, game->player->pos, exit))
		return (free(exit), EC_NOT_VALID_MAP);
	return (free(exit), OK);
}
void leaks()
{
	system("leaks solong");
}
int	main(int	argc,	char	*argv[])
{
	t_game		*game;
	t_err_code	status;

	atexit(leaks);
	game = NULL;
	if (argc != 2)
		return (error(game, EC_INVALID_ARGS));
	status = init(&game, argv[argc - 1]);
	if (status != OK)
		return (error(game, status));
	status = valid_map(game);
	if (status != OK)
		return (error(game, status));
	reload_map(game);
	mlx_key_hook(game->mlx->win, listener, game);
	mlx_loop_hook(game->mlx->mlx, reload_map, game);
	mlx_hook(game->mlx->win, 17, 0L, (int (*)()) delete_data, &game);
	mlx_loop(game->mlx->mlx);
	return (0);
}
