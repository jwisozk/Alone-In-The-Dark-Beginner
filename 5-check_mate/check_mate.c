/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 12:01:13 by jwisozk           #+#    #+#             */
/*   Updated: 2019/05/23 23:05:27 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list *ft_get_coord_king(int len, char **argv)
{
    int i;
    int j;
    t_list *lst;
    
    lst = (t_list*)malloc(sizeof(*lst));
    i = 0;
    while (i < len)
    {
        j = 0;
        while (argv[i][j] != '\0')
        {
            if (argv[i][j] == 'K')
            {
                lst->i = i;
                lst->j = j;
                
            }
            j++;
        }
        i++;
    }
    return (lst);
}

int ft_fn(int x, char s, char f, char c)
{
    if (x == 1 && c == 'P')
        return (1);
    if (c == 'Q' || c == s)
        return (1);
    else if (c == 'P' || c == f)
        return (-1);
    else
        return (0);
}

int ft_is_res(int *arr)
{
    int i;
    
    i = 0;
    while (i < 8)
    {
        if (arr[i] == 1)
            return (1);
        i++;
    }
    return (0);
}

int ft_ischeck(t_list *lst, int len, char **argv, int x, int *arr)
{
    int i;
    int j;
    
    if (x  == len)
        return (0);
    i = lst->i;
    j = lst->j;
    
    if (arr[0] == 0 && i - x >= 0 && j - x >= 0)
        arr[0] = ft_fn(x, 'B', 'R', argv[i - x][j - x]);
    if (arr[1] == 0 && i - x >= 0 && j + x < len)
        arr[1] = ft_fn(x, 'B', 'R', argv[i - x][j + x]);
    if (arr[2] == 0 && i + x < len && j - x >= 0)
        arr[2] = ft_fn(x, 'B', 'R', argv[i + x][j - x]);
    if (arr[3] == 0 && i + x < len && j + x < len)
        arr[3] = ft_fn(x, 'B', 'R', argv[i + x][j + x]);
    if (arr[4] == 0 && j - x >= 0)
        arr[4] = ft_fn(x, 'R', 'B', argv[i][j - x]);
    if (arr[5] == 0 && j + x < len)
        arr[5] = ft_fn(x, 'R', 'B', argv[i][j + x]);
    if (arr[6] == 0 && i - x >= 0)
        arr[6] = ft_fn(x, 'R', 'B', argv[i - x][j]);
    if (arr[7] == 0 && i + x < len)
        arr[7] = ft_fn(x, 'R', 'B', argv[i + x][j]);
    if (ft_is_res(arr) == 1)
        return (1);
    else
        return (ft_ischeck(lst, len, argv, x + 1, arr));
}

void ft_clear_arr(int *arr)
{
    int i;
    
    i = 0;
    while (i < 8)
    {
        arr[i] = 0;
        i++;
    }
}

int ft_check_mate(int len, char **argv)
{
    t_list *lst;
    int arr[8];
    
    ft_clear_arr(arr);
    lst = ft_get_coord_king(len, argv);
    return (ft_ischeck(lst, len, argv, 1, arr));
}
int    main(int argc, char **argv)
{
    if (argc > 1)
    {
        
        if (ft_check_mate(argc - 1, argv + 1) == 1)
            write(1, "Success\n", 8);
        else
            write(1, "Fail\n", 5);
    }
    else
    {
        write(1, "\n", 1);
    }
    return (0);
}
