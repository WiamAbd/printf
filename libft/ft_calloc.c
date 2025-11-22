/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabdella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 22:33:02 by wabdella          #+#    #+#             */
/*   Updated: 2025/11/06 21:30:00 by wabdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*p;
	size_t			total;
	size_t			i;
	unsigned char	*c;

	if (count != 0 && size != 0 && count > SIZE_MAX / size)
		return (NULL);
	total = count * size;
	p = malloc(total);
	if (!p)
		return (NULL);
	c = (unsigned char *)p;
	i = 0;
	while (i < total)
		c[i++] = 0;
	return (c);
}
