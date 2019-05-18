/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:11:31 by jwisozk           #+#    #+#             */
/*   Updated: 2019/05/18 15:18:35 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# define MAX 2147483647
# define MIN -2147483648
typedef struct      s_list
{
    long           	num;
    struct s_list   *prev;
}                   t_list;

#endif
