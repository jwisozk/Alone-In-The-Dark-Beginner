/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:11:00 by jwisozk           #+#    #+#             */
/*   Updated: 2019/05/18 15:19:24 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list *ft_newlst(long num)
{
	t_list *lst;
	
	lst = (t_list*)malloc(sizeof(*lst));
	lst->num = num;
	lst->prev = NULL;
	return (lst);
}

void ft_addlst(t_list **lst, t_list *tmp)
{
	if (tmp != NULL)
	{
		tmp->prev = *lst;
		*lst = tmp;
	}
}

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

int 	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);	
	return (0);
}

int     ft_calc(char c, long a, long b)
{
    if (c == '+')
        return (a + b);
    if (c == '-')
        return (a - b);
    if (c == '*')
        return (a * b);
    if (c == '/' && b != 0)
        return (a / b);
    if (c == '%' && b != 0)
        return (a % b);
    return (0);
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

int ft_search(char *str, t_list **l)
{
	t_list 	*tmp;
	t_list 	*lst;
    int		num;
	int 	i;
	long 	a;
	long 	b;

	lst = NULL;
	i = 0;
	while (*str != '\0')
    {
		if (ft_valid_caracter(*str) != 1)
                return(0);
        if ((*str == '-' && ft_isdigit(*(str + 1)) == 1) || ft_isdigit(*str) == 1)
        {
			num = atoi(str);
			if ((*str == '-' && num > 0) || (*str != '-' && num < 0))
				return (0);
			tmp = ft_newlst(num);
			ft_addlst(&lst, tmp);
			while (*str != ' ' && *str != '\0')
				str++;	
			i++;
		} 
		else if (ft_is_operator(*str) == 1)
        {
			if (lst == NULL || lst->prev == NULL)
				return (0);
			if (*(str - 1) != ' ' || (*(str + 1) != ' ' && *(str + 1) != '\0'))
				return (0);
           	a = lst->prev->num;
			b = lst->num;
			if ((*str == '%' || *str == '/') && b == 0)
				return (0);
			tmp = lst;
		   	lst = lst->prev;
			free(tmp);
		   	lst->num = ft_calc(*str, a, b);
			if (lst->num > MAX || lst->num < MIN)
				return (0);
		}
		str++;
	}
    if (i == 0 || lst->prev != NULL)
		return(0);
	*l = lst;
	return (1);
}

int	main(int argc, char **argv)
{
    t_list *lst;
    
    if (argc == 2)
    {
		if (ft_search(*(argv + 1), &lst) == 1)
			printf("%li\n", lst->num);
		else
			write(1, "Error\n", 6);
    }
    else
        write(1, "Error\n", 6);
    return (0);
}
