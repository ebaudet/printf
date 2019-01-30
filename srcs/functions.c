/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:58:12 by ebaudet           #+#    #+#             */
/*   Updated: 2019/01/30 23:06:02 by ebaudet          ###   ########.fr       */
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

/*
** Fill de string <str> to fit the size <len> with the charact <c>
** at position <pos right:0,left:1>
*/

char	*fill_string(char *str, int c, size_t len, int pos)
{
	size_t	str_len;
	char	*str_tmp;

	str_len = ft_strlen(str);
	if (len <= str_len)
		return (str);
	str_tmp = ft_memalloc((len + 1) * sizeof(char));
	if (pos == 0)
		str_tmp = ft_memset(str_tmp, c, len - str_len);
	ft_strcat(str_tmp, str);
	if (pos != 0)
		ft_memset(str_tmp + str_len, c, len - str_len);
	ft_strcpy(str, str_tmp);
	free(str_tmp);
	return (str);
}
