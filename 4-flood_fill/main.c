/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 21:46:00 by jwisozk           #+#    #+#             */
/*   Updated: 2019/04/21 21:46:18 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_point.h"

char **make_area(char *zone[], t_point size)
{
    char **area;
    int i;
    int j;

    area = (char**)malloc(sizeof(*area) * (size.y + 1));
    area[size.y] = NULL;
    i = 0;
    while (i < size.y)
    {
        area[i] = (char*)malloc(sizeof(char) * (size.x + 1));
        j = 0;
        while (j < size.x)
        {
            area[i][j] = zone[i][j];
            j++;
        }
        area[i][j] = '\0';
        i++;
    }
    return (area);
}

void print_tab(char **area)
{
    int i;

    i = 0;
    while(area[i])
    {
        printf("%s\n", area[i]);
        i++;
    }
}

int main(void)
{
    char **area;
    t_point size = { 8, 5 };
    t_point begin = { 2, 2 };
    char *zone[] = {
            "00111111",
            "10100000",
            "10111110",
            "10000010",
            "10100000"
    };
    area = make_area(zone, size);
    print_tab(area);
    ft_flood_fill(area, size, begin);
    printf("\n");
    print_tab(area);
    return (0);
}
