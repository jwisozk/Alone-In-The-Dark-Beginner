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
#include <stdio.h>

typedef struct      s_list
{
    int             num;
    struct s_list   *prev;
}                   t_list;

#endif
