#include "list.h"


struct ListNode
{
    String *data;
    ListNode *next;
    int numberOfElements;
};

struct List
{
    ListNode *first;
    int numberOfWords;
    int numberOfNodes;
};

List *createList()
{
    List *list = new List;
    list->first = nullptr;
    list->numberOfWords = 0;
    list->numberOfNodes = 0;
    return list;
}

void print(List *&list)
{
    for (ListNode *node = list->first; node != nullptr; node = node->next)
    {
        printString(node->data);
    }
    std::cout << std::endl;
}

void addNode(List *&list, String *str)
{
    list->numberOfNodes++;
    ListNode *newNode = new ListNode;
    newNode->data = str;
    newNode->numberOfElements = 1;
    newNode->next = list->first;
    list->first = newNode;
}

void push(List *&list, String *str)
{
    list->numberOfWords++;
    if (isEmpty(list))
    {
        addNode(list, str);
        return;
    }
    ListNode *plist = searchNode(list->first, str);
    if (plist != nullptr)
    {
        plist->numberOfElements++;
        return;
    }
    addNode(list, str);
}

ListNode *searchNode(List *&list, String *str)
{
    return searchNode(list->first, str);
}

ListNode *searchNode(ListNode *&list, String *str)
{
    ListNode *plist = list;
    while (plist != nullptr)
    {
        if (comparsion(plist->data, str))
        {
            return plist;
        }
        plist = plist->next;
    }
    return plist;
}

String *pop(List &list, String *str)
{
    ListNode *node = list.first;
    while (node->next != nullptr && comparsion(node->next->data, str) == false)
    {
        node = node->next;
    }
    if (node != nullptr)
    {
        String *result = node->next->data;
        if (node->next->numberOfElements == 1)
        {
            node->next = node->next->next;
            node = node->next;
            deleteString(node->data);
            delete node;
            return result;
        }
        node->next->numberOfElements--;
        return result;
    }
    return nullptr;
}

void deleteList(List *&list)
{
    while (list->first != nullptr)
    {
        ListNode *tempNode = list->first;
        list->first = list->first->next;
        deleteString(tempNode->data);
        delete tempNode;
    }
}

bool isEmpty(List *&list)
{
    return list->first == nullptr;
}

String *top(List &list)
{
    return list.first->data;
}

char *returnChar(List *list)
{
    return stringToChar(list->first->data);
}

int numOfWords(List *list)
{
    return list->numberOfWords;
}

int numOfNodes(List *list)
{
    return list->numberOfNodes;
}
