/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 00:42:35 by bjones            #+#    #+#             */
/*   Updated: 2017/08/31 01:34:52 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strcpy_until(const char *s, int c)
{
	char	*tmp;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	tmp = (char *)s;
	while (*tmp && *tmp++ != (char)c)
		i++;
	return (ft_strsub(s, 0, i));
}
