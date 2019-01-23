/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 22:53:23 by ebaudet           #+#    #+#             */
/*   Updated: 2019/01/23 15:06:54 by ebaudet          ###   ########.fr       */
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

typedef struct		s_handler
{
	char			conversion;
	void			(*handle)(t_ftprintf *, char *);
}					t_handler;

char	*ft_sprintf(const char *format, ...);
int		ft_printf(const char *format, ...);

/* put.c */
void	put_p(t_ftprintf *t, char *buf);
void	put_c(t_ftprintf *t, char *buf);
void	put_s(t_ftprintf *t, char *buf);
void	put_d(t_ftprintf *t, char *buf);
void	put_f(t_ftprintf *t, char *buf);

#endif /* LIBFTPRINTF_H */
