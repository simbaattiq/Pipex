/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:33:42 by mel-atti          #+#    #+#             */
/*   Updated: 2023/11/30 15:06:26 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	num_len(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len = 1;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ntos;
	int		length;
	long	nbr;

	nbr = n;
	length = num_len(nbr);
	ntos = (char *) malloc(length + 1);
	if (!ntos)
		return (NULL);
	ntos[length--] = '\0';
	if (nbr == 0)
		ntos[0] = '0';
	if (nbr < 0)
	{
		ntos[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		ntos[length] = 48 + (nbr % 10);
		nbr /= 10;
		length--;
	}
	return (ntos);
}
