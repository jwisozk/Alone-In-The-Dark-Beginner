/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:11:00 by jwisozk           #+#    #+#             */
/*   Updated: 2019/05/07 19:44:36 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int     ft_valid_caracter(char c)
{
    if (c == '+' ||
        c == '-' ||
        c == '*' ||
        c == '/' ||
        c == '%' ||
        c == ' ' ||
        (c >= '0' && c <= '9'))
        return (1);
    return (0);
}

int     ft_calc(char c, int a, int b)
{
    int num;

    if (c == '+')
        num = a + b;
    if (c == '-')
        num = a - b;
    if (c == '*')
        num = a * b;
    if (c == '/')
        num = a / b;
    if (c == '%')
        num = a % b;
    return (num);
}

int    ft_is_operator(char c)
{
    if (c == '+' ||
        c == '-' ||
        c == '*' ||
        c == '/' ||
        c == '%')
        return (1);
    return (0);
}

int print_error(char *str)
{
    printf("%s\n", str);
    return (0);
}

int ft_get_len_num(char *str)
{
    int i;

    i = 0;
    while (str[i] >= '0' && str[i] <= '9')
        i++;
    return (i);
}

char *ft_strcpy(char *nstr, char *str , int sign)
{
    int i;

    i = 0;
    if (sign == 1)
    {
        nstr[i] = '-';
        i++;
    }
    while (*str >= '0' && *str <= '9')
    {
        nstr[i] = *str;
        i++;
        str++;
    }
    nstr[i] = '\0';
    return (nstr);
}

int	main(int argc, char **argv)
{
    char *str;
    t_list *lst;
    t_list *tmp;
    int i;
    int len;
    int sign;
    char *nstr;
    int t;
    int op;

    if (argc == 2)
    {
        str = argv[1];
        lst = NULL;
        tmp = NULL;
        sign = 0;
        i = 0;
        op = 0;
        while (str[i] != '\0')
        {
            if (ft_valid_caracter(str[i] != 1))
                return(print_error("Error"));
            if (str[i] != ' ' && str[i] != '*' && str[i] != '/' && str[i] != '+' && str[i] != '-' && str[i] != '%')
            {
                lst = (t_list*)malloc(sizeof(*lst));
                if (tmp == NULL)
                    lst->prev = NULL;
                else
                    lst->prev = tmp;
                len = ft_get_len_num(str + i);
                if (i != 0 && str[i - 1] == '-')
                    sign = 1;
                nstr = (char*)malloc(sizeof(*nstr) * (len + sign + 1));
                nstr = ft_strcpy(nstr, str + i, sign);
                lst->num = atoi(nstr);
                tmp = lst;
                i += len;
                continue ;
            }
            else if ((op = ft_is_operator(str[i])) == 1 && str[i + 1] < '0' && str[i - 1] == ' ')
            {
                if (lst == NULL || lst->prev == NULL)
                    return(print_error("Error"));
                t = ft_calc(str[i], lst->num, lst->prev->num);
                if ((lst->num > 0 && lst->prev->num > 0 && t < 0) ||
                    (lst->num < 0 && lst->prev->num < 0 && t > 0) ||
                    (str[i] == '*' && t / lst->prev->num != lst->num))
                    return(print_error("Error"));
                lst->prev->num = t;
                lst = lst->prev;
                free(tmp);
                tmp = lst;
            }
            i++;
        }
        if (i == 0 || lst->prev != NULL || op == 0)
            return(print_error("Error"));
        printf("%i\n", lst->num);
    }
    else
        print_error("Error");
    return (0);
}
