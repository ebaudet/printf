/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 22:53:23 by ebaudet           #+#    #+#             */
/*   Updated: 2019/02/03 00:08:56 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFF_PARAMS 255

# define P_FLAGS "-+ 0#"
# define P_WIDTH "123456789"
# define P_PRECISION "."
# define P_LENGTH "hhlLzjt"
# define P_TYPE "cspdiouxXf"
# define P_MODULO "%"

/*
** color code for opion k - color
*/
# define K_BLACK 30
# define K_RED 31
# define K_GREEN 32
# define K_YELLOW 33
# define K_BLUE 34
# define K_ROSE 35
# define K_CYAN 36
# define K_WHITE 37

/*
** hh - char
** h  - short
** l  - long
** ll - long long
** L  - long double
** z  - size_t
** j  - intmax_t
** t  - ptrdiff_t
*/
typedef enum {
	NONE_LENGH = 0,
	HH,
	H,
	L,
	LL,
	LD,
	Z,
	J,
	T,
	MAX_LENGHT
}	t_length;

typedef enum {
	NONE_FLAG = 0,
	MINUS = 0b1,
	PLUS = 0b10,
	SPACE = 0b100,
	ZERO = 0b1000,
	HASH = 0b10000,
	MAX_FLAG = 0b100000
}	t_flag;

/*
** Global structure for printf
*/
typedef struct			s_ftprintf
{
	va_list				ap;
	int					i;
	char				*str;
	int					size;
}						t_ftprintf;

/*
** Return structur for the function ft_sprintf.
** This contains the string and the size of the string.
*/
typedef struct			s_ftsprintf
{
	char				*str;
	int					len;
}						t_ftsprintf;

/*
** Structure for params printf
*/
typedef struct			s_params
{
	int					parameter;
	t_flag				flag;
	int					width;
	int					precision;
	t_length			length;
	char				*pos;
	int					size;
	char				buf[BUFF_PARAMS];
	void				(*type)(t_ftprintf *, char *, struct s_params *);
}						t_params;

typedef void	(*t_hadler_case)(t_ftprintf *, t_params *);
typedef void	(*t_handler_function)(const char *, t_ftprintf *, t_params *);

typedef struct			s_handler
{
	char				value;
	t_hadler_case		handle;
}						t_handler;

typedef struct			s_call_handler
{
	char				*value;
	t_handler_function	handle;
}						t_call_handler;

typedef long long int	(*t_len_decimal)(t_ftprintf *);

typedef struct			s_handler_len
{
	char				value;
	t_len_decimal		handle;
}						t_handler_len;

/*
** ft_printf.c
*/
t_ftsprintf				*ft_sprintf(const char *format, ...);
int						ft_printf(const char *format, ...);

/*
** params.c
*/
t_params				*params_reset(t_params *params);

/*
** put.c
*/
void					type_c(t_ftprintf *t, t_params *params);
void					type_s(t_ftprintf *t, t_params *params);
void					type_p(t_ftprintf *t, t_params *params);
void					type_d(t_ftprintf *t, t_params *params);
void					type_o(t_ftprintf *t, t_params *params);
void					type_u(t_ftprintf *t, t_params *params);
void					type_x(t_ftprintf *t, t_params *params);
void					type_x_cap(t_ftprintf *t, t_params *params);
void					type_f(t_ftprintf *t, t_params *params);

/*
** functions.c
*/
char					*find_last_nunber(const char *str);
char					*ft_strstrchr(const char *haystack, const char *needle);
char					*fill_string(char *str, int c, size_t len, int pos);
char					*fill_zero(char *str, size_t len);
int						check_flag(t_params *params, t_flag flag);

/*
** handler.c
*/
int						call_handler(const char *format, t_ftprintf *t,
						t_params *params);
void					modulo_handler(const char *format, t_ftprintf *t,
						t_params *params);
void					flag_handler(const char *format, t_ftprintf *t,
						t_params *params);
void					width_handler(const char *format, t_ftprintf *t,
						t_params *params);
void					precision_handler(const char *format, t_ftprintf *t,
						t_params *params);
void					length_handler(const char *format, t_ftprintf *t,
						t_params *params);
void					type_handler(const char *format, t_ftprintf *t,
						t_params *params);

/*
** get_dec_lenght.c
*/
long long int			get_signed_int_handler(t_ftprintf *t, t_length length);
long long int			get_signed_hh_length(t_ftprintf *t);
long long int			get_signed_h_length(t_ftprintf *t);
long long int			get_signed_l_length(t_ftprintf *t);
long long int			get_signed_ll_length(t_ftprintf *t);
long long int			get_signed_z_length(t_ftprintf *t);
long long int			get_signed_j_length(t_ftprintf *t);

/*
** LIBFTPRINTF_H
*/
#endif
