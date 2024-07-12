#include <stdlib.h>
#include <stdint.h>
#include "linked_list.h"
struct node {
    long value;
    struct node *next;
    struct node *prev;
};

static void free_nodes(struct node *root);

static void free_nodes(struct node *root)
{
    if (root->next) free_nodes(root->next);
    free(root);
}

struct linked_list new_linked_list(void)
{
    struct linked_list new = { 0 };
    return new;
}

void free_linked_list(struct linked_list *list)
{
    free_nodes(list->first);

    // prevent dangling pointers and allow safe double free
    list->first = NULL;
    list->last = NULL;
}

void clear_linked_list(struct linked_list *list)
{
    free_linked_list(list);
    list->len = 0;
}

int push_linked_list(struct linked_list *list, long value)
{
    if (!list) return -1;
    if (list->last) {
        // list->last->next is always NULL
        list->last->next = malloc(sizeof(struct node));
        list->last->next->prev = list->last;
        list->last->next->value = value;
        list->last = list->last->next;
    } else {
        list->first = malloc(sizeof(struct node));
        list->first->next = NULL;
        list->first->prev = NULL;
        list->first->value = value;
        list->last = list->first;
    }
    list->len++;
    return 0;
}

long *index_in_linked_list(struct linked_list *list, unsigned long index)
{
    struct node *current;
    if (index <= list->len / 2) {
        current = list->first;

        while (index--) {
            if (!current->next) return NULL;
            current = current->next;
        }
    } else {
        current = list->last;

        while (index--) {
            if (!current->prev) return NULL;
            current = current->next;
        }
    }
    return &current->value;
}

long *find_in_linked_list(struct linked_list *list, long value)
{
    struct node *current = list->first;
    while (current->value != value) {
        if (!current->next) return NULL;
        current = current->next;
    }
    return &current->value;
}

