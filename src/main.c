#include <stdio.h>
#include <assert.h>
#include "linked_list.h"
int main(void)
{
    struct linked_list my_list = new_linked_list();
    push_linked_list(&my_list, 5);
    push_linked_list(&my_list, 10);

    long *index_1 = (index_in_linked_list(&my_list, 1));
    assert(index_1);
    assert(*index_1 == 10);

    clear_linked_list(&my_list);
    index_1 = (index_in_linked_list(&my_list, 0));
    assert(!index_1);

    return 0;
}
