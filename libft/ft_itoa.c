/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:51:51 by sderet            #+#    #+#             */
/*   Updated: 2017/11/15 16:55:06 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	long	a;
	size_t	len;
	char	*str;

	a = n;
	len = (n <= 0 ? 2 : 1);
	while (n != 0 && len++)
		n /= 10;
	if (!(str = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	ft_strclr(str);
	len--;
	if (a <= 0)
		str[0] = (a < 0 ? '-' : '0');
	while (a != 0)
	{
		len--;
		str[len] = ((a < 0 ? -a : a) % 10 + '0');
		a /= 10;
	}
	return (str);
}
