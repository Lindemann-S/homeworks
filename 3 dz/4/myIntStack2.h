#pragma once

struct MyIntStackNode;

void print(MyIntStackNode *list);
void push(MyIntStackNode **plist, int d);
int pop(MyIntStackNode **plist);
bool is_empty(MyIntStackNode *list);
char top(MyIntStackNode *list);
