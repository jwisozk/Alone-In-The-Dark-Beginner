/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:10:16 by jwisozk           #+#    #+#             */
/*   Updated: 2019/05/01 23:25:15 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void init(t_stack *stk)
{
    stk->top = 0;
}

void push(t_stack *stk, char c)
{
    if (stk->top < MAX)
    {
        stk->elem[stk->top] = c;
        stk->top++;
    }
}

char pop(t_stack *stk)
{
    if (stk->top > 0)
    {
        stk->top--;
        return(stk->elem[stk->top]);
    }
}

char stk_top(t_stack *stk)
{
    if (stk->top > 0)
        return(stk->elem[stk->top - 1]);
    else
        return('0');
}

int ft_valid(char *str)
{
    t_stack stk;
    int     i;
    char    c;

    init (&stk);
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
            push(&stk, str[i]);
        if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            c = stk_top(&stk);
            if (str[i] == c + 1 || str[i] == c + 2)
                pop(&stk);
            else
            {
                stk.top = -1;
                break ;
            }
        }
        i++;
    }
    return (stk.top);
}

int main(int argc, char **argv)
{
    int i;

    if (argc > 1)
    {
        i = 1;
        while (i < argc)
        {
            if (ft_valid(argv[i]) != 0)
            {
                write(1, "Error\n", 6);
                return (0);
            }
            i++;
        }
        while (i-- > 1)
        {
            write(1, "OK\n", 3);
        }
    }
    else
    {
        write(1, "\n", 1);
    }
    return 0;
}
