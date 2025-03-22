/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:32:28 by mel-atti          #+#    #+#             */
/*   Updated: 2023/11/01 18:33:36 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

// int main () {
// 	printf("testing ==>  jkdfhsdgfjhdsgfds \n");
// 	char str[5];
// 	printf ("Mine   ==>  %s\n", ft_memset(str, 'a', 1));
// 	printf ("theirs ==>  %s\n", memset(str, 'a', 1));
// }