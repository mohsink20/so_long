/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_free2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:15:26 by mokhan            #+#    #+#             */
/*   Updated: 2023/12/31 16:15:27 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_elements(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	free_invalid_chars(t_data *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->wall_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->wall_s_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->corner_tl);
	mlx_destroy_image(mlx->mlx_ptr, mlx->corner_tr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->corner_bl);
	mlx_destroy_image(mlx->mlx_ptr, mlx->corner_br);
	mlx_destroy_image(mlx->mlx_ptr, mlx->rock_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->floor_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->char_f_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->char_b_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->char_r_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->char_l_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->coll_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->coll_2_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->exit_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->enemy_w_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->enemy_a_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->enemy_s_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->enemy_d_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->black_img);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	exit(0);
}
