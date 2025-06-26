/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hientranpc <hientranpc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 02:27:47 by hientranpc        #+#    #+#             */
/*   Updated: 2025/06/26 20:06:40 by hientranpc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
#define FT_PRINTF
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

size_t	ft_putchar_fd(char c, int fd);
size_t	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_base_fd(int n, int fd, int base, char flag);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
int ft_printf(const char *input, ...);
#endif