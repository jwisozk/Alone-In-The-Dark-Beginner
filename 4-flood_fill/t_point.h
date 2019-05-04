/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_point.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 21:46:29 by jwisozk           #+#    #+#             */
/*   Updated: 2019/04/21 21:46:35 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_POINT_H
# define T_POINT_H
# include <stdio.h>
# include <stdlib.h>

typedef struct  s_point
{
    int x;
    int y;
}               t_point;
void  ft_flood_fill(char **tab, t_point size, t_point begin);
#endif
