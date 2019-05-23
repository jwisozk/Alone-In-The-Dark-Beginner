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

int        cycle_detector(const t_list *list)
{
    const t_list  	*tmp;
    int     		i;
    
    i = 100;
    while (list != NULL && i--)
        list = list->next;
    tmp = list;
    if (list != NULL)
        list = list->next;
    while (list != NULL && tmp != list)
        list = list->next;
    return (list == NULL ? 0 : 1);
}
