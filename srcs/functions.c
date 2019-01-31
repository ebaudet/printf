/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:58:12 by ebaudet           #+#    #+#             */
/*   Updated: 2019/01/31 19:36:10 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
** Fill the string <str> to fit the size <len> with the charact <c>
** at position <pos right:0,left:1>
*/

char	*fill_string(char *str, int c, size_t len, int pos)
{
	size_t	str_len;
	char	*str_tmp;

	str_len = ft_strlen(str);
	if (len <= str_len)
		return (str);
	str_tmp = (char *)ft_memalloc((len + 1) * sizeof(char));
	if (pos == 0)
		str_tmp = ft_memset(str_tmp, c, len - str_len);
	ft_strcat(str_tmp, str);
	if (pos != 0)
		ft_memset(str_tmp + str_len, c, len - str_len);
	ft_strcpy(str, str_tmp);
	free(str_tmp);
	return (str);
}

/*
** Fill the string <str> to fit the size <len> with zero before numbers.
*/

char	*fill_zero(char *str, size_t len)
{
	size_t	str_len;
	char	*str_tmp;
	int		i;
	int		j;

	str_len = ft_strlen(str);
	if (len <= str_len)
		return (str);
	str_tmp = (char *)ft_memalloc((len + 1) * sizeof(char));
	i = -1;
	while (str[++i] && (str[i] < '1' || str[i] > '9'))
		str_tmp[i] = str[i];
	j = -1;
	while (++j < (int)(len - str_len))
		str_tmp[i + j] = '0';
	while (str[i])
	{
		str_tmp[i + j] = str[i];
		i++;
	}
	ft_strcpy(str, str_tmp);
	free(str_tmp);
	return (str);
}

/*
** Check if the flag is set.
*/

int		check_flag(t_params *params, t_flag flag)
{
	if ((params->flag | flag) == params->flag)
		return (1);
	return (0);
}

