/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:42:02 by ebaudet           #+#    #+#             */
/*   Updated: 2019/01/31 19:58:28 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)malloc(size * sizeof(unsigned char));
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, size);
	return (ptr);
}
