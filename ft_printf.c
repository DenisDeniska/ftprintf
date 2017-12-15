/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:08:36 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/12 18:34:08 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_opp.h"

static void			free_form(t_form **form)
{
	if (!(*form))
		return ;
	if ((*form)->flg)
		free((*form)->flg);
	if ((*form)->lmod)
		free((*form)->lmod);
	free(*form);
	*form = NULL;
}

static const char	*main_handler(const char *format, va_list *argp, int *res)
{
	t_form		*form;
	int			i;

	form = (t_form *)malloc(sizeof(t_form));
	form->flg = parse_flags(&(format));
	parse_w(argp, &(format), form);
	parse_prec(argp, &(format), form);
	form->lmod = parse_lmod(&(format));
	form->res = *res;
	form->conv = parse_conv(&(format), g_opptab);
	i = 0;
	while (g_opptab[i].convers && form->conv != g_opptab[i].convers[0])
		i++;
	if (form->conv == 0)
		*res += failconv_handler(&format, form);
	else if (g_opptab[i].convers != NULL)
		*res += g_opptab[i].op(argp, form);
	free_form(&form);
	return (format);
}

static int			minift_printf(const char *format, va_list *argp)
{
	int		res;

	res = 0;
	while (*format)
	{
		if (*format == '%')
			format = main_handler(format + 1, argp, &res);
		else
		{
			ft_putchar(*format);
			format++;
			res++;
		}
	}
	return (res);
}

int					ft_printf(const char *format, ...)
{
	va_list		argp;
	int			res;

	va_start(argp, format);
	res = minift_printf(format, &argp);
	va_end(argp);
	return (res);
}
