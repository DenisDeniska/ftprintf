/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 20:22:50 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/17 21:56:36 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <time.h>

static char	*time_str(struct tm tm)
{
	char	*res;
	int		i;
	int		temp;

	i = 0;
	res = (char *)malloc(sizeof(char) * 9);
	temp = tm.tm_hour;
	res[0] = temp / 10 + 48;
	res[1] = temp % 10 + 48;
	res[2] = ':';
	temp = tm.tm_min;
	res[3] = temp / 10 + 48;
	res[4] = temp % 10 + 48;
	res[5] = ':';
	temp = tm.tm_sec;
	res[6] = temp / 10 + 48;
	res[7] = temp % 10 + 48;
	res[8] = 0;
	return (res);
}

int			time_handler(va_list *va, t_form *form)
{
	time_t		t;
	struct tm	tm;
	char		*res;
	int			ret;

	(void)form;
	(void)va;
	t = time(NULL);
	tm = *localtime(&t);
	res = time_str(tm);
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
