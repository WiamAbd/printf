/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabdella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 21:30:00 by wabdella          #+#    #+#             */
/*   Updated: 2025/11/20 21:30:00 by wabdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int	print_char(char c);
int	print_number(int nbr);
int	print_string(char *str);
int	print_pointer(void *d);
int	print_hex(unsigned int n, int x);
int	print_unsigned(unsigned int n);
int	ft_printf(const char *f, ...);

#endif
