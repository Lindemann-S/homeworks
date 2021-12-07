#include <iostream>
#include <cstdlib>
#include "charStack2.h"


struct CharStackNode
{
    char data;
    CharStackNode *next;
};

void print(CharStackNode *list)
{
    for (CharStackNode *p = list; p != nullptr; p = p->next)
    {
        printf("%d ", p->data);
    }
    printf("\n");
}

void push(CharStackNode *&plist, char d)
{
    CharStackNode *p = new CharStackNode;
    p->data = d;
    p->next = plist;
    plist = p;
}

int pop(CharStackNode *&plist)
{
    CharStackNode *p = plist;
    char result = p->data;
    plist = p->next;
    delete(p);
    return result;
}

bool is_empty(CharStackNode *list)
{
    return list == nullptr;
}

char top(CharStackNode *list)
{
    return list->data;
}

void deleteStack(CharStackNode *&list)
{
        for (CharStackNode *p = list; p != nullptr; p = p->next)
    {
        delete (p);
    }
}
