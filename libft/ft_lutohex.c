/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutohex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 20:45:55 by ebaudet           #+#    #+#             */
/*   Updated: 2019/02/02 15:10:28 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_lutohex(long unsigned int lu)
{
	char				hexadecimal_number[100];
	long unsigned int	temp;
	int					i;

	ft_memset(hexadecimal_number, 0, 100);
	i = 0;
	if (lu == 0)
		hexadecimal_number[i++] = 0 + '0';
	while (lu != 0)
	{
		temp = lu % 16;
		if (temp < 10)
			temp = temp + '0';
		else
			temp = temp + 'a' - 10;
		hexadecimal_number[i++] = temp;
		lu = lu / 16;
	}
	ft_strreverse(hexadecimal_number);
	return (ft_strdup(hexadecimal_number));
}
