#include <iostream>
#include <cstdlib>
#include "myCharStack2.h"

struct MyCharStackNode
{
    char data;
    MyCharStackNode *next;
};

void print(MyCharStackNode *list)
{
    for (MyCharStackNode *p = list; p != nullptr; p = p->next)
    {
        printf("%d ", p->data);
    }
    printf("\n");
}

void push(MyCharStackNode **plist, char d)
{
    MyCharStackNode *p = new MyCharStackNode;
    p->data = d;
    p->next = *plist;
    *plist = p;
}

int pop(MyCharStackNode **plist)
{
    MyCharStackNode *p = *plist;
    char result = p->data;
    *plist = p->next;
    delete(p);
    return result;
}

bool is_empty(MyCharStackNode *list)
{
    return list == nullptr;
}

char top(MyCharStackNode *list)
{
    return list->data;
}
