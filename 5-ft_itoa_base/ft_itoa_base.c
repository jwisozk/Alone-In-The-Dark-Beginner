/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:00:09 by jwisozk           #+#    #+#             */
/*   Updated: 2019/05/13 13:39:00 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     ft_get_len(long num, int base)
{
    int len;

    len = 1;
    if (num < 0 && base == 10)
        len = 2;
    while ((num /= base) != 0)
        len++;
    return (len);
}

void    ft_convert(char *str, long num, int base)
{
    char    *arr;

    arr = "0123456789ABCDEF";
    if (num >= base)
        ft_convert(str - 1, num / base, base);
    if (*str != '-' )
        *str = arr[num % base];
}

void    ft_fill_str(char *str, int len)
{
    int i;

    i = 0;
    while (i <= len)
    {
        str[i] = 0;
        i++;
    }
}

char	*ft_itoa_base(int value, int base)
{
    int  len;
    long num;
    char *str;

    num = value;
    len = ft_get_len(value, base);
    str = (char*)malloc(sizeof(char) * (len + 1));
    ft_fill_str(str, len);
    if (num < 0 && base == 10)
    {
        *str = '-';
        num *= -1;
    }
    ft_convert(str + len - 1, num, base);
    return (str);
}
