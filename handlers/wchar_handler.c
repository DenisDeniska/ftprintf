/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 19:53:37 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/11 17:48:21 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			wchar_handler(va_list *va, t_form *form)
{
	wint_t ch;

	ch = va_arg(*va, wint_t);
	(void)form;
	return (ft_putchar(ch));
}
