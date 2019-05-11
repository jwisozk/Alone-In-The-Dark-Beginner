/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 11:10:00 by jwisozk           #+#    #+#             */
/*   Updated: 2019/05/11 19:31:10 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void    ft_fill_arr(int *arr)
{
    int i;

    i = 0;
    while (i < LEN)
    {
        arr[i] = 0;
        i++;
    }
}

t_list     *ft_newlst(char *str)
{
    t_list *lst;

    lst = (t_list*)malloc(sizeof(*lst));
    lst->str = str;
    lst->next = NULL;
    return (lst);
}

void    ft_addlst(t_list **lst, t_list *tmp)
{
    if (tmp != NULL)
    {
        tmp->next = *lst;
        *lst = tmp;
    }
}

int     ft_isprint(int c)
{
    if (c >= 32 && c <= 126)
        return (1);
    return (0);
}

void    ft_interpreter(char *str)
{
    t_list  *lst;
    t_list  *tmp;
    int     *arr;

    lst = NULL;
    arr = (int*)malloc(sizeof(*arr) * LEN);
    ft_fill_arr(arr);
    while (*str != '\0')
    {
        if (*str == '>')
            arr++;
        if (*str == '<')
            arr--;
        if (*str == '+')
            (*arr)++;
        if (*str == '-')
            (*arr)--;
        if (*str == '.' && ft_isprint(*str) == 1)
            write(1, &*arr, 1);
        if (*str == '[')
        {
            if (*arr != 0)
            {
                tmp = ft_newlst(str);
                ft_addlst(&lst, tmp);
            }
            else
                while (*str != ']')
                    str++;
        }
        if (*str == ']')
        {
            if (*arr != 0)
                str = lst->str;
            else
            {
                tmp = lst;
                lst = lst->next;
                free(tmp);
            }
        }
        str++;
    }
}

int	    main(int argc, char **argv)
{
    if (argc == 2)
        ft_interpreter(*(argv + 1));
    else
        write(1, "\n", 1);
    return (0);
}
