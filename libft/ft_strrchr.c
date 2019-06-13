/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 18:40:20 by bjones            #+#    #+#             */
/*   Updated: 2017/08/31 01:36:51 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	t;

	ptr = (char *)s;
	while (*s)
	{
		if (*s == (char)c)
		{
			ptr = (char *)s;
			t = 1;
		}
		s++;
	}
	if (c == 0)
		return ((char *)s);
	if (t == 1)
		return (ptr);
	return (NULL);
}
