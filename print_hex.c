/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabdella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:35:00 by wabdella          #+#    #+#             */
/*   Updated: 2025/11/20 20:35:00 by wabdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned int n, int x)
{
	int		count;
	char	*lst_min;
	char	*lst_maj;

	count = 0;
	lst_min = "0123456789abcdef";
	lst_maj = "0123456789ABCDEF";
	if (n >= 16)
		count += print_hex(n / 16, x);
	if (x == 1)
	{
		write(1, &lst_min[n % 16], 1);
		count++;
	}
	else if (x == 0)
	{
		write(1, &lst_maj[n % 16], 1);
		count++;
	}
	return (count);
}
