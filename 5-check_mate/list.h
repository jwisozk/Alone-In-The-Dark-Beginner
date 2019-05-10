/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:11:31 by jwisozk           #+#    #+#             */
/*   Updated: 2019/05/07 19:43:15 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

#include <stdlib.h>
#include <unistd.h>

typedef struct      s_list
{
    char            c;
    int             i;
    int             j;
    struct s_list   *next;
}                   t_list;

#endif
