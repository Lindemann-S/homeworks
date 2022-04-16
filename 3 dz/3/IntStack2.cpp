#include <iostream>
#include <cstdlib>
#include "IntStack2.h"


struct StackNode
{
    int data;
    StackNode *next;
};

void print(StackNode *list)
{
    for (StackNode *p = list; p != nullptr; p = p->next)
    {
        printf("%d ", p->data);
    }
    printf("\n");
}

void push(StackNode *&plist, int d)
{
    StackNode *p = new StackNode;
    p->data = d;
    p->next = plist;
    plist = p;
}

int pop(StackNode *&plist)
{
    StackNode *p = plist;
    int result = p->data;
    plist = p->next;
    delete(p);
    return result;
}

bool is_empty(StackNode *list)
{
    return list == nullptr;
}

char top(StackNode *list)
{
    return list->data;
}
