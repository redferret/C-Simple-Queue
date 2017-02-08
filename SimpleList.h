
/* 
 * File:   SimpleList.h
 * Author: Richard DeSilvey
 * Includes: stdio.h, stdlib.h, stdbool.h
 * Created on January 27, 2017, 9:22 PM
 */

#ifndef SIMPLELIST_H
#define SIMPLELIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define prints_the_data (_PTR data)
#define string char *

/**
 * The Node that contains the data for the list
 */
typedef struct Node {
    _PTR data_ptr;
    struct Node* next_ptr;
} Node;

/**
 * The iterator that helps keep track of the linked-list
 */
typedef struct Iter {
    Node* head_ptr;
    Node* tail_ptr;
    int length;
} Iter;

/**
 * Builds a new list Iter
 * @return The prepared empty list
 */
Iter* get_list();

/**
 * Resets the list pointers and length
 * @param list
 */
void set_list(Iter* list);

/**
 * Enqueues onto the given list the new data. The
 * data is appended to the end of the list.
 * @param list The list receiving the new data
 * @param data The data being added to the list
 */
void add(Iter* list, _PTR data);

/**
 * Dequeues from the given list. Removes from the head.
 */
_PTR dequeue(Iter* list);

/**
 * Calls the given function to handle the generic data
 * for printing.
 * @param list The list being printed
 * @param print The function used to print individual elements in
 * the given list.
 */
void print(Iter* list, void (*print)(_PTR));

/**
 * Internal function, do not call.
 * @param head
 */
void clear(Node* head);

/**
 * Clears the given list
 * @param list The list being cleared
 */
void clear_list(Iter* list);

#endif /* SIMPLELIST_H */

