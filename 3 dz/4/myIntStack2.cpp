#include <iostream>
#include <cstdlib>
#include "myIntStack2.h"

struct MyIntStackNode
{
    int data;
    MyIntStackNode *next;
};

void print(MyIntStackNode *list)
{
    for (MyIntStackNode *p = list; p != nullptr; p = p->next)
    {
        printf("%d ", p->data);
    }
    printf("\n");
}

void push(MyIntStackNode **plist, int d)
{
    MyIntStackNode *p = new MyIntStackNode;
    p->data = d;
    p->next = *plist;
    *plist = p;
}

int pop(MyIntStackNode **plist)
{
    MyIntStackNode *p = *plist;
    int result = p->data;
    *plist = p->next;
    delete(p);
    return result;
}

bool is_empty(MyIntStackNode *list)
{
    return list == nullptr;
}

char top(MyIntStackNode *list)
{
    return list->data;
}
