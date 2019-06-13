/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 18:14:52 by bjones            #+#    #+#             */
/*   Updated: 2017/08/31 01:36:23 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t s1len;

	s1len = ft_strlen(s1);
	if (n < ft_strlen(s2))
	{
		ft_memcpy(s1 + s1len, s2, n);
		*(s1 + s1len + n) = '\0';
	}
	else
		ft_strcpy(s1 + s1len, s2);
	return (s1);
}
