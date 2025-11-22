/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabdella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 21:20:00 by wabdella          #+#    #+#             */
/*   Updated: 2025/11/20 21:20:00 by wabdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_format(char f, va_list args)
{
	if (f == 'c')
		return (print_char((char)va_arg(args, int)));
	if (f == 's')
		return (print_string(va_arg(args, char *)));
	if (f == 'd' || f == 'i')
		return (print_number(va_arg(args, int)));
	if (f == 'u')
		return (print_unsigned(va_arg(args, unsigned int)));
	if (f == 'x')
		return (print_hex(va_arg(args, unsigned int), 1));
	if (f == 'X')
		return (print_hex(va_arg(args, unsigned int), 0));
	if (f == 'p')
		return (print_pointer(va_arg(args, void *)));
	if (f == '%')
		return (write(1, "%", 1));
	return (write(1, &f, 1));
}

int	ft_printf(const char *f, ...)
{
	va_list	args;
	size_t	i;
	size_t	count;

	va_start(args, f);
	i = 0;
	count = 0;
	while (f[i])
	{
		if (f[i] == '%' && f[i + 1])
		{
			i++;
			count += handle_format(f[i], args);
		}
		else
			count += write(1, &f[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
