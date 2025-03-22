/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:25:38 by mel-atti          #+#    #+#             */
/*   Updated: 2023/11/11 14:51:13 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		d_len;
	size_t		total_len;
	const char	*s;

	s = src;
	if (!size)
		return (ft_strlen(s));
	d_len = 0;
	while (*(dst + d_len) && d_len < size)
		d_len++;
	if (d_len < size)
		total_len = (d_len + 1) + (ft_strlen(s) + 1);
	else
		return (size + ft_strlen(s));
	while (*s && (d_len + 1) < size)
	{
		*(dst + d_len) = *s++;
		d_len++;
	}
	*(dst + d_len) = '\0';
	return (total_len);
}
// int main(){
// 	char dst[20] = "";
// 	char str2[20] = "World";
// 	printf("Mine   ==>  %lu\n", ft_strlcat(dst, str2, 8));
// 	printf("theirs ==>  %lu\n", strlcat(dst, str2, 8));
// 	printf("Mine   ==>  %s\n", dst);
// 	printf("theirs ==>  %s\n", dst);

// }