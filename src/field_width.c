/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:09:52 by hdanylev          #+#    #+#             */
/*   Updated: 2018/02/19 17:10:11 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

t_all	*ft_put_width_num(t_all *all)
{
	char	ch;
	int		width;

	width = all->lat[6].num - all->outlen - all->prec;
	if (width < 0)
		width = 0;
	if (all->lat[4].flag == 1 && width == 0)
		all->lat[4].f(all);
	if (all->lat[2].flag == 1)
	{
		if (all->lat[0].flag == 1)
			all->lat[0].f(all);
		if (all->lat[3].flag == 1 && all->lat[5].flag != 1)
			all->lat[3].f(all);
		all->lat[2].f(all);
		ch = ft_zero(all);
		all->len += width;
		while (width > 0)
		{
			write(1, &ch, 1);
			width--;
		}
	}
	else
	{
		if (all->lat[1].flag == 1 && all->lat[0].flag == 1)
			all->lat[0].f(all);
		ch = ft_zero(all);
		all->len += width;
		while (width > 0)
		{
			write(1, &ch, 1);
			width--;
		}
		if (all->lat[0].flag == 1 && all->lat[1].flag != 1)
			all->lat[0].f(all);
	}
	return (all);
}

t_all	*ft_put_width_str(t_all *all)
{
	char	ch;
	int		width;

	if (all->lat[5].num <= all->outlen && all->lat[5].num)
		width = all->lat[6].num - all->lat[5].num;
	else
		width = all->lat[6].num - all->outlen;
	if (all->lat[2].flag == 1)
		all->lat[2].f(all);
	if (width < 0)
		width = 0;
	all->len += width;
	ch = ' ';
	while (width > 0)
	{
		write(1, &ch, 1);
		width--;
	}
	return (all);
}

t_all	*ft_field_width(t_all *all)
{
	if (all->spc == 'x' || all->spc == 'o' ||
			all->spc == 'd' || all->spc == 'i' ||
			all->spc == 'u' || all->spc == 'c' || all->spc == '%')
		return (ft_put_width_num(all));
	if (all->spc == 's')
		return (ft_put_width_str(all));
	return (0);
}
