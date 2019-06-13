/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 23:53:21 by bjones            #+#    #+#             */
/*   Updated: 2017/08/31 01:35:27 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*new;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new = ft_strnew(s1_len + s2_len);
	if (!new)
		return (NULL);
	while (s2_len-- > 0)
		*(new + s1_len + s2_len) = *(s2 + s2_len);
	while (s1_len-- > 0)
		*(new + s1_len) = *(s1 + s1_len);
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (new);
}
