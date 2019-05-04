/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 21:46:44 by jwisozk           #+#    #+#             */
/*   Updated: 2019/05/04 21:46:53 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_print_ascii(unsigned char *ptr, int size)
{
    int i;
    
    if (size < 16)
    {
        i = (16 - size % 16) / 4 * 10;
        while (i--)
            write(1, " ", 1);
    }
    i = 0;
    write(1, " ", 1);
    while (i < size)
    {
        if (*ptr > 31 && *ptr < 127)
            write(1, &(*ptr), 1);
        else
            write(1, ".", 1);
        i++;
        ptr++;
    }
    write(1, "\n", 1);
}

void    print_memory(const void *addr, size_t size)
{
    char            *arr;
    unsigned char   *ptr;
    int             i;
    
    ptr = (unsigned char*)addr;
    arr = "0123456789abcdef";
    i = 0;
    while (i < size)
    {
        if (i % 2 == 0 && i % 16 != 0)
            write(1, " ", 1);
        write(1, &arr[*ptr / 16], 1);
        write(1, &arr[*ptr % 16], 1);
        i++;
        ptr++;
        if ((i % 16 == 0))
            ft_print_ascii(ptr - 16, 16);
        else if (size == i)
            ft_print_ascii(ptr - size % 16, size % 16);
    }
}
