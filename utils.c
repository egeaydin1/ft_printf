/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeaydin <egeaydin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:51:22 by egeaydin          #+#    #+#             */
/*   Updated: 2025/06/28 21:17:30 by egeaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static size_t	null_check(long long n, char flag)
{
	size_t	size;

	size = 0;
	if (flag == 0)
		return (0);
	if (flag == 'p' && n == 0)
		size += ft_putstr("(nil)");
	else if (flag == 'p' && n != 0)
		size += ft_putstr("0x");
	return (size);
}

size_t	ft_putnbr_base(long long n, size_t base, char flag, int first)
{
	size_t				size;
	unsigned long long	num;

	size = 0;
	if (first--)
		size = null_check(n, flag);
	if (size > 2)
		return (size);
	if (flag != 'p' && n < 0)
	{
		size += ft_putchar('-');
		num = -n;
	}
	else
		num = (unsigned long long)n;
	if (num >= base)
		size += ft_putnbr_base(num / base, base, flag, 0);
	if (flag == 'X')
		size += ft_putchar(DIGITS_UPPER[(num % base)]);
	else
		size += ft_putchar(DIGITS_LOWER[(num % base)]);
	return (size);
}

size_t	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
