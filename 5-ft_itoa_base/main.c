#include "list.h"

int	    main(int argc, char **argv)
{
    int value;
    int base;
    char *str;

    if (argc == 3)
    {
        value = atoi(argv[1]);
        base = atoi(argv[2]);
        str = ft_itoa_base(value, base);
        printf("%s\n", str);
    }
    return (0);
}
