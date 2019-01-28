/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 22:53:23 by ebaudet           #+#    #+#             */
/*   Updated: 2019/01/28 16:09:42 by ebaudet          ###   ########.fr       */
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

typedef enum {
	NONE_LENGH = 0,
	HH,		// hh	char
	H,		// h	short
	L,		// l	long
	LL,		// ll	long long
	LD,		// L	long double
	Z,		// z	size_t
	J,		// j	intmax_t
	T,		// t	ptrdiff_t
	MAX_LENGHT /* not a type of thing itself, instead used to find number of things */
}					t_length;

typedef enum {
	NONE_FLAG = 0,
	MINUS = 0b1,
	PLUS = 0b10,
	SPACE = 0b100,
	ZERO = 0b1000,
	HASH = 0b10000,
	MAX_FLAG = 0b100000
}					t_flag;



typedef struct		s_params
{
	char			*position;
	int				size;
	int				parameter;
	int				flag;
	int				width;
	int				precision;
	t_length		length;
	void			(*type)(t_ftprintf *, char *, struct s_params *);
	// void			(*type)();
	struct s_params	*next;
}					t_params;

typedef void (*t_hadler_case)(t_ftprintf *, char *, t_params *);

typedef struct		s_handler
{
	char			value;
	t_hadler_case	handle;
}					t_handler;

char	*ft_sprintf(const char *format, ...);
int		ft_printf(const char *format, ...);

/* put.c */
void	print_uniq_caract(t_ftprintf *t, char *format, char *buf, int size);
void	put_o(t_ftprintf *t, char *buf, t_params *params);
void	put_p(t_ftprintf *t, char *buf, t_params *params);
void	put_x(t_ftprintf *t, char *buf, t_params *params);
void	put_x_cap(t_ftprintf *t, char *buf, t_params *params);
void	put_c(t_ftprintf *t, char *buf, t_params *params);
void	put_s(t_ftprintf *t, char *buf, t_params *params);
void	put_d(t_ftprintf *t, char *buf, t_params *params);
void	put_u(t_ftprintf *t, char *buf, t_params *params);
void	put_f(t_ftprintf *t, char *buf, t_params *params);

#endif /* LIBFTPRINTF_H */
