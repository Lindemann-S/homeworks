#pragma once

struct CharStackNode;

void print(CharStackNode *list);
void push(CharStackNode *&plist, char d);
int pop(CharStackNode *&plist);
bool is_empty(CharStackNode *list);
char top(CharStackNode *list);
void deleteStack(CharStackNode *&list);
