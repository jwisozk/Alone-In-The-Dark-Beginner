/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:13:21 by jwisozk           #+#    #+#             */
/*   Updated: 2019/05/01 23:24:44 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRACKETS_H
# define BRACKETS_H

# define MAX 1000
# include <unistd.h>
typedef struct  s_stack
{
    char        *elem;
    int         top;
}               t_stack;

#endif
