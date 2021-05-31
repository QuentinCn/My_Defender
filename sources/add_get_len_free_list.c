/*
** EPITECH PROJECT, 2020
** list_action
** File description:
** action on the list
*/

#include "my_defender.h"
#include <stdlib.h>

element_list *add_inlist(element_list *list, element_list *element, int pos)
{
    element_list *prev = list;
    element_list *curr = list;

    if (pos == 0) {
        element->next = list;
        element->prev = NULL;
        return (element);
    }
    for (int i = 0; i < pos; i += 1) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = element;
    element->prev = prev;
    element->next = curr;
    return (list);
}

element_list *get_inlist(element_list *list, int pos)
{
    for (int i = 0; i < pos; i += 1)
        list = list->next;
    return (list);
}

int len_list(element_list *list)
{
    int i = 0;

    for (; list; i += 1)
        list = list->next;
    return (i);
}

element_list *free_inlist(element_list *list, int pos)
{
    element_list *prev = list;
    element_list *curr = list;

    if (pos == 0) {
        curr = list->next;
        free(list);
        return (curr);
    }
    for (int i = 0; i < pos; i += 1) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    free(curr);
    return (list);
}
