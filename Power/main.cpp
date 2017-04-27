#include "Test.h"
#include <iostream>
using namespace std;

int power(int base, int exponent)
{
  if(exponent == 0)
    return 1;
  
  int half = power(base, exponent/2);

  if(exponent%2 == 0)
    return half*half;
  else
    return base*half*half;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
