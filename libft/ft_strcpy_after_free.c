/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_after_free.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 00:45:38 by bjones            #+#    #+#             */
/*   Updated: 2017/09/19 21:30:47 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strcpy_after_free(char *s, int c)
{
	char	*tmp;
	char	*cpy;
	int		i;

	if (!s)
		return (NULL);
	if (!ft_strchr(s, (char)c))
	{
		ft_strdel(&s);
		return (ft_strnew(0));
	}
	i = 1;
	tmp = s;
	while (*tmp && *tmp++ != (char)c)
		i++;
	cpy = ft_strsub(s, i, ft_strlen(s) - i);
	ft_strdel(&s);
	return (cpy);
}
