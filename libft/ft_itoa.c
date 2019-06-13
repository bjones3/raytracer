/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 19:49:12 by bjones            #+#    #+#             */
/*   Updated: 2017/08/31 01:28:12 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t	ft_intlen(int n)
{
	size_t len;

	len = 1;
	if (n < 0)
		len++;
	while (n /= 10)
		len++;
	return (len);
}

char			*ft_itoa(int n)
{
	char			*s;
	size_t			len;
	unsigned int	n_cpy;

	len = ft_intlen(n);
	if (!(s = ft_strnew(len)))
		return (NULL);
	n_cpy = n;
	if (n < 0)
	{
		*s = '-';
		n_cpy = -n;
	}
	while (n_cpy >= 10)
	{
		*(s + --len) = n_cpy % 10 + '0';
		n_cpy /= 10;
	}
	*(s + --len) = n_cpy + '0';
	return (s);
}
