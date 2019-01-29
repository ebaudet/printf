/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:58:12 by ebaudet           #+#    #+#             */
/*   Updated: 2019/01/29 17:35:53 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

/*
** This function find the last numeric char of chained numeric chars.
*/

char	*find_last_nunber(const char *str)
{
	int		i;

	i = 0;
	while (str && str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	return (char *)&str[i];
}

/*
** This function search the first occurance of one of the caraters of needle in
** heystack.
*/

char	*ft_strstrchr(const char *haystack, const char *needle)
{
	while (*haystack && ft_strchr(needle, haystack[0]) == NULL)
		haystack++;
	if (!*haystack)
		return (NULL);
	else
		return ((char *)haystack);
}
