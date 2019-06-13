/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:00:13 by bjones            #+#    #+#             */
/*   Updated: 2017/08/31 01:28:54 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	*ft_mempcpy(void *dst, const void *src, size_t n)
{
	return (char *)ft_memcpy(dst, src, n) + n;
}

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void *p;

	p = ft_memchr(src, c, n);
	if (p != NULL)
		return (ft_mempcpy(dst, src, p - src + 1));
	ft_memcpy(dst, src, n);
	return (NULL);
}
