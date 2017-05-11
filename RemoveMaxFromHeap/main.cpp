#include "Test.h"
#include <iostream>
using namespace std;

uint left_son(uint root){
    return (root*2)+1;
}

uint right_son(uint root){
    return (root*2)+2;
}

vector<int> removeTopFromHeap(vector<int> heap)
{
  vector<int> answer;
  answer = heap;

  answer[0] = answer[answer.size()-1];
  answer.erase(answer.begin()+answer.size()-1);

  uint current = 0;
  while(current < answer.size()){
    uint lson = left_son(current);
    uint rson = right_son(current);
    if(lson < answer.size() && answer[current] < answer[lson] && answer[lson] >= answer[rson]){
      int aux = answer[current];
      answer[current] = answer[lson];
      answer[lson] = aux;
      current = lson;
    }else if(rson < answer.size() &&  answer[current] < answer[rson] && answer[rson] >= answer[lson]){
      int aux = answer[current];
      answer[current] = answer[rson];
      answer[rson] = aux;
      current = rson;
    }else
      break;
  }

  for(int i = 0; i < answer.size(); i++)
    cout<<i<<" "<<answer[i]<<endl;

  return answer;
}

int main ()
{
    test();
    return 0;
}
