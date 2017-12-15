/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:14:59 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/15 16:17:49 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_roundd(double num, int precision)
{
	int		i;
	double	temp;

	i = 0;
	temp = num;
	while (i < precision)
	{
		num *= 10;
		num -= (int)num;
		i++;
	}
	num *= 10;
	if (num >= 5)
		temp += ft_pow(10, -precision);
	return (temp);
}
