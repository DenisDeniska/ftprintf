/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:54:28 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/11 18:47:54 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct	s_flags
{
	int			sharp;
	int			zero;
	int			minus;
	int			space;
	int			plus;
}				t_flags;

typedef struct	s_form
{
	t_flags		*flg;
	int			min_w;
	int			prec;
	char		*lmod;
	char		conv;
	int			res;
}				t_form;

typedef struct	s_opp
{
	char		*convers;
	int			(*op)(va_list *va, t_form *form);
}				t_opp;

int				ft_printf(const char *format, ...);
t_flags			*parse_flags(const char **format);
int				parse_w(const char **format);
int				parse_prec(const char **format);
char			*parse_lmod(const char **format);
char			parse_conv(const char **format, t_opp *g_opptab);

char			*dec_handler(t_form *form, intmax_t *num);
char			*unum_handler(t_form *form, uintmax_t *num);
int				string_handler(va_list *va, t_form *form);
int				wstring_handler(va_list *va, t_form *form);
int				pointer_handler(va_list *va, t_form *form);
int				int_handler(va_list *va, t_form *form);
int				longint_handler(va_list *va, t_form *form);
int				octal_handler(va_list *va, t_form *form);
int				longoctal_handler(va_list *va, t_form *form);
int				unsigned_handler(va_list *va, t_form *form);
int				longunsigned_handler(va_list *va, t_form *form);
int				hex_handler(va_list *va, t_form *form);
int				char_handler(va_list *va, t_form *form);
int				wchar_handler(va_list *va, t_form *form);
int				perc_handler(va_list *va, t_form *form);
int				n_handler(va_list *va, t_form *form);
int				failconv_handler(const char **format, t_form *form);

void			apply_plusspace(char **res, t_form *form, char symb);
void			apply_precision(char **res, t_form *form);
void			apply_precisions(char **res, t_form *form);
void			apply_blanks(char **res, t_form *form, int minus);
void			apply_blanksw(char **res, t_form *form, int minus);
void			apply_zero(char **res, t_form *form);
#endif
