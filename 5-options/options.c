/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 16:01:19 by jwisozk           #+#    #+#             */
/*   Updated: 2019/05/27 19:06:37 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define LEN 32

size_t	ft_strlen(char const *s)
{
    size_t	i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

void    ft_fill_str(char *str)
{
    int i;

    i = 0;
    while (i < LEN)
    {
        str[i] = '0';
        i++;
    }
    str[i] = '\0';
}

int     ft_valid_opt(int count, char **argv, char *arr)
{
    int 	i;
    int 	j;
	char	c;

    ft_fill_str(arr);
    i = 0;
    while (i < count)
    {
        j = 0;
		c = argv[i][j];
        while (argv[i][j] != '\0')
        {
           	if (j == 0 && c != '-')
			{
				while (argv[i][j] != ' ' && argv[i][j] != '\0')
					j++;
				continue ;
			}
			if (j == 0 && c == '-' && argv[i][j + 1] == '\0')
				return (1);
			else if (j != 0 && (argv[i][j] < 'a' || argv[i][j] > 'z'))
				return (1);
			else if (argv[i][j] == 'h')
				return (2);
			else
				arr[argv[i][j] - 97] = '1';
            j++;
        }
        i++;
    }
    return (0);
}

void    ft_usage(char *s)
{
    write(1, &*s, ft_strlen(s));
}

int main(int argc, char **argv)
{
    char arr[LEN + 1];
    int status;
    int i;

    status = ft_valid_opt(argc - 1, argv + 1, arr);
    if (argc > 1 && status == 0)
    {
        i = LEN;
        while (i--)
        {
            write(1, &arr[i], 1);
            if (i != 0 && i % 8 == 0)
                write(1, " ", 1);
        }
        write(1, "\n", 1);
    }
    else if (status == 1)
    {
        ft_usage("Invalid Option\n");
    }
    else
        ft_usage("options: abcdefghijklmnopqrstuvwxyz\n");
    return 0;
}
