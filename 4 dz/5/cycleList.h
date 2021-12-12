#pragma once

#include <iostream>

struct ListNode;

void addValue(ListNode *&list, int value);
void printList(ListNode *list);
void removeValue(ListNode *&list, int value);
void deleteList(ListNode *&list);
void removeStepValue(ListNode *&last, int step);
