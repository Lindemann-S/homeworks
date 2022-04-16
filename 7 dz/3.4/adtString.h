#pragma once

#include <fstream>
#include <iostream>

struct String;

String *createString();
String *createString(char *string);
void deleteString(String *str);
String *clone(String *str);
void concatenation(String *&str1, String *str2);
void concatenation(String *&str, char *string);
bool comparsion(String *str1, String *str2);
int stringLength(String *str);
int strlen(char *str);
bool isEmpty(String *str);
char *substringSelection(String *str, int begin, int end);
char *stringToChar(String *str);
void printString(String *str);
void printString(char *str);
bool isLetter(char ch);
bool isAlpha(char ch);
char toLower(char ch);
char *wordRepair(char *buffer, int i, int maxIndex);
