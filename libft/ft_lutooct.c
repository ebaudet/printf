/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutooct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 20:45:55 by ebaudet           #+#    #+#             */
/*   Updated: 2019/01/23 21:38:30 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_lutooct(long unsigned int lu)
{
	char				octalNumber[100];
	long unsigned int	temp;
	int					i;

	ft_memset(octalNumber, 0, 100);
	i = 0;
	if (lu == 0)
		octalNumber[i++] = 0 + '0';
	while (lu != 0)
	{
		temp = lu % 8;
		temp += '0';
		octalNumber[i++] = temp;
		lu = lu / 8;
	}
	ft_strreverse(octalNumber);
	return ft_strdup(octalNumber);
}
