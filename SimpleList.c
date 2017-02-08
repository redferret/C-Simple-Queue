
#include "SimpleList.h"

Iter* get_list(){
    Iter* list = malloc(sizeof(Iter));
    list->head_ptr = malloc(sizeof(Node));
    set_list(list);
    return list;
}

void set_list(Iter* list){
    list->head_ptr->data_ptr = 0;
    list->head_ptr->next_ptr = 0;
    list->tail_ptr = list->head_ptr;
    list->length = 0;
}

void add(Iter* list, _PTR data) {
    
    if (list->head_ptr->data_ptr == 0){
        list->head_ptr->data_ptr = data;
    }else{
        Node* newNode = malloc(sizeof(Node));
        newNode->data_ptr = data;
        newNode->next_ptr = 0;

        list->tail_ptr->next_ptr = newNode;
        list->tail_ptr = newNode;
    }
    list->length++;
}

_PTR dequeue(Iter* list){
    _PTR data = list->head_ptr->data_ptr;
    if (list->head_ptr != list->tail_ptr){
        Node* temp = list->head_ptr;
        list->head_ptr = list->head_ptr->next_ptr;
        free(temp);
    }else{
        list->head_ptr->data_ptr = 0;
    }
    list->length--;
    return data;
}

void print(Iter* list, void (*print_data)(_PTR)){

    Node* head = list->head_ptr;
    bool empty = head->data_ptr == 0;
    if (!empty){
        Node* next = head;
        while(next != 0){
            print_data(next->data_ptr);
            next = next->next_ptr;
            if (next != 0) {
                printf(", ");
            }
        }
    } else {
        printf("<empty>");
    }
    printf("\n");
    
}

void clear_list(Iter* list){
    if (list->head_ptr->data_ptr != 0){
        clear(list->head_ptr);
        set_list(list);
    }
}

void clear(Node* head){
    Node* next = head->next_ptr;
    
    if (next != 0){
        clear(next);
    }
    
    free(head);
}
