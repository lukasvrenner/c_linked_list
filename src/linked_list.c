#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"

struct node {
    long value;
    struct node *next;
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

bool push_linked_list(struct linked_list *list, long value)
{
    if (!list) return false;
    if (list->last) {
        // list->last->next is always NULL
        list->last->next = malloc(sizeof(struct node));
        list->last->next->value = value;
        list->last = list->last->next;
    } else {
        // if `last` is empty, so is `first`
        list->first = malloc(sizeof(struct node));
        list->first->next = NULL;
        list->first->value = value;
        list->last = list->first;
    }
    list->len++;
    return true;
}

bool push_front_linked_list(struct linked_list *list, long value)
{
    if (!list) return false;

    struct node *new = malloc(sizeof(struct node));
    new->value = value;
    new->next = list->first;
    list->first = new;

    list->len++;
    return true;
}

long *index_in_linked_list(struct linked_list *list, unsigned int index)
{
    struct node *current = list->first;
    if (!current) return NULL;
        while (index--) {
            if (!current->next) return NULL;
            current = current->next;
        }
    return &current->value;
}

long *find_in_linked_list(struct linked_list *list, long value)
{
    struct node *current = list->first;
    if (!current) return NULL;
    while (current->value != value) {
        if (!current->next) return NULL;
        current = current->next;
    }
    return &current->value;
}

