/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 13:31:46 by syzhang           #+#    #+#             */
/*   Updated: 2019/05/04 13:31:48 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <wchar.h>
# include <locale.h>
# include "libft.h"
/*
** d = int;
** D = long int;
** u = unsigned int;
** U = unsigned long int;
** c = char;
** s = char*;
** C = wchar_t;
** S = wchar_t*;
*/

typedef struct s_data
{
    int     precision; //. + int > 0 ->le nb de char, decimal ou chiffres a generer
    int     width; //Si nb de char < au nb min de char, des espaces sont ajoutés
    int     modifier;
    char    format;
    int     hashtag; //0, 0x, 0X
    int     zero; //affiche des 0
    int     plus; //utiliser un signe
    int     minus; //aligne a gauche le resultat selon la largeur du champ
    int     space; //affiche des espaces
    int     sign;
}               t_data;

enum e_modifier
{
    none, h, hh, l, ll, j, z
};

int	    ft_abs(int i);
char	*ft_strnew(size_t size);
char	*ft_ctos(int c);
void	ft_init_flags(t_data *data);
int		ft_isdigit(int c);
int	    ft_isspace(int c);
size_t	ft_count_len(unsigned long long n, int base, size_t count);
char	*ft_itoa_b(unsigned long long n, int base);
int		ft_max(int a, int b);
char	*ft_strtolower(char *str);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
void	ft_strset(char *str, char c, size_t start, size_t end);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
int		ft_ptr(t_data *data, va_list ap);
int		ft_string(t_data *data, va_list ap);
int		ft_char(t_data *data, va_list ap);
intmax_t		ft_signed_int(t_data *data, va_list ap);
uintmax_t		ft_unsigned_int(t_data *data, va_list ap);
int		ft_long(t_data *data, va_list ap);
int		ft_print_start(const char *format, va_list ap);
int		ft_printf(const char *format, ...);
void	ft_get_flags(char **format, t_data *data);
int     ft_parse_int(char **format);
int		ft_parse_modifier(char **format);
char    *ft_parse_args(t_data *data, char **format);
int     check_arg(char **format, va_list ap);
char	*ft_precision(char *str, t_data *data);
int		ft_prefix(char *str, t_data *data);
int		ft_printstr(char *str, t_data *data);
int		ft_print_args(t_data *data, va_list ap);
int		ft_widthsize(int len, t_data *data, char *str);
int		ft_width(size_t len, t_data *data, char *str);
int     ft_wclen(wchar_t c);
int     ft_wcslen(wchar_t *s);
int		ft_putwchar(wchar_t c);
char	*ft_wctostr(wchar_t c);
int	    ft_c_cap(t_data *data, va_list ap);
int		ft_s_cap(t_data *data, va_list ap);

#endif