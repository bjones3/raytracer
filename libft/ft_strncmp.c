/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 21:51:34 by bjones            #+#    #+#             */
/*   Updated: 2017/08/31 01:36:28 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && *s2 && n-- > 1)
		if (*(s1++) != *(s2++))
			return ((unsigned char)*(--s1) - (unsigned char)*(--s2));
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
