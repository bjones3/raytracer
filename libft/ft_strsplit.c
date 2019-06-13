/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 21:13:57 by bjones            #+#    #+#             */
/*   Updated: 2017/08/31 01:36:56 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char			**ft_strsplit(char const *s, char c)
{
	char	**new;
	char	*start;
	int		word_ct;

	if (!s)
		return (NULL);
	word_ct = ft_wordct((char *)s, c);
	new = (char **)malloc(sizeof(char *) * word_ct + 1);
	if (!new)
		return (NULL);
	start = (char *)s;
	while (*s)
	{
		if (*s == c)
		{
			if (start != s)
				*(new++) = ft_strsub(start, 0, s - start);
			start = (char *)s + 1;
		}
		s++;
	}
	if (start != s)
		*(new++) = ft_strsub(start, 0, s - start);
	*new = NULL;
	return (new - word_ct);
}
