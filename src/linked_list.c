#include "linked_list.h"
#include <stdbool.h>
#include <stdlib.h>

struct node {
    long value;
    struct node *next;
};

static void free_nodes(struct node *root);

static void free_nodes(struct node *root)
{
    if (root && root->next)
        free_nodes(root->next);
    free(root);
}

inline struct linked_list new_linked_list(void)
{
    return (struct linked_list) { 0 };
}

void free_linked_list(struct linked_list list[static 1])
{
    free_nodes(list->first);
}

void clear_linked_list(struct linked_list list[static 1])
{
    free_linked_list(list);
    *list = new_linked_list();
}

bool push_linked_list(struct linked_list list[static 1], long value)
{
    if (list->last) {
        // list->last->next is always NULL
        list->last->next = malloc(sizeof(struct node));
        if (list->last->next == NULL)
            return false;

        list->last->next->value = value;
        list->last = list->last->next;
    } else {
        // if `last` is NULL, so is `first`
        list->first = malloc(sizeof(struct node));
        if (list->first == NULL)
            return false;

        list->first->next = NULL;
        list->first->value = value;
        list->last = list->first;
    }
    list->len++;
    return true;
}

bool push_front_linked_list(struct linked_list list[static 1], long value)
{
    struct node *new = malloc(sizeof(struct node));
    if (new == NULL)
        return false;
    new->value = value;
    new->next = list->first;
    list->first = new;

    list->len++;
    return true;
}

long *index_in_linked_list(struct linked_list list[static 1],
                           unsigned int index)
{
    struct node *current = list->first;
    if (!current)
        return NULL;

    while (index--) {
        if (!current->next)
            return NULL;
        current = current->next;
    }
    return &current->value;
}

long *find_in_linked_list(struct linked_list list[static 1], long value)
{
    struct node *current = list->first;
    if (!current)
        return NULL;

    while (current->value != value) {
        if (!current->next)
            return NULL;
        current = current->next;
    }
    return &current->value;
}
