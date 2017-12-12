/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:58:22 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/11 21:01:45 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		char_handler(va_list *va, t_form *form)
{
	int		i;
	char	*res;

	if (form->lmod && ft_strcmp(form->lmod, "l") == 0)
		return (wchar_handler(va, form));
	res = NULL;
	i = 1;
	if (form->min_w > 1)
	{
		i = form->min_w;
		res = (char *)malloc(sizeof(char) * i);
		res[i] = 0;
		(form->flg->zero == 0) ? ft_memset(res, ' ', i - 1) : ft_memset(res, '0', i - 1);
	}
	if (form->flg->minus == 0)
	{
		ft_putstr(res);
		ft_putchar((char)va_arg(*va, int));
	}
	else
	{
		ft_putchar((char)va_arg(*va, int));
		ft_putstr(res);
	}
	ft_strdel(&res);
	return (i);
}
