/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:49:47 by ebaudet           #+#    #+#             */
/*   Updated: 2019/01/31 19:58:58 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*scopy;

	i = -1;
	scopy = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	while (s1[++i])
		scopy[i] = s1[i];
	scopy[i] = s1[i];
	return (scopy);
}
