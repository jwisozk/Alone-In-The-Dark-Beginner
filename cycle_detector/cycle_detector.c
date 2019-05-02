/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_detector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 16:10:26 by jwisozk           #+#    #+#             */
/*   Updated: 2019/05/02 17:40:10 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list  *ft_lstnew(int data)
{
    t_list *lst;

    if(!(lst = (t_list*)malloc(sizeof(*lst))))
        return (NULL);
    lst->data = data;
    lst->next = NULL;
    return (lst);
}

void    ft_lstadd_back(t_list **head, t_list *new)
{
    t_list *lst;

    lst = *head;
    while (lst->next != NULL)
        lst = lst->next;
    lst->next = new;
}

int        cycle_detector(const t_list *list)
{
    t_list  *head;
    t_list  *tmp;
    int     status;

    head = ft_lstnew(list->data);
    list = list->next;
    while (head != NULL && list != NULL)
    {
        if (head->data != list->data)
        {
            tmp = ft_lstnew(list->data);
            ft_lstadd_back(&head, tmp);
        }
        else
        {
            tmp = head;
            head = head->next;
            free(tmp);
        }
        list = list->next;
    }
    if (head == NULL)
        status = 1;
    if (list == NULL)
        status = 0;
    return (status);
}