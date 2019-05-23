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

int main(void)
{
    t_list *lst1;
    t_list *lst2;
    t_list *lst3;

    lst1 = ft_lstnew(1);
    lst2 = ft_lstnew(2);
    lst3 = ft_lstnew(3);

    lst1->next = lst2;
    lst2->next = lst3;
    lst3->next = lst2;

    printf("status = %i\n", cycle_detector(lst1));
    return 0;
}
