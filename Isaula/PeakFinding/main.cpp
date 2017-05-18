#include "Evaluador.h"
#include <iostream>
using namespace std;
#define LEFT -1
#define RIGHT 1
int find_partner(vector<int> numbers, int index, int left_or_right);
int lineal_algth(vector<int> numbers){
  for(int i=0; i < numbers.size();i++){
    int n = numbers[i];
    int left = find_partner(numbers,i,LEFT);
    int right = find_partner(numbers,i,RIGHT);
    if(n >=left && n >= right)
      return i;
  }
  return 0;
}
int find_partner(vector<int> numbers, int index, int left_or_right){
  if(left_or_right<0){
    if(index==0)
      return 0;
  }else{
    if((index+1)==numbers.size())
      return 0;
  }

  return numbers[index+=left_or_right];
}
int log_algth(vector<int> numbers,int *index){
  int n = numbers[*index];

  int left = find_partner(numbers,*index,LEFT);
  int right = find_partner(numbers,*index,RIGHT);
  if(n >=left && n >= right)
    return *index;
  if(n<=left){
    cout<<"left"<<endl;
    *index-=1;
  }else{
    cout<<"right"<<endl;
    *index+=1;
  }
  return -1;
}

int findPeak(vector<int> numbers)
{
    int index = numbers.size()/2;
    for(int i =0; i<numbers.size();i++){
      int return_val = log_algth(numbers,&index);
      if(return_val>=0)
        return return_val;
    }
    return 0;
}


int findPeakAHMED(vector<int> numbers, int begin, int end)
{
  int current = begin + (end-begin)/2;
  if(current >= 0 && numbers[current] < numbers[current-1])
  {
    return findPeakAHMED(numbers,begin,current);
  }
  if(current < numbers.size()-1 && numbers[current] < numbers[current+1])
  {
    return findPeakAHMED(numbers,current,end);
  }
  return current;
}

int findPeakAHMED(vector<int> numbers)
{
  return findPeakAHMED(numbers,0,numbers.size()-1);
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
