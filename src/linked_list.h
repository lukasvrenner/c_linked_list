#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

/*
 * A singly-linked list.
 * The current implementation seperately allocates each node.
 * Before this structure is dropped, its destructor,
 * `free_linked_list()`, must be called.
 */
struct linked_list {
    struct node *first;
    struct node *last;
    unsigned long len;
};

struct linked_list new_linked_list(void);

/*
 *  Appends `value` to `list`.
 *
 *  param list[static 1]: the list to push to
 *  param value: the value to push on the list
 *
 *  This is a constant-time operation.
 */
bool push_linked_list(struct linked_list list[static 1], long value);

bool push_front_linked_list(struct linked_list list[static 1], long value);

/*
 * Frees all of the elements in `list`.
 *
 * param list[static 1]: the list to free.
 * WARNING: using the list or any pointers to nodes of the list after freeing
 * is undefined behavior. If more safety is wanted, use `clear_linked_list()`
 */
void free_linked_list(struct linked_list list[static 1]);

/*
 * Frees all of the elements in `list` and zeroes its values
 */
void clear_linked_list(struct linked_list list[static 1]);

long *index_in_linked_list(struct linked_list list[static 1],
                           unsigned int index);

long *find_in_linked_list(struct linked_list list[static 1], long value);

#endif
