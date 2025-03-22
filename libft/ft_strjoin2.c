/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:58:26 by mel-atti          #+#    #+#             */
/*   Updated: 2024/01/29 12:58:55 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin2(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*result;

	if (!s1)
	{
		s1 = (char *) malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *) malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);
	result = ft_str_append(s1, s2, result);
	return (result);
}

char	*ft_str_append(char *s1, char *s2, char *result)
{
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = 0;
	len2 = 0;
	if (s1)
	{
		while (s1[len1] != '\0')
		{
			result[len1] = s1[len1];
			len1++;
		}
	}
	while (s2[len2] != '\0')
		result[len1++] = s2[len2++];
	result[len1] = '\0';
	return (result);
}
