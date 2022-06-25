/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 23:13:15 by fdarrin           #+#    #+#             */
/*   Updated: 2020/07/30 23:57:09 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countlen(unsigned int n)
{
	int	len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

char		*ft_utoa(unsigned int n)
{
	char	*str;
	int		len;

	len = countlen(n);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len--] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
