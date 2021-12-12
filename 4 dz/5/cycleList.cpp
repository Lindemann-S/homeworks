#include "cycleList.h"

struct ListNode
{
    int value;
    ListNode *next;
};

void addValue(ListNode *&list, int value)
{
    ListNode *newNode = new ListNode;
    newNode->value = value;
    if (list == nullptr)
    {
        list = newNode;
        newNode->next = list;
        return;
    }
    ListNode *plist = list;
    if (newNode->value < list->value)
    {
        while (plist->next != list)
        {
            plist = plist->next;
        }
        newNode->next = list;
        plist->next = newNode;
        list = newNode;
        return;
    }
    while (newNode->value > plist->value && plist->next != list)
    {
        if (newNode->value > plist->next->value)
        {
            plist = plist->next;
        }
        else
        {
            break;
        }
    }
    newNode->next = plist->next;
    plist->next = newNode;
}

void printList(ListNode *list)
{
    if (list == nullptr)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }
    ListNode *plist = list;
    while (plist->next != list)
    {
        std::cout << plist->value << ", ";
        plist = plist->next;
    }
    std::cout << plist->value << ", ";
    std::cout << std::endl;
}

void removeValue(ListNode *&list, int value)
{
    if (list == nullptr)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }
    ListNode *plist = list;
    if (value == plist->value)
    {
        if (plist->next == list)
        {
            delete plist;
            list = nullptr;
            return;
        }
        while (plist->next != list)
        {
            plist = plist->next;
        }
        ListNode *tempNode = plist->next;
        plist->next = plist->next->next;
        list = plist->next;
        delete tempNode;
        return;
    }
    while (value != plist->next->value && plist->next->next != list)
    {
        plist = plist->next;
    }
    if (value != plist->next->value)
    {
        std::cout << "Value not found" << std::endl;
        return;
    }
    ListNode *tempNode = plist->next;
    plist->next = plist->next->next;
    delete tempNode;
}

void removeStepValue(ListNode *&list, int step)
{
    for (int i = 0; i < step; i++)
    {
        list = list->next;
    }
    removeValue(list, list->value);
}

void deleteList(ListNode *&list)
{
    ListNode *plist = list;
    ListNode *delNode = list;
    while (plist->next != list)
    {
        plist = plist->next;
    }
    while (list != list->next)
    {
        plist->next = plist->next->next;
        delNode = list;
        list = list->next;
        delete delNode;
    }
    delete list;
}
