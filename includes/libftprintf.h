/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 22:53:23 by ebaudet           #+#    #+#             */
/*   Updated: 2013/12/21 22:53:29 by ebaudet          ###   ########.fr       */
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

int		ft_atoi(const char *str);
char	*ft_lutohex(long unsigned int lu);
size_t	ft_strlen(const char *s);
void	ft_putchar(char c);
char	*ft_itoa(int n);
char	*ft_strcpy(char *s1, const char *s2);
char	*ft_strdup(const char *s1);
void	print_c(t_ftprintf *t);
void	print_s(t_ftprintf *t);
void	print_d(t_ftprintf *t);
void	putstr_count(t_ftprintf *t, char *str);
int		is_arg(t_ftprintf *t, char *format);
void	print_uniq_caract(t_ftprintf *t, char *format);
void	print_caract(t_ftprintf *t, char *format);
int		ft_printf(const char *format, ...);

#endif /* LIBFTPRINTF_H */
