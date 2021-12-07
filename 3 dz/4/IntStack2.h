#pragma once

struct IntStackNode;

void print(IntStackNode *list);
void push(IntStackNode *&plist, int d);
int pop(IntStackNode *&plist);
bool is_empty(IntStackNode *list);
char top(IntStackNode *list);
void deleteStack(IntStackNode *&list);
