/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 22:53:23 by ebaudet           #+#    #+#             */
/*   Updated: 2019/02/01 18:01:52 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct			s_ftprintf
{
	va_list				ap;
	int					i;
	int					count;
	char				*buf;
}						t_ftprintf;

typedef enum {
	NONE_LENGH			= 0,
	HH,					/* hh	char		*/
	H,					/* h	short		*/
	L,					/* l	long		*/
	LL,					/* ll	long long	*/
	LD,					/* L	long double	*/
	Z,					/* z	size_t		*/
	J,					/* j	intmax_t	*/
	T,					/* t	ptrdiff_t	*/
	MAX_LENGHT 			/* not a type of thing itself, instead used to find number of things */
}						t_length;

typedef enum {
	NONE_FLAG			= 0,
	MINUS				= 0b1,
	PLUS				= 0b10,
	SPACE				= 0b100,
	ZERO				= 0b1000,
	HASH				= 0b10000,
	MAX_FLAG			= 0b100000
}						t_flag;

typedef struct			s_params
{
	char				*position;
	int					size;
	int					parameter;
	t_flag				flag;
	int					width;
	int					precision;
	t_length			length;
	void				(*type)(t_ftprintf *, char *, struct s_params *);
}						t_params;

typedef void (*t_hadler_case)(t_ftprintf *, char *, t_params *);
typedef void (*t_handler_function)(char *, t_ftprintf *, t_params *);

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

typedef long long int (*t_len_decimal)(t_ftprintf *);

typedef struct			s_handler_len
{
	char				value;
	t_len_decimal		handle;
}						t_handler_len;

/* ft_printf.c */
char					*ft_sprintf(const char *format, ...);
int						ft_printf(const char *format, ...);

/* params.c */
t_params				*params_init(t_params *params);

/* put.c */
void					print_uniq_caract(t_ftprintf *t, char *format, char *buf, int size);
void					type_c(t_ftprintf *t, char *buf, t_params *params);
void					type_s(t_ftprintf *t, char *buf, t_params *params);
void					type_p(t_ftprintf *t, char *buf, t_params *params);
void					type_d(t_ftprintf *t, char *buf, t_params *params);
void					type_o(t_ftprintf *t, char *buf, t_params *params);
void					type_u(t_ftprintf *t, char *buf, t_params *params);
void					type_x(t_ftprintf *t, char *buf, t_params *params);
void					type_x_cap(t_ftprintf *t, char *buf, t_params *params);
void					type_f(t_ftprintf *t, char *buf, t_params *params);

/* functions.c */
char					*find_last_nunber(const char *str);
char					*ft_strstrchr(const char *haystack, const char *needle);
char					*fill_string(char *str, int c, size_t len, int pos);
char					*fill_zero(char *str, size_t len);
int						check_flag(t_params *params, t_flag flag);

/* handler.c */
int						call_handler(char *format, t_ftprintf *t, t_params *params);
void					modulo_handler(char *format, t_ftprintf *t, t_params *params);
void					flag_handler(char *format, t_ftprintf *t, t_params *params);
void					width_handler(char *format, t_ftprintf *t, t_params *params);
void					precision_handler(char *format, t_ftprintf *t, t_params *params);
void 					length_handler(char *format, t_ftprintf *t, t_params *params);
void					type_handler(char *format, t_ftprintf *t, t_params *params);

/* get_dec_lenght.c */
long long int			get_signed_int_handler(t_ftprintf *t, t_length length);
long long int			get_signed_hh_length(t_ftprintf *t);
long long int			get_signed_h_length(t_ftprintf *t);
long long int			get_signed_l_length(t_ftprintf *t);
long long int			get_signed_ll_length(t_ftprintf *t);
long long int			get_signed_z_length(t_ftprintf *t);
long long int			get_signed_j_length(t_ftprintf *t);

/* lib functions */
// void					*ft_memset(void *b, int c, size_t len);
// size_t					ft_strlen(const char *s);
// char					*ft_strdup(const char *s1);
// void					*ft_memalloc(size_t size);
// char					*ft_strchr(const char *s, int c);
// void					ft_putchar(char c);
// void					ft_putstr(char const *s);
// void					ft_putnbr(int n);
// void					ft_putendl(char const *s);
// char					*ft_strcat(char *s1, const char *s2);
// char					*ft_strncat(char *s1, const char *s2, size_t n);
// char					*ft_strjoin(char const *s1, char const *s2);
// int						ft_strcmp(const char *s1, const char *s2);
// char					*ft_lutohex(long unsigned int lu);
// char					*ft_lutooct(long unsigned int lu);
// int						ft_toupper(int c);
// int						ft_atoi(const char *str);
// char					*ft_strcpy(char *s1, const char *s2);
// char					*ft_strncpy(char *s1, const char *s2, size_t n);
// char					*ft_dtoa(double d, unsigned int precision);
// char					*ft_itoa(int n);
// double					ft_fabs(double i);
// void					ft_strreverse(char *str);


/*






void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *s1, void const *s2, size_t n);
void	*ft_memccpy(void *s1, void const *s2, int c, size_t n);
void	*ft_memmove(void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);


size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *s1, const char *s2);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s);
char	**ft_strsplit(char const *s, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		get_next_line(int const fd, char **line);
char	*ft_concat2(const char *s1, const char *s2);
char	*ft_concat2endl(const char *s1, const char *s2);
char	*ft_concat2c(const char *s1, const char *s2, char c);
char	*ft_concat(int nb_elem, ...);
char	*ft_concatc(int nb_elem, ...);
void	ft_strreverse(char *str);
int		ft_isspace(int c);
double	ft_atof(const char *str);
double	ft_fabs(double i);
int		ft_abs(int i);


*/

#endif /* LIBFTPRINTF_H */
