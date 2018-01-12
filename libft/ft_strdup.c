/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:15:14 by sderet            #+#    #+#             */
/*   Updated: 2017/11/14 14:02:49 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		a;

	a = 0;
	while (s1[a] != '\0')
		a++;
	if ((char*)malloc(sizeof(char) * (a + 1)))
		cpy = (char*)malloc(sizeof(char) * (a + 1));
	else
		return (NULL);
	while (a >= 0)
	{
		cpy[a] = s1[a];
		a--;
	}
	return (cpy);
}
