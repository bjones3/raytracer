/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 15:39:08 by bjones            #+#    #+#             */
/*   Updated: 2017/08/31 01:36:19 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		i;

	if (!s)
		return (NULL);
	new = (char *)malloc(ft_strlen(s) + 1);
	if (!new)
		return (NULL);
	i = -1;
	while (*(s + ++i))
		*(new + i) = f(i, *(s + i));
	*(new + i) = '\0';
	return (new);
}
