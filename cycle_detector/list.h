/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 16:15:21 by jwisozk           #+#    #+#             */
/*   Updated: 2019/05/02 17:40:15 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct      s_list
{
    int             data;
    struct s_list   *next;
}                   t_list;
t_list              *ft_lstnew(int data);
int                 cycle_detector(const t_list *list);

#endif
