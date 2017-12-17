/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 20:08:16 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/17 21:56:45 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <time.h>

static char	*date_str(struct tm tm)
{
	char	*res;
	int		i;
	int		temp;

	i = 0;
	res = (char *)malloc(sizeof(char) * 11);
	temp = tm.tm_year + 1900;
	while (i < 4)
	{
		res[3 - i] = temp % 10 + 48;
		temp /= 10;
		i++;
	}
	res[4] = '-';
	temp = tm.tm_mon + 1;
	res[5] = temp / 10 + 48;
	res[6] = temp % 10 + 48;
	res[7] = '-';
	temp = tm.tm_mday;
	res[8] = temp / 10 + 48;
	res[9] = temp % 10 + 48;
	res[10] = 0;
	return (res);
}

int			date_handler(va_list *va, t_form *form)
{
	time_t		t;
	int			ret;
	struct tm	tm;
	char		*res;

	(void)form;
	(void)va;
	t = time(NULL);
	tm = *localtime(&t);
	res = date_str(tm);
	if (form->flg->minus == 1)
		apply_blanks(&res, form, 1);
	else if (form->flg->zero == 1 && form->prec == -1)
		apply_zero(&res, form);
	else
		apply_blanks(&res, form, 0);
	ft_putstr(res);
	ret = ft_strlen(res);
	ft_strdel(&res);
	return (ret);
}
