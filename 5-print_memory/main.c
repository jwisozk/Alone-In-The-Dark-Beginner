/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 21:47:07 by jwisozk           #+#    #+#             */
/*   Updated: 2019/05/04 21:47:13 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    print_memory(const void *addr, size_t size);

int    main(void)
{
    int    tab[10] = {0, 23, 150, 255, 12, 16,  21, 42};
    
    print_memory(tab, sizeof(tab));
    return (0);
}
