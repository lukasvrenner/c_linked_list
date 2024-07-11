#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "main.h"

struct node {
    long value;
    struct node *next;
    struct node *prev;
};

static void free_nodes(struct node *root);

int main(void)
{
    struct linked_list my_list = new_linked_list();
    push_linked_list(&my_list, 5);
    printf("%ld\n", my_list.first->value);
    printf("len: %ld\n", my_list.len);

    clear_linked_list(&my_list);
    if (my_list.first) {
        printf("%ld\n", my_list.first->value);
    } else {
        printf("NULL\n");
    }
    printf("len: %ld\n", my_list.len);
    return 0;
}

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
