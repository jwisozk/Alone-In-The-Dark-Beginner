/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 12:01:13 by jwisozk           #+#    #+#             */
/*   Updated: 2019/05/10 18:24:35 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list *ft_new_lst(char c, int i, int j)
{
    t_list *lst;

    lst = (t_list*)malloc(sizeof(*lst));
    lst->c = c;
    lst->i = i;
    lst->j = j;
    lst->next = NULL;
    return (lst);
}

void ft_add_lst(t_list **shapes, t_list *tmp)
{
    if (tmp != NULL)
    {
        tmp->next = *shapes;
        *shapes = tmp;
    }
}

t_list *ft_create_shapes(int len, char **argv)
{
    t_list  *shapes;
    t_list  *tmp;
    int     i;
    int     j;

    shapes = NULL;
    i = 0;
    while (i < len)
    {
        j = 0;
        while (argv[i][j] != '\0')
        {
            if (argv[i][j] == 'P' ||
                argv[i][j] == 'B' ||
                argv[i][j] == 'R' ||
                argv[i][j] == 'Q')
            {
                tmp = ft_new_lst(argv[i][j], i, j);
                ft_add_lst(&shapes, tmp);
            }
            j++;
        }
        i++;
    }
    return (shapes);
}

int ft_is_obstacle(char c)
{
    if (c == 'P' ||
        c == 'B' ||
        c == 'R' ||
        c == 'Q')
        return (1);
    return (0);
}

int ft_check_char(char c, int *arr)
{
    if (c == 'K')
        return (1);
    else
        *arr = ft_is_obstacle(c);
    return (0);
}

int ft_pawn(char **argv, int i, int j)
{
    if (argv[i - 1][j - 1] == 'K' || argv[i - 1][j + 1] == 'K')
        return (1);
    return (0);
}

int ft_bishop(char **argv, int i, int j, int len, int x, int *arr)
{
    if (x == len)
        return (0);
    if (i - x >= 0 && j - x >= 0 && arr[0] == 0)
        if (ft_check_char(argv[i - x][j - x], arr) == 1)
            return (1);
    if (i - x >= 0 && j + x < len && arr[1] == 0)
        if (ft_check_char(argv[i - x][j + x], arr + 1) == 1)
            return (1);
    if (i + x < len && j - x >= 0 && arr[2] == 0)
        if (ft_check_char(argv[i + x][j - x], arr + 2) == 1)
            return (1);
    if (i + x < len && j + x < len && arr[3] == 0)
        if (ft_check_char(argv[i + x][j + x], arr + 3) == 1)
            return (1);
    return (ft_bishop(argv, i, j, len, x + 1, arr));
}

int ft_rook(char **argv, int i, int j, int len, int x, int *arr)
{
    if (x == len)
        return (0);
    if (j - x >= 0 && arr[0] == 0)
        if (ft_check_char(argv[i][j - x], arr) == 1)
            return (1);
    if (i - x >= 0 && arr[1] == 0)
        if (ft_check_char(argv[i - x][j], arr + 1) == 1)
            return (1);
    if (j + x < len && arr[2] == 0)
        if (ft_check_char(argv[i][j + x], arr + 2) == 1)
            return (1);
    if (i + x < len && arr[3] == 0)
        if (ft_check_char(argv[i + x][j], arr + 3) == 1)
            return (1);
    return (ft_rook(argv, i, j, len, x + 1, arr));
}

void ft_clear_arr(int *arr)
{
    int i;

    i = 0;
    while (i < 4)
    {
        arr[i] = 0;
        i++;
    }
}

int ft_check_mate(int len, char **argv)
{
    t_list *shapes;
    int arr[4];
    ft_clear_arr(arr);
    shapes = ft_create_shapes(len, argv);

    while (shapes != NULL)
    {
        if (shapes->c == 'P')
            if (ft_pawn(argv, shapes->i, shapes->j) == 1)
                return (1);
        if (shapes->c == 'B')
            if (ft_bishop(argv, shapes->i, shapes->j, len, 1, arr) == 1)
                return (1);
        ft_clear_arr(arr);
        if (shapes->c == 'R')
            if (ft_rook(argv, shapes->i, shapes->j, len, 1, arr) == 1)
                return (1);
        ft_clear_arr(arr);
        if (shapes->c == 'Q')
        {
            if (ft_bishop(argv, shapes->i, shapes->j, len, 1, arr) == 1)
                return (1);
            ft_clear_arr(arr);
            if (ft_rook(argv, shapes->i, shapes->j, len, 1, arr) == 1)
                return (1);
        }
        shapes = shapes->next;
    }
    return (0);
}

int	main(int argc, char **argv)
{
    if (argc > 1)
    {
        if (ft_check_mate(argc - 1, argv + 1) == 1)
            write(1, "Success\n", 8);
        else
            write(1, "Error\n", 6);
    }
    else
    {
        write(1, "\n", 1);
    }
    return (0);
}
