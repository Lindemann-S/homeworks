#pragma once

#include "adtString.h"

struct List;
struct ListNode;

ListNode *searchNode(List *&list, String *str);
ListNode *searchNode(ListNode *&list, String *str);
void print(List *&list);
void push(List *&list, String *str);
String *pop(List &list);
bool isEmpty(List *&list);
String *top(List &list);
void deleteList(List *&list);
char *returnChar(List *list);
int numOfWords(List *list);
int numOfNodes(List *list);
List *createList();
