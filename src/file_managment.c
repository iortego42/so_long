/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_managment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortego- <iortego-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:33:29 by iortego-          #+#    #+#             */
/*   Updated: 2023/09/15 19:41:51 by iortego-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "mlx.h"
#include "so_long.h"

t_bool	is_sym(t_map *map)
{
	int	prevlen;
	int	len;
	int	index;

	index = 0;
	len = get_line_lenght(map->map[index]);
	while (map->map[index] != NULL)
	{
		prevlen = len;
		len = get_line_lenght(map->map[index]);
		if (len != prevlen)
			return (FALSE);
		index++;
	}
	map->dim.x = len;
	map->dim.y = index;
	return (TRUE);
}

t_img	*get_imgs(t_mlx	*mlx, char	*pathtoimgs)
{
	t_img	*images;
	t_item	item;

	item = F;
	images = (t_img *) malloc(sizeof(t_img) * N_ITEMS);
	if (images == NULL)
		return (NULL);
	while (item < N_ITEMS)
	{
		images[item].path = ft_strjoin(pathtoimgs, g_imgfiles[item]);
		images[item].img = mlx_xpm_file_to_image(mlx->mlx,
				images[item].path,
				&images[item].width, &images[item].height);
		free(images[item].path);
		images[item].path = NULL;
		if (images[item].img == NULL)
		{
			while (item-- >= 0)
				mlx_destroy_image(mlx->mlx, images[item].img);
			return (free(images), NULL);
		}
		item++;
	}
	return (images);
}

t_err_code	open_file(char *file, void *(*fun)(int), void **data)
{
	int		fd;

	*data = NULL;
	if (fun == NULL && file == NULL)
		return (EC_UNDEFINED);
	if (extension(file, ALLOWED_EXT) == FALSE)
		return (EC_NOT_VALID_MAP);
	fd = open(file, O_RDONLY);
	if (fd > 0)
	{
		*data = fun(fd);
		close(fd);
		if (*data == NULL)
			return (EC_UNDEFINED);
		return (OK);
	}
	else
		return (EC_NOT_FILE);
}

t_map	*get_map(int fd)
{
	int		index;
	t_map	*map;
	char	*line;

	index = 0;
	line = NULL;
	map = (t_map *) malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->map = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map->map = (char **)ft_realloc(map->map,
				sizeof(char **) * (index + 2), sizeof(char **) * (index + 1));
		if (map->map == NULL)
			return (clear_matrix((void ***)&map->map, index), NULL);
		map->map[index] = line;
		index++;
		line = get_next_line(fd);
	}
	map->map[index] = NULL;
	map->dim.y = index;
	map->items = get_items(*map);
	return (map);
}
