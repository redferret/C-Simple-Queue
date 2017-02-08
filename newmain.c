
/* 
 * File:   newmain.c
 * Author: Richard
 *
 * Created on January 26, 2017, 7:26 AM
 */

#include "SimpleList.h"

typedef struct Person {
    string name;
    int age;
} Person;

void my_print prints_the_data {
    Person* person = ((Person*)data);
    string name = person->name;
    int age = person->age;
    printf("%s %d", name, age);
}

void str_print prints_the_data {
    printf("%s", (string)data);
}

void set(Person* p, string name, int age){
    p->name = name;
    p->age = age;
}

/*
 * 
 */
int main(int argc, string* argv) {

    Iter* myList = get_list();
    
    Person p1, p2, p3;
    set(&p1, "Richard", 30);
    set(&p2, "Dustin", 32);
    set(&p3, "Ashley", 31);
    
    Person* p4 = malloc(sizeof(Person));
    set(p4, "Jamie", 29);
    
    add(myList, &p1);
    add(myList, p4);
    add(myList, &p3);
    add(myList, &p2);
    
    print(myList, &my_print);
    
    Person* removed = (Person*)dequeue(myList);
    printf("%s was removed from list: ", removed->name);
    print(myList, &my_print);
    clear_list(myList);
    print(myList, &my_print);
    
    add(myList, &p3);
    add(myList, &p2);
    print(myList, &my_print);
    
    
    return (EXIT_SUCCESS);
}
