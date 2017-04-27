#include "Evaluador.h"
#include <iostream>
using namespace std;

int findPeak(vector<int>);
int findPeakAux(vector<int>, int, int, int);
int findPeakLineal(vector<int>);

int findPeakLineal(vector<int> numbers)
{
    if(numbers.size() == 1 || (numbers.size() > 1 && numbers[0] >= numbers[1]))
        return 0;

    for(int i =1; i < numbers.size() -1; i++){
        if(numbers[i] >= numbers[i+1] && numbers[i] >= numbers[i-1]){
            return i;
        }
    }

    int last_pos = numbers.size() -1;
    if(numbers.size() > 1 && numbers[last_pos] >= numbers[last_pos-1])
        return last_pos;    
    
    return -1;
}

int findPeakAux(vector<int> numbers, int current, int first_pos, int last_pos)
{
    if( (current + first_pos > 0 && numbers[current + first_pos] > numbers[current  + first_pos -1]) ){
        if( current  + first_pos < last_pos ){
            if( numbers[current + first_pos] > numbers[current  + first_pos +1] )
                return current + first_pos;
        }else{
            return current + first_pos;
        }
    }else if( numbers[current + first_pos] <= numbers[current + first_pos -1] ){
        cout<<"left"<<endl;
        return findPeakAux(numbers, (current - first_pos)/2, first_pos, current);
    }else if( numbers[current + first_pos] <= numbers[current + first_pos +1] ){
        cout<<"right"<<endl;
        return findPeakAux(numbers, (current - first_pos)/2, current, last_pos);
    }
}

int findPeak(vector<int> numbers)
{
    return findPeakAux(numbers, numbers.size()/2, 0, numbers.size()-1);
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
