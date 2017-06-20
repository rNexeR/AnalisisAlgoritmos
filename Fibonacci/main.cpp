#include "Test.h"
#include <iostream>
#include<cstring>
using namespace std;


int fibonnaci_recursive(int number, int* registro){
  if(number == 0){
    return 0;
  }
  if(number == 1)
    return 1;

  if(registro[number-1] != 0)
    return registro[number-1];
  int return_value = fibonnaci_recursive(number-1, registro) + fibonnaci_recursive(number-2, registro);
  registro[number-1] = return_value;
  return return_value;
}
int fibonacci(int number)
{

  int registro[number];
  registro[0] = 0;
  memset(registro, 0, number * sizeof(int));
  return fibonnaci_recursive(number, registro);
}

int main ()
{
    test();
    return 0;
}
