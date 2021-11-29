#pragma once

struct MyStackNode;

void print(MyStackNode *list);
void push(MyStackNode **plist, int d);
int pop(MyStackNode **plist);
bool is_empty(MyStackNode *list);
char top(MyStackNode *list);
