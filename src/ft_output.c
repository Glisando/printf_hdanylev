/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:29:26 by hdanylev          #+#    #+#             */
/*   Updated: 2018/02/18 15:29:29 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

t_all	*ft_output(t_all *all)
{
	all->size = ft_strlen(all->output);
	if (all->lat[5].flag == 1 && all->output[0] == '-')
		write(1, &all->output[1], all->size - 1);
	else if (all->lat[1].flag == 1 && all->lat[2].flag != 1 &&
			all->output[0] == '-')
		write(1, &all->output[1], all->size - 1);
	else if (all->spc == 'c' && all->output[0] == '\0' && all->size++)
		write(1, "\0", 1);
	else
		write(1, all->output, all->size);
	all->len += (int)all->size;
	all->printed = 1;
	return (all);
}
