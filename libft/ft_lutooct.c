/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutooct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 20:45:55 by ebaudet           #+#    #+#             */
/*   Updated: 2019/01/31 16:21:46 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_lutooct(long unsigned int lu)
{
	char				octal_number[100];
	long unsigned int	temp;
	int					i;

	ft_memset(octal_number, 0, 100);
	i = 0;
	if (lu == 0)
		octal_number[i++] = 0 + '0';
	while (lu != 0)
	{
		temp = lu % 8;
		temp += '0';
		octal_number[i++] = temp;
		lu = lu / 8;
	}
	octal_number[i++] = '0';
	ft_strreverse(octal_number);
	return (ft_strdup(octal_number));
}
