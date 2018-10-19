/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutohex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 20:45:55 by ebaudet           #+#    #+#             */
/*   Updated: 2018/10/19 20:45:55 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_strcat(char *s1, const char *s2)
{
	int			i;
	size_t		lenght;

	lenght = ft_strlen(s1);
	i = 0;
	while (s2[i])
	{
		s1[i + lenght] = s2[i];
		i++;
	}
	s1[i + lenght] = 0;
	return (s1);
}

static void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ptr[i] = c;
		i++;
	}
	return (b);
}

static void	ft_invstr(char *str)
{
	char	buff[100];
	int		size;
	int		i;

	ft_memset(buff, 0, 100);
	ft_strcpy(buff, str);
	size = ft_strlen(str);
	i = -1;
	while (size - ++i > 0)
		str[i] = buff[size - i - 1];
}

char		*ft_lutohex(long unsigned int lu)
{
	char hexadecimalNumber[100];
	long unsigned int temp;
	int i;

	ft_memset(hexadecimalNumber, 0, 100);
	i = 0;
	while (lu != 0)
	{
		temp = lu % 16;
		if (temp < 10)
			temp = temp + '0';
		else
			temp = temp + 'a' - 10;
		hexadecimalNumber[i++] = temp;
		lu = lu / 16;
	}
	ft_strcat(hexadecimalNumber + i, "x0");
	ft_invstr(hexadecimalNumber);
	return ft_strdup(hexadecimalNumber);
}
