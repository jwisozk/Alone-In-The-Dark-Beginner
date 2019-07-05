/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 20:59:18 by jwisozk           #+#    #+#             */
/*   Updated: 2019/07/05 20:59:24 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_space(char c)
{
    if (c == '\t' || c == ' ' || c == '\r' || c == '\v' || c == '\f' || c == '\n')
        return (1);
    return (0);
}

int ft_valid(char c, int base)
{
    int n;
    
    if (c >= 48 && c <= 57)
        n = c - 48;
    else if (c >= 65 && c <= 70)
        n = c - 55;
    else if (c >= 97 && c <= 102)
        n = c - 87;
    else
        n = -1;
    
    if (n > --base)
        n = -1;
    return (n);
}

int    ft_atoi_base(const char *str, int str_base)
{
    long    value;
    int     status;
    int     num;
    
    status = 1;
    value = 0;
    while(ft_space(*str))
        str++;
    if (*str == '-')
        status = -1;
    if (*str == '-' || *str == '+')
        str++;
    while ((num = ft_valid(*str, str_base)) != -1)
    {
        value = value * str_base + num;
        if (num < 10 && value % str_base != num)
        {
            if (status == -1)
                return (0);
            return (-1);
        }
        str++;
    }
    return (value * status);
}

int main() {
    char *str = "12fdb3";
    int str_base = 14;
    
    printf("ft_atoi_base:   %i\n", ft_atoi_base(str, str_base));
    
    return 0;
}
