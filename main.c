/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 20:41:51 by ebaudet           #+#    #+#             */
/*   Updated: 2019/01/31 19:23:42 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int main(void)
{
	int		i;
	char	*pointer = NULL;

	i = 12;

	ft_printf("12.5 = %f\n-25.744 = %f\n-25.745 = %f\n3.145 = %f\n3.146 = %f\n3.144 = %f\n",
	          12.5, -25.744, -25.745, 3.145, 3.146, 3.144);
	// exit(0);
	ft_printf("1111123.3456 = %f\n", 1111123.3456);

	// todo: handle float 2^65 -> long long
	// ft_printf("36893488147419103232.0 = %f\n", 36893488147419103232.0);
	printf("%f\n", 36893488147419103232.0);
	ft_printf("char-%c-%s-%s-%c-%s-%c-\n", 'a', "un", "deux", 'b', "trois", 'e');
	printf("char-%c-%s-%s-%c-%s-%c-\n", 'a', "un", "deux", 'b', "trois", 'e');
	ft_printf("char-%c-%s-%s-%c-%s-%c-%-4i\n", 'a', "un", "deux", 'b', "trois", 'd', -12);
	printf("char-%c-%s-%s-%c-%s-%c-%-4i\n", 'a', "un", "deux", 'b', "trois", 'd', -12);
    // ft_printf("");

	ft_printf("\n----------\n");
	ft_printf("\nabcdefg\nh");
	ft_printf(". .\n");
	ft_printf("coucou\n");
	printf("coucou\n");
	ft_printf("\n%bla% => %\n");
	// exit(0);
	// printf("%bla% => %\n");
	printf("|nie% -  %d|\n");
    ft_printf("|nie% -  %d|\n");
	printf("Je m'appelle %s %s, et j'ai %d ans\n", "Emilien", "Baudet", 29);
	ft_printf("Je m'appelle %s %s, et j'ai %d ans\n", "Emilien", "Baudet", 29);
	ft_printf("\n----------\n");
	printf("   printf: &i = %p\n", &i);
	ft_printf("ft_printf: &i = %p\n", &i);
	printf("   printf: 1835 = (x)%x, (X)%X, (p)%p\n", 1835, 1835, pointer);
	ft_printf("ft_printf: 1835 = (x)%x, (X)%X, (p)%p\n", 1835, 1835, pointer);
	printf("   printf: 1835 = (x)%#x, (X)%#X, (p)%p\n", 1835, 1835, pointer);
	ft_printf("ft_printf: 1835 = (x)%#x, (X)%#X, (p)%p\n", 1835, 1835, pointer);
	printf("   printf: octal 123 = %o %#o %o %#o\n", 123, 123, -123, -123);
	ft_printf("ft_printf: octal 123 = %o %#o %o %#o\n", 123, 123, -123, -123);
	printf("   printf: 123.37 = %g\n", 123.37);
	ft_printf("ft_printf: 123.37 = %g\n", 123.37);

	ft_printf("coucou%d\n", i);
	ft_printf("\n----------\n");
	printf("%00000002$d %01$d\n", 1, 2);

	printf("======= TEST DES FLAGS ========\n");
	printf("without any flags\n'%5d'\n'%5d'\n'%5d'\n'%5d'\n", 22, -42, 1234567, -1234567);
	ft_printf("without any flags\n'%5d'\n'%5d'\n'%5d'\n'%5d'\n", 22, -42, 1234567, -1234567);
	printf("with minus flag\n'%-5d'\n'%-5d'\n'%-5d'\n'%-5d'\n", 22, -42, 1234567, -1234567);
	ft_printf("with minus flag\n'%-5d'\n'%-5d'\n'%-5d'\n'%-5d'\n", 22, -42, 1234567, -1234567);
	printf("with plus flag\n'%+5d'\n'%+5d'\n'%+5d'\n'%+5d'\n", 22, -42, 1234567, -1234567);
	ft_printf("with plus flag\n'%+5d'\n'%+5d'\n'%+5d'\n'%+5d'\n", 22, -42, 1234567, -1234567);
	printf("with plus/minus flag\n'%+-5d'\n'%+-5d'\n'%+-5d'\n'%+-5d'\n", 22, -42, 1234567, -1234567);
	ft_printf("with plus/minus flag\n'%+-5d'\n'%+-5d'\n'%+-5d'\n'%+-5d'\n", 22, -42, 1234567, -1234567);
	printf("with zero flag (ignored if minus option)\n'%05d'\n'%05d'\n'%05d'\n'%05d'\n", 22, -42, 1234567, -1234567);
	ft_printf("with zero flag (ignored if minus option)\n'%05d'\n'%05d'\n'%05d'\n'%05d'\n", 22, -42, 1234567, -1234567);
	printf("with zero/plus flag\n'%0+5d'\n'%0+5d'\n'%0+5d'\n'%0+5d'\n", 22, -42, 1234567, -1234567);
	ft_printf("with zero/plus flag\n'%0+5d'\n'%0+5d'\n'%0+5d'\n'%0+5d'\n", 22, -42, 1234567, -1234567);
	printf("with space option (ignored with plus option)\n'% 5d'\n'% 5d'\n'% 5d'\n'% 5d'\n", 22, -42, 1234567, -1234567);
	ft_printf("with space option (ignored with plus option)\n'% 5d'\n'% 5d'\n'% 5d'\n'% 5d'\n", 22, -42, 1234567, -1234567);
	printf("with space/zero option (ignored with plus option)\n'%0 5d'\n'%0 5d'\n'%0 5d'\n'%0 5d'\n", 22, -42, 1234567, -1234567);
	ft_printf("with space/zero option (ignored with plus option)\n'%0 5d'\n'%0 5d'\n'%0 5d'\n'%0 5d'\n", 22, -42, 1234567, -1234567);
	printf("%d %.*s %s\n", 12, 3, "abcdef", "asdfghjk");

	printf("%f\n", 123456789123.12);
	// printf("%hhs\n", 'c');

	printf("%o => %#o, %x => %#x, %X => %#X\n", 15, 15, 15, 15, 15, 15);
	ft_printf("%o => %#o, %x => %#x, %X => %#X\n", 15, 15, 15, 15, 15, 15);
	printf("%x %x\n", 12, -12);
	printf("%.2f %08.2f %08.2f\n", 12.5, 12.5, -12.5);
	ft_printf("%.2f %08.2f %08.2f\n", 12.5, 12.5, -12.5);
	printf("%o %05o\n", 12, 12);
	ft_printf("%o %05o\n", 12, 12);

	// printf("%hhc %hhc", 1, 'c');
	printf("{cyan}yolo{eoc} {red}zbra{eoc}\n");
	printf("\e[36;1myolo\e[0m \e[31;1mzbra\e[0m\n");
	ft_printf("%f, %.1f, %.2f, %.3f, %.4f, %f\n", 123.456, 123.456, 123.456, 123.456, 123.456, 123.456);
	printf("'%15s' '%15.3s' '%4.3s' '%.0s' '%.3s'\n", "qwertyuiop", "qwertyuiop", "qwertyuiop", "qwertyuiop", "qwertyuiop");
	ft_printf("'%15s' '%15.3s' '%4.3s' '%.0s' '%.3s'\n", "qwertyuiop", "qwertyuiop", "qwertyuiop", "qwertyuiop", "qwertyuiop");
	return (0);
}
