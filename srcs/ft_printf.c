/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 20:45:55 by ebaudet           #+#    #+#             */
/*   Updated: 2013/12/21 20:45:55 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	/*va_list		ap;
	va_start(ap, format);
	va_arg(ap, type);
	va_end(ap);
	return (0);
*/
	int			i;
	int			j;
	char		*v;
	int			n;
	va_list		ap;

	i = 0;
	j = 0;
	va_start(ap, format);
	while(*(format + i) != '\0')
	{
		switch(*(format + i))
		{
			case '%':
			{
				i++;
				if(*(format + i) == 'c')
				{
					ft_putchar(va_arg(ap, int));
				}
				if(*(format + i) == 'd')
				{
					n = va_arg(ap, int);
					v = ft_itoa(n);
					for(j = 0; j < ft_strlen(v); j++)
					{
						ft_putchar(v[j]);
					}
					if(*(format + i) == 's')
					{
						ft_strcpy(v, va_arg(ap, char *));
						for(j = 0; j < ft_strlen(v); j++)
							ft_putchar(v[j]);
					}
				}
				break;
				default : ft_putchar(*(format + i)); break ;
			}
			i++;
		}
		va_end(ap);
	}
	return (0);
}
