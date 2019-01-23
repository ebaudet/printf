/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 22:53:23 by ebaudet           #+#    #+#             */
/*   Updated: 2019/01/23 21:59:02 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_ftprintf
{
	va_list			ap;
	int				i;
	int				count;
}					t_ftprintf;

typedef void (*t_hadler_case)(t_ftprintf *, char *);

typedef struct		s_handler
{
	char			conversion;
	t_hadler_case	handle;
}					t_handler;

typedef enum {
	NONE = 0,
	HH,		// hh	char
	H,		// h	short
	L,		// l	long
	LL,		// ll	long long
	LD,		// L	long double
	Z,		// z	size_t
	J,		// j	intmax_t
	T,		// t	ptrdiff_t
	num_thing_types /* not a type of thing itself, instead used to find number of things */
} t_length;

typedef struct	s_params
{
	int			parameter;
	int			flag;
	int			width;
	int			precision;
	t_length	length;
}				t_params;

char	*ft_sprintf(const char *format, ...);
int		ft_printf(const char *format, ...);

/* put.c */
void	print_uniq_caract(t_ftprintf *t, char *format, char *buf);
void	put_o(t_ftprintf *t, char *buf);
void	put_p(t_ftprintf *t, char *buf);
void	put_x(t_ftprintf *t, char *buf);
void	put_x_cap(t_ftprintf *t, char *buf);
void	put_c(t_ftprintf *t, char *buf);
void	put_s(t_ftprintf *t, char *buf);
void	put_d(t_ftprintf *t, char *buf);
void	put_u(t_ftprintf *t, char *buf);
void	put_f(t_ftprintf *t, char *buf);

#endif /* LIBFTPRINTF_H */
