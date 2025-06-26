/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hientranpc <hientranpc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 02:25:33 by hientranpc        #+#    #+#             */
/*   Updated: 2025/06/26 20:15:19 by hientranpc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int is_format(char contype)
{
    if (contype == 'c' || contype == 's' || contype == 'p' || contype == 'd' || contype == 'i' || contype == 'u' || contype == 'x' || contype == 'X')
        return(1);
    return(0);
}

static int printer(char type,va_list list)
{
    size_t size;

    size = 0;
    if (type == 's')
        size = ft_putstr_fd(va_arg(list,char *), 1);
    if (type == 'c')
        size = ft_putchar_fd((char)va_arg(list,int),1);
    if (type == 'd' || type == 'i')
        ft_putnbr_base_fd(va_arg(list,int),1,10,'d');
    if (type == 'x')
        ft_putnbr_base_fd(va_arg(list,int),1,16,'x');
    if (type == 'X')
        ft_putnbr_base_fd(va_arg(list,int),1,16,'X');

    return (size);
}

int ft_printf(const char *input, ...)
{
    size_t  i;
    size_t  tempsize;
    va_list args;

    i = 0;
    tempsize = 0;
    va_start(args,input);
    while (input[i])
    {            
        if (input[i] == '%' && is_format(input[i + 1]))
        {
            tempsize += printer(input[i + 1],args);
            i++;
        }
        else if (input[i] == '%' && input[i + 1] == '%')
            tempsize += ft_putchar_fd('%',1);
        else
            tempsize += ft_putchar_fd(input[i],1);
        i++;
    }
    va_end(args);
    return (tempsize);   
}