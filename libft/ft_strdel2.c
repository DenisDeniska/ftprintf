/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 20:13:33 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/12 19:00:48 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel2(char **as1, char **as2)
{
	ft_strdel(as1);
	ft_strdel(as2);
}

void	ft_strdel3(char **as1, char **as2, char **as3)
{
	ft_strdel(as1);
	ft_strdel(as2);
	ft_strdel(as3);
}
