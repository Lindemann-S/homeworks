#include <iostream>
#include <cstdlib>
#include "myIntStack2.h"

struct MyStackNode
{
    int data;
    MyStackNode *next;
};

void print(MyStackNode *list)
{
    for (MyStackNode *p = list; p != nullptr; p = p->next)
    {
        printf("%d ", p->data);
    }
    printf("\n");
}

void push(MyStackNode **plist, int d)
{
    MyStackNode *p = new MyStackNode;
    p->data = d;
    p->next = *plist;
    *plist = p;
}

int pop(MyStackNode **plist)
{
    MyStackNode *p = *plist;
    int result = p->data;
    *plist = p->next;
    delete(p);
    return result;
}

bool is_empty(MyStackNode *list)
{
    return list == nullptr;
}

char top(MyStackNode *list)
{
    return list->data;
}
