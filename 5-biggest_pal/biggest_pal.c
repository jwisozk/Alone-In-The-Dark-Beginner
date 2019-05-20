/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_pal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 19:38:42 by jwisozk           #+#    #+#             */
/*   Updated: 2019/05/20 20:03:20 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(char const *s)
{
    size_t	i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

int ft_bp(char *str, int i, size_t len)
{
    int     j;
    int     cnt1;
    int     cnt2;
    int     st1;
    int     st2;

    j = 0;
    cnt1 = 0;
    cnt2 = 0;
    st1 = 1;
    st2 = 1;
    while (i - j >= 0 && i + j < len)
    {
        if (st1 == 1 && str[i - j] == str[i + j])
            cnt1++;
        else
            st1 = 0;
        if (st2 == 1 && str[i - j] == str[i + j + 1])
            cnt2++;
        else
            st2 = 0;
        j++;
    }
    return (cnt1 > cnt2 ? (cnt1 - 1) * 2 + 1 : cnt2 * 2);
}

int main(int argc, char **argv)
{
    char    *str;
    char    *s;
    int     cnt;
    int     t;
    int     i;
    size_t  len;

    if (argc == 2)
    {
        str = *(argv + 1);
        len = ft_strlen(str);
        i = 0;
        cnt = 0;
        while (str[i] != '\0')
        {
            t = ft_bp(str, i, len);
            if (t >= cnt)
            {
                s = str + i - t / 2 - t % 2 + 1;
                cnt = t;
            }
            i++;
        }
        while (cnt--)
            write(1, &*s++, 1);
    }
    write(1, "\n", 1);
    return (0);
}