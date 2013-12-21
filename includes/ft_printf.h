/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 20:41:15 by ebaudet           #+#    #+#             */
/*   Updated: 2013/12/21 20:41:15 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
void	ft_putchar(char c);
char			*ft_itoa(int n);
char	*ft_strcpy(char *s1, const char *s2);

int		ft_printf(const char *format, ...);

#endif /* PRINTF_H */
