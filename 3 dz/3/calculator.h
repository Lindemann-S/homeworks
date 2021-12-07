#pragma once
#include <iostream>
#include "IntStack2.h"


int stringLenght(char *string);
void calculate(StackNode *&operands, char sign, bool &errorFlag);
int solution(char *inputExpression);
