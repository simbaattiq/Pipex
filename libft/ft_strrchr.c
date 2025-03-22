/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:42:05 by mel-atti          #+#    #+#             */
/*   Updated: 2023/11/13 15:33:48 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*last_oc;

	last_oc = NULL;
	while (*str != '\0')
	{
		if (*str == (char)c)
			last_oc = str;
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return ((char *)last_oc);
}
