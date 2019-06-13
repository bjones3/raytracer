/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 18:36:05 by bjones            #+#    #+#             */
/*   Updated: 2017/08/31 01:36:32 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t srclen;

	srclen = ft_strlen(src);
	if (srclen < len)
	{
		ft_bzero(dst + srclen, len - srclen);
		return (ft_memcpy(dst, src, srclen));
	}
	else
		return (ft_memcpy(dst, src, len));
}
