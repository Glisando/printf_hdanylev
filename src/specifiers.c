/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:33:38 by hdanylev          #+#    #+#             */
/*   Updated: 2018/01/27 18:16:49 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

int		ft_c(t_all *all)
{
	char	c;

	ft_check_mod2(all);
	if (all->ret == -22)
	{
		c = (unsigned char)va_arg(all->conv, int);
		all->output = (char*)malloc(sizeof(char) * 1);
		all->output[0] = c;
		ft_count_output(all);
		ft_check_lat2(all);
		if (all->ret == -42)
		{
			ft_output(all);
			return (all->len);
		}
	}
	if (all->printed != 1)
		ft_output(all);
	return (all->len);
}

int		ft_o(t_all *all)
{
	unsigned int	o;

	ft_check_mod2(all);
	if (all->ret == -22)
	{
		o = va_arg(all->conv, unsigned int);
		all->output = ft_itoa_base(o, 8);
		ft_count_output(all);
		ft_check_lat2(all);
		if (all->ret == -42)
		{
			ft_output(all);
			return (all->len);
		}
	}
	if (all->printed != 1)
		ft_output(all);
	return (all->len);
}

int		ft_x(t_all *all)
{
	unsigned int	x;

	ft_check_mod2(all);
	if (all->ret == -22)
	{
		x = va_arg(all->conv, unsigned int);
		all->output = ft_itoa_base(x, 16);
		ft_count_output(all);
		if (all->spc == 'X')
			ft_toupper(all->output);
		ft_check_lat2(all);
		if (all->ret == -42)
		{
			ft_output(all);
			return (all->len);
		}
	}
	if (all->printed != 1)
		ft_output(all);
	return (all->len);
}

int		ft_id(t_all *all)
{
	int	id;

	ft_check_mod2(all);
	if (all->ret == -22)
	{
		id = va_arg(all->conv, int);
		all->output = ft_itoa(id);
		ft_count_output(all);
		ft_check_lat2(all);
		if (all->ret == -42)
		{
			ft_output(all);
			return (all->len);
		}
	}
	if (all->printed != 1)
		ft_output(all);
	return (all->len);
}

int		ft_u(t_all *all)
{
	unsigned int	u;

	ft_check_mod2(all);
	if (all->ret == -22)
	{
		u = va_arg(all->conv, unsigned int);
		all->output = ft_itoa(u);
		ft_count_output(all);
		ft_check_lat2(all);
		if (all->ret == -42)
		{
			ft_output(all);
			return (all->len);
		}
	}
	if (all->printed != 1)
		ft_output(all);
	return (all->len);
}

int		ft_p(t_all *all)
{
	intptr_t	*p;

	ft_check_mod2(all);
	if (all->ret == -22)
	{
		p = va_arg(all->conv, void*);
		all->output = ft_itoa_base((unsigned long)p, 16);
		ft_count_output(all);
		ft_check_lat2(all);
		if (all->ret == -42)
		{
			write(1, "0x", 2);
			ft_output(all);
			return (all->len + 2);
		}
	}
	if (all->printed != 1)
		ft_output(all);
	return (all->len);
}

int		ft_s(t_all *all)
{
	ft_check_mod2(all);
	if (all->ret == -22)
	{
		if (!(all->output = va_arg(all->conv, char*)))
			all->output = "(null)";
		ft_count_output(all);
		ft_check_lat2(all);
		if (all->ret == -42)
		{
			ft_output(all);
			return (all->len);
		}
	}
	if (all->printed != 1)
		ft_output(all);
	if (all->output == NULL)
		return (0);
	return (all->len);
}

t_all	*ft_count_output(t_all *all)
{
	all->outlen = ft_strlen(all->output);
	if (all->lat[5].flag == 1 && all->lat[5].num == 0 && all->output[0] == '0')
	{
		if ( all->spc != 'o' || all->lat[0].flag != 1)
		{
			all->printed = 1;
			all->outlen -= 1;
		}
	}
	if (all->output[0] == '\0' && all->spc == 'c')
		all->outlen = 1;
	if (all->lat[0].flag == 1)
	{
		if (all->spc == 'x' || all->spc == 'X')
			all->outlen += 2;
		else if (all->spc == 'o' || all->spc == 'O')
			all->outlen += 1;
	}
	if (all->lat[3].flag == 1)
	{
		if ((all->spc == 'd' || all->spc == 'i') && all->output[0] != '-')
			all->lat[6].num -= 1;
	}
	return (all);
}
