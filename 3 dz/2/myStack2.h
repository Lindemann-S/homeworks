#pragma once

struct StackNode;

void print(StackNode *list);
void push(StackNode *&plist, int d);
int pop(StackNode *&plist);
bool is_empty(StackNode *list);
char top(StackNode *list);
