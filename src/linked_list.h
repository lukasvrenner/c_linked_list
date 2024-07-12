#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/*
 * A heap-allocated doubly-linked list.
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
 *  param *list: the list to push to
 *  param value: the value to push on the list
 *
 *  This is a constant-time operation.
 */ 
int push_linked_list(struct linked_list *list, long value);

/*
 * Frees all of the elements in the list.
 *
 * param *list: the list to free
 *
 * `list.first` and `list.last` are set to NULL, so it's safe to free twice.
 *
 * WARNING: any pointers to nodes or data in the list will be dangling
 * -- dereferencing them is undefined behavior
 */
void free_linked_list(struct linked_list *list);

/*
 * Clears all elements from `list`.
 * Behaves just like `free_linked_list()`, but it additionally resets the length.
 */
void clear_linked_list(struct linked_list *list);

long *index_in_linked_list(struct linked_list *list, unsigned long index);

long *find_in_linked_list(struct linked_list *list, long value);


#endif
