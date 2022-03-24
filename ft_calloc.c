/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:56:14 by psuanpro          #+#    #+#             */
/*   Updated: 2022/03/12 22:54:59 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int		byte;
	void	*str;

	byte = count * size;
	str = (char *)malloc(byte);
	if (!str)
		return (NULL);
	while (byte > 0)
		((char *)str)[--byte] = 0;
	return (str);
}
