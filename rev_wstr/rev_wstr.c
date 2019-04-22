/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 21:58:55 by jwisozk           #+#    #+#             */
/*   Updated: 2019/04/22 21:59:32 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int ft_get_count_of_words(char *str)
{
    int  count;
    int  l;
    
    count = 0;
    l = 0;
    while(str[l] != '\0')
    {
        while (str[l] == ' ' || str[l] == '\t')
            l++;
        if (str[l] != '\0')
        {
            while (str[l] != ' ' && str[l] != '\t' && str[l] != '\0')
                l++;
            count++;
        }
    }
    return (count);
}

char *ft_get_word(char **s)
{
    char    *str;
    int     len;
    int     i;
    
    len = 0;
    while (**s != ' ' && **s != '\t' && **s != '\0')
    {
        len++;
        (*s)++;
    }
    str = (char*)malloc(sizeof(char) * (len + 1));
    *s = *s - len;
    i = 0;
    while (i < len)
    {
        *str = **s;
        str++;
        (*s)++;
        i++;
    }
    *str = '\0';
    return (str - len);
}

void ft_print_word(char *str)
{
    while(*str != '\0')
    {
        write(1, &*str, 1);
        str++;
    }
}

void ft_print_output(char **arr, int count)
{
    while (count--)
    {
        ft_print_word(arr[count]);
        if (count > 0)
            write(1, " ", 1);
        else
            write(1, "\n", 1);
    }
}

int main(int argc, char **argv)
{
    char **arr;
    int  count;
    int  i;
    
    if (argc == 2)
    {
        count = ft_get_count_of_words(argv[1]);
        arr = (char**)malloc(sizeof(*arr) * (count + 1));
        arr[count] = NULL;
        i = 0;
        while (i < count)
        {
            while (*argv[1] == ' ' || *argv[1] == '\t')
                argv[1]++;
            arr[i] = ft_get_word(&argv[1]);
            i++;
        }
        ft_print_output(arr, count);
    }
    else
    {
        write(1, "\n", 1);
    }
    return 0;
}
