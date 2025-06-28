/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeaydin <egeaydin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:51:16 by egeaydin          #+#    #+#             */
/*   Updated: 2025/06/28 21:15:45 by egeaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_format(char contype)
{
	if (contype == 'c' || contype == 's' || contype == 'p' || contype == 'd'
		|| contype == 'i' || contype == 'u' || contype == 'x' || contype == 'X')
		return (1);
	return (0);
}

static int	printer(char type, va_list list)
{
	size_t	size;

	size = 0;
	if (type == 's')
		size += ft_putstr(va_arg(list, char *));
	if (type == 'c')
		size += ft_putchar((char)va_arg(list, int));
	if (type == 'd' || type == 'i')
		size += ft_putnbr_base(va_arg(list, int), 10, 'd', 0);
	if (type == 'x')
		size += ft_putnbr_base(va_arg(list, unsigned int), 16, 'x', 0);
	if (type == 'X')
		size += ft_putnbr_base(va_arg(list, unsigned int), 16, 'X', 0);
	if (type == 'u')
		size += ft_putnbr_base(va_arg(list, unsigned int), 10, 'u', 0);
	if (type == 'p')
		size += ft_putnbr_base(va_arg(list, size_t), 16, 'p', 1);
	return (size);
}

int	ft_printf(const char *input, ...)
{
	size_t	i;
	size_t	size;
	va_list	args;

	i = 0;
	size = 0;
	va_start(args, input);
	while (input[i])
	{
		if (input[i] == '%' && is_format(input[i + 1]))
		{
			size += printer(input[i + 1], args);
			i++;
		}
		else if (input[i] == '%' && input[++i] == '%')
			size += ft_putchar('%');
		else
			size += ft_putchar(input[i]);
		i++;
	}
	va_end(args);
	return (size);
}
