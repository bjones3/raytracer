/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:05:30 by bjones            #+#    #+#             */
/*   Updated: 2017/08/31 01:29:10 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_ptr;

	dst_ptr = dst;
	while (n-- > 0)
		*(dst_ptr++) = *((char *)src++);
	return (dst);
}
