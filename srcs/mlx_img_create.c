/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 10:02:38 by erli              #+#    #+#             */
/*   Updated: 2019/01/16 17:30:05 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxadd.h"
#include "libft.h"

t_img	*mlx_img_create(void *mlx_ptr, t_img *img, int width, int height)
{
	img->ptr = mlx_new_image(mlx_ptr, width, height);
	if (img->ptr == 0)
		return (0);
	img->bypp = 4;
	img->bpp = img->bypp * 8;
	img->size_line = 4 * width;
	img->nb_line = height;
	img->endian = 0;
	img->str = mlx_get_data_addr(img->ptr, &(img->bpp), &(img->size_line),
					&(img->endian));
	ft_bzero(img->str, (img->size_line * height));
	return (img);
}
