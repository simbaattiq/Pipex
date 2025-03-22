/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:47:27 by mel-atti          #+#    #+#             */
/*   Updated: 2023/11/13 13:10:05 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;
	size_t	t_length;
	char	*nstr;

	if (s1 == NULL || set == NULL)
		return (NULL);
	first = 0;
	last = ft_strlen(s1);
	while (s1[first] && ft_strchr(set, s1[first]))
		first++;
	while (s1[last - 1] && ft_strchr(set, s1[last - 1]) && last > first)
		last--;
	t_length = (last - first) + 1;
	nstr = (char *) malloc(t_length);
	if (!nstr)
		return (NULL);
	if (t_length > 0)
		ft_strlcpy(nstr, s1 + first, t_length);
	return (nstr);
}
