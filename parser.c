/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:31:50 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/12 12:01:17 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		parse_conv(const char **format, t_opp *g_opptab)
{
	char	conv;
	int		i;

	conv = **format;
	i = 0;
	while (g_opptab[i].convers && (g_opptab[i].convers[0] != conv))
		i++;
	if (g_opptab[i].convers == NULL)
		return (0);
	(*format)++;
	return (conv);
}

t_flags		*parse_flags(const char **format)
{
	t_flags *res;

	if (!(res = (t_flags *)malloc(sizeof(t_flags))))
		return (NULL);
	res->sharp = 0;
	res->zero = 0;
	res->plus = 0;
	res->minus = 0;
	res->space = 0;
	while (**format)
	{
		if (**format == '#')
			res->sharp = 1;
		else if	(**format == ' ')
			res->space = 1;
		else if (**format == '0')
			res->zero = 1;
		else if (**format == '-')
			res->minus = 1;
		else if (**format == '+')
			res->plus = 1;
		else
			return (res);
		(*format)++;
	}
	return (res);
}

int			parse_w(va_list *va, const char **format)
{
	int	minw;

	minw = 0;
	if (**format == '*')
	{
		minw = va_arg(*va, int);
		(*format)++;
	}
	if (ft_isdigit(**format))
	{
		minw = 0;
		while (ft_isdigit(**format))
		{
			minw *= 10;
			minw += **format - 48;
			(*format)++;
		}
	}
	if (**format == '*')
	{
		minw = va_arg(*va, int);
		(*format)++;
	}
	return (minw);
}

int			parse_prec(va_list *va, const char **format)
{
	int		prec;

	prec = -1;
	if (**format == '.')
	{
		prec = 0;
		(*format)++;
		if (ft_isdigit(**format))
			while (ft_isdigit(**format))
			{
				prec *= 10;
				prec += **format - 48;
				(*format)++;
			}
		else if (**format == '*')
		{
			prec = va_arg(*va, int);
			(*format)++;
		}
	}
	return (prec);
}

char		*parse_lmod(const char **format)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * 3);
	ft_memset(res, 0, 3);
	if (**format == 'h' || **format == 'l' || **format == 'j'\
			|| **format == 'z')
		res[0] = **format;
	else
	{
		free(res);
		return (NULL);
	}
	(*format)++;
	if ((res[0] == 'h' && **format == 'h') || (res[0] == 'l' \
				&& **format == 'l'))
		res[1] = **format;
	else
		return (res);
	(*format)++;
	return (res);
}
