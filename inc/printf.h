/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:50:34 by hdanylev          #+#    #+#             */
/*   Updated: 2018/01/27 17:46:04 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct		s_all
{
	struct s_mod	*mod;
	struct s_capa	*capa;
	struct s_lat	*lat;
	va_list			conv;
	size_t 			size;
	int 			flag_stop;
	int 			len;
	long			l;
	unsigned long	ul;
	char 			*output;
	int 			x;
	char 			spc;
	int 			printed;
	int 			ret;
	int				outlen;
	int 			prec;
}					t_all;

typedef struct 		s_lat
{
	t_all 	*(*f)(t_all*);
	int 	flag;
	char 	lat;
	int 	num;
}					t_lat;

typedef struct		s_mod
{
	t_all	*(*f)(t_all*);
	char	mod;
	int		flag;
}					t_mod;

typedef struct		s_capa
{
	int		(*f)(t_all*);
	int		flag;
	char	spc;
}					t_capa;

int		ft_x(t_all *all);
int		ft_u(t_all *all);
int		ft_o(t_all *all);
int		ft_c(t_all *all);
int		ft_id(t_all *all);
int		ft_atoi(const char *str);
int		ft_atoi_base(char *str, int base);
int		ft_s(t_all *all);
int		ft_p(t_all *all);
int		ft_printf(const char *fmt, ...);
void	nbr_hex(long n);
void	ft_putstr(char const *str);
void	ft_putchar(char c);
char	ft_zero(t_all *all);
char	*ft_strnew(int size);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_itoa(long nb);
char	*ft_itoa_base(unsigned long value, int base);
char	*ft_itoa_base_l(long n, int base);
char	*ft_toupper(char *str);
size_t	ft_strlen(const char *str);
t_all	*ft_hash(t_all *all);
t_all	*ft_space(t_all *all);
t_all	*ft_count_output(t_all *all);
t_all	*ft_minus(t_all *all);
t_all	*ft_plus(t_all *all);
t_all	*ft_unicode(t_all *all);
t_all	*ft_check_mod2(t_all *all);
t_all	*ft_check_lat2(t_all *all);
t_all 	*ft_field_width(t_all *all);
t_all	*ft_output(t_all *all);
t_all 	*ft_precision(t_all *all);
t_all	*ft_l(t_all *all);
t_all	*ft_hh(t_all *all);
t_all	*ft_h(t_all *all);
t_all	*ft_j(t_all *all);
t_all	*ft_z(t_all *all);
t_all	*ft_persent(t_all *all);
t_all	*ft_zero_flag(t_all *all);
t_all	*ft_str_unicode(t_all *all, unsigned int u);
t_all	*write_flags(t_all *all);
t_all	*ft_check_capa(t_all *all, char x);
t_all	*ft_check_mod(t_all *all, char x);
t_all	*ft_check_lat(t_all *all, char *fmt);
t_all	*ft_read_lol(t_all *all, char *fmt);
t_all	*functions_pointers_capa(t_all *all);
t_all	*functions_pointers_mod(t_all *all);
t_all	*functions_pointers_flag(t_all *all);

#endif
