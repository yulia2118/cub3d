/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 23:00:15 by fdarrin           #+#    #+#             */
/*   Updated: 2020/07/30 23:55:42 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(unsigned long n)
{
	int len;

	len = 1;
	while (n / 16)
	{
		len++;
		n /= 16;
	}
	return (len);
}

char		*ft_tohex(unsigned long n, char mode)
{
	char	*str;
	char	*elem;
	int		len;

	if (mode == 'x')
		elem = HEX_LOW;
	else
		elem = HEX_UPP;
	len = count_len(n);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len--] = elem[n % 16];
		n /= 16;
	}
	return (str);
}
