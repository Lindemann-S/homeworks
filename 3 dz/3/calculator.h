#pragma once
#include <iostream>
#include "myIntStack2.h"


int stringLenght(char *string);
void calculate(MyStackNode **operands, char sign, bool *errorFlag);
int solution(char *inputExpression);
