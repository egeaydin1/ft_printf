/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeaydin <egeaydin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:52:21 by egeaydin          #+#    #+#             */
/*   Updated: 2025/06/27 20:53:56 by egeaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
#define DIGITS_LOWER "0123456789abcdef"
#define DIGITS_UPPER "0123456789ABCDEF"

int		ft_printf(const char *input, ...);
size_t	ft_strlen(const char *s);
size_t	ft_putchar(char c);
size_t	ft_putstr(char *s);
size_t	null_check(long n, char flag);
size_t	ft_putnbr_base(long n, int base, char flag, int first);
char	*ft_strdup(const char *s);

#endif