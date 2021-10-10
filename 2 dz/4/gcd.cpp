#include "functions.h"

int gcd(int a, int b)
{
    int c = 0;
   while (b)
   {
      c = a % b;
      a = b;
      b = c;
   }
   return abs(a);
}