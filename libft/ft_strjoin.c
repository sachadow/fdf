/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:25:22 by sderet            #+#    #+#             */
/*   Updated: 2017/12/07 15:38:48 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str != 0)
	{
		str = ft_strcpy(str, s1);
		str = ft_strcat(str, s2);
	}
	else
		return (NULL);
	return (str);
}
