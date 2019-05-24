/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_detector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 16:10:26 by jwisozk           #+#    #+#             */
/*   Updated: 2019/05/23 20:06:25 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void        ft_assign_value(const t_list **turtle, const t_list **rabbit)
{
    if (*rabbit != NULL && (*rabbit)->next != NULL)
    {
        *turtle = (*turtle)->next;
        *rabbit = (*rabbit)->next->next;
    }
}

int        cycle_detector(const t_list *list)
{
    const t_list      *turtle;
    const t_list      *rabbit;
    
    turtle = list;
    rabbit = list;
    ft_assign_value(&turtle, &rabbit);
    while (list != NULL && turtle != rabbit)
        ft_assign_value(&turtle, &rabbit);
    return (list == NULL ? 0 : 1);
}
