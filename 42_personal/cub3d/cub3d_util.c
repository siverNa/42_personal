/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:18:56 by sna               #+#    #+#             */
/*   Updated: 2021/04/16 17:25:33 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		freenull(void **var)
{
	free(*var);
	*var = 0;
}

int			print_error(int e_code, char *msg)
{
	if (e_code == 0)
	{
	write(1, "Error\n", 6);
	write(1, msg, ft_strlen(msg));
	write(1, "\n", 1);
	}
	return (0);
}

