/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 22:56:04 by bjones            #+#    #+#             */
/*   Updated: 2017/08/31 01:37:08 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *new;

	if (!s)
		return (NULL);
	new = ft_strnew(len);
	if (!new)
		return (NULL);
	while (len > 0)
	{
		*(new + len - 1) = *(s + start + len - 1);
		len--;
	}
	return (new);
}
