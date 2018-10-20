/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 20:41:51 by ebaudet           #+#    #+#             */
/*   Updated: 2013/12/21 20:41:51 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int main(void)
{

	int i;

	i = 12;

	ft_printf("char-%c-%s-%s-%c-%s-%c-\n", 'a', "un", "deux", 'b', "trois", 'c');
	ft_printf("char-%c-%s-%s-%c-%s-%c-%-i", 'a', "un", "deux", 'b', "trois", 'd');
    ft_printf("");
	ft_printf("\n----------\n");
	ft_printf("\nabcdefg\nh");
	ft_printf(". .");
	ft_printf("ft_printf: coucou\n");
	printf("printf: coucou\n");

	ft_printf("ft_printf: Je m'appelle %s %s, et j'ai %d ans\n", "Emilien", "Baudet", 29);
	printf("printf: Je m'appelle %s %s, et j'ai %d ans\n", "Emilien", "Baudet", 29);
	ft_printf("\n----------\n");
	ft_printf("ft_printf: &i = %p\n", &i);
	printf("printf: &i = %p\n", &i);



	ft_printf("coucou%d\n", i);
	ft_printf("\n----------\n");
	return (0);
}
