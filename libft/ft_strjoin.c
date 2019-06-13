/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 19:04:41 by bjones            #+#    #+#             */
/*   Updated: 2017/08/31 01:35:31 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
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
	return (new);
}
