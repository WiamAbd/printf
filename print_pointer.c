/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabdella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:55:00 by wabdella          #+#    #+#             */
/*   Updated: 2025/11/20 20:55:00 by wabdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex_p(unsigned long n)
{
	int		count;
	char	*lst_min;

	count = 0;
	lst_min = "0123456789abcdef";
	if (n >= 16)
		count += print_hex_p(n / 16);
	write(1, &lst_min[n % 16], 1);
	count++;
	return (count);
}

int	print_pointer(void *d)
{
	int	count;

	if (d == NULL)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	count = 2;
	count += print_hex_p((unsigned long)d);
	return (count);
}
