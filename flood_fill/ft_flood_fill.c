/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 21:46:42 by jwisozk           #+#    #+#             */
/*   Updated: 2019/04/21 21:46:46 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_point.h"

void fn(char **tab, t_point size, int i, int j)
{
    tab[i][j] = 'F';
    if (i > 0 && tab[i-1][j] == '0')
        fn(tab, size, i-1, j);
    if (j < size.x && tab[i][j+1] == '0')
        fn(tab, size, i, j+1);
    if (i < size.y && tab[i+1][j] == '0')
        fn(tab, size, i+1, j);
    if (j > 0 && tab[i][j-1] == '0')
        fn(tab, size, i, j-1);
}

void  ft_flood_fill(char **tab, t_point size, t_point begin)
{
    size.x = size.x-1;
    size.y = size.y-1;
    if (tab[begin.x-1][begin.y - 1] == '0')
        fn(tab, size, begin.x - 1, begin.y - 1);
}
