/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeaydin <egeaydin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:51:22 by egeaydin          #+#    #+#             */
/*   Updated: 2025/06/27 20:55:16 by egeaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
size_t	null_check(long n, char flag)
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

size_t	ft_putnbr_base(long n, int base, char flag, int first)
{
	size_t	size;

	size = 0;
	if (first)
		size = null_check(n, flag);
	first = 0;
	if (size > 2)
		return (size);
	if (n < 0)
	{
		size += ft_putchar('-');
		n = n * (-1);
	}
	if (n >= base)
		size += ft_putnbr_base(n / base, base, flag,0);
	if (flag == 'X')
		size += ft_putchar(DIGITS_UPPER[(n % base)]);
	else
		size += ft_putchar(DIGITS_LOWER[(n % base)]);
	return (size);
}

size_t	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		i += ft_putstr("(null)");
		return (i);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*strptr;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	strptr = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!strptr)
		return (NULL);
	while (s[i])
	{
		strptr[i] = s[i];
		i++;
	}
	strptr[i] = '\0';
	return (strptr);
}
