#include <iostream>
#include <cstdlib>
#include "IntStack2.h"


struct IntStackNode
{
    int data;
    IntStackNode *next;
};

void print(IntStackNode *list)
{
    for (IntStackNode *p = list; p != nullptr; p = p->next)
    {
        printf("%d ", p->data);
    }
    printf("\n");
}

void push(IntStackNode *&plist, int d)
{
    IntStackNode *p = new IntStackNode;
    p->data = d;
    p->next = plist;
    plist = p;
}

int pop(IntStackNode *&plist)
{
    IntStackNode *p = plist;
    int result = p->data;
    plist = p->next;
    delete(p);
    return result;
}

bool is_empty(IntStackNode *list)
{
    return list == nullptr;
}

char top(IntStackNode *list)
{
    return list->data;
}

void deleteStack(IntStackNode *&list)
{
    for (IntStackNode *p = list; p != nullptr; p = p->next)
    {
        delete (p);
    }
}
