#pragma once

struct MyCharStackNode;

void print(MyCharStackNode *list);
void push(MyCharStackNode **plist, char d);
int pop(MyCharStackNode **plist);
bool is_empty(MyCharStackNode *list);
char top(MyCharStackNode *list);
