#include "Test.h"
#include <iostream>
#include <climits>
using namespace std;

int maxSequenceSum(vector<int> numbers, int begin, int end)
{
  if(begin == end)
    return numbers[begin];

  int index_half = begin + (end - begin)/2;

  int max_left = maxSequenceSum(numbers, begin, index_half);
  int max_right = maxSequenceSum(numbers, index_half+1, end);

  int max_center_to_left = INT_MIN;

  int sum = 0;
  for(int i =index_half; i >= begin; i--){
    sum += numbers[i];
    if(max_center_to_left < sum)
      max_center_to_left = sum;
  }

  int max_center_to_right = INT_MIN;

  sum = 0;
  for(int i =index_half+1; i <= end; i++){
    sum += numbers[i];
    if(max_center_to_right < sum)
      max_center_to_right = sum;
  }

  int max_center = max_center_to_left + max_center_to_right;

  if(max_left > max_center && max_left > max_right)
    return max_left;
  if(max_right > max_center)
    return max_right;
  return max_center;
}

int maxSequenceSum(vector<int> numbers)
{
  return maxSequenceSum(numbers, 0, numbers.size()-1);
}

int maxSequenceSumN2(vector<int> numbers)
{
  int ret = INT_MIN;

  for(int i = 0; i < numbers.size(); i++){
    
    int sum = 0;

    for(int j = i; j < numbers.size(); j++){
      sum += numbers[j];
      if(sum > ret)
        ret = sum;
    }
  }

  return ret;
}

int main ()
{
    test();
    return 0;
}
