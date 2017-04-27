#include "Test.h"
#include <iostream>
using namespace std;

bool exists(vector<int> ordered_numbers, int x, int begin, int end){
	int current_pos = begin + (end - begin)/2;
	int current = ordered_numbers[current_pos];

	printf("searching %d beg %d end %d pos %d val %d\n", x, begin, end, current_pos, current);

	if(current == x)
		return true;
	else if(current_pos > begin && x < current){
		printf("Left\n");
		return exists(ordered_numbers, x, begin, current_pos-1);
	}else if(current_pos < end && x > current){
		printf("Right\n");
		return exists(ordered_numbers, x, current_pos+1, end);
	}
	return false;
}

bool numberExists(vector<int> ordered_numbers, int x)
{
	int sz = ordered_numbers.size();
	
    return exists(ordered_numbers, x, 0, sz-1);
}

int main ()
{
    test();
    return 0;
}
