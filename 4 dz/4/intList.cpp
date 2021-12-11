#include "intList.h"

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
        newNode->next = nullptr;
        list = newNode;
        return;
    }
    if (newNode->value < list->value)
    {
        newNode->next = list;
        list = newNode;
        return;
    }
    ListNode *plist = list;
    while (newNode->value > plist->value && plist->next != nullptr)
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
    while (plist->next != nullptr)
    {
        std::cout << plist->value << ", ";
        plist = plist->next;
    }
    std::cout << plist->value << ", ";
    std::cout << std::endl;
}

void removeValue(ListNode *&list)
{
    int value = 0;
    if (list == nullptr)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }
    std::cout << "Enter value: ";
    std::cin >> value;
    ListNode *plist = list;
    if (plist->next == nullptr)
    {
        if (value == plist->value)
        {
            ListNode *tempNode = plist;
            plist = plist->next;
            delete tempNode;
            list = nullptr;
            std::cout << "Value successfully removed" << std::endl;
            return;
        }
        std::cout << "Value not finded" << std::endl;
        return;
    }
    if (value == list->value)
    {
        ListNode *tempNode = list;
        list = list->next;
        delete tempNode;
        std::cout << "Value successfully removed" << std::endl;
        return;
    }
    while (value != plist->next->value && plist->next->next != nullptr)
    {
        plist = plist->next;
    }
    if (value != plist->next->value && plist->next->next == nullptr)
    {
        std::cout << "Value not finded" << std::endl;
        return;
    }
    ListNode *tempNode = plist->next;
    plist->next = plist->next->next;
    delete tempNode;
    std::cout << "Value successfully removed" << std::endl;
}

void deleteList(ListNode *&list)
{
    ListNode *plist = list;
    while (list != nullptr)
    {
        plist = list;
        list = list->next;
        delete plist;
    }
    std::cout << "List successfull deleted" << std::endl;
}
