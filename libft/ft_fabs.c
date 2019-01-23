/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fabs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:39:09 by ebaudet           #+#    #+#             */
/*   Updated: 2014/03/25 21:43:17 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double		ft_fabs(double i)
{
	if (i < 0)
		return -i;
	return i;
}
