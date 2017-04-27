#include "Evaluador.h"

vector<int> getRandomVector()
{
    vector<int> numbers;
    srand(time(NULL));
    for(int i=0;i<10;i++)
    {
        int num = rand()%100;
        numbers.push_back(num);
    }
    return numbers;
}

bool isPeak(vector<int> numbers, int position)
{
    return (position==0 && numbers[1]<=numbers[0])
       || (position==(int)numbers.size()-1 && numbers[numbers.size()-2]<=numbers[numbers.size()-1])
       || (numbers[position]>=numbers[position-1] && numbers[position]>=numbers[position+1]);
}

void evaluar()
{
    vector<int> numbers1 = getRandomVector();
    vector<int> numbers2 = getRandomVector();
    vector<int> numbers3 = getRandomVector();

    int answer1 = findPeak(numbers1);
    int answer2 = findPeak(numbers2);
    int answer3 = findPeak(numbers3);

    if(isPeak(numbers1, answer1) && isPeak(numbers2, answer2) && isPeak(numbers3, answer3))
    {
        cout<<"Pass"<<endl;
    }else
    {
        cout<<"Fail"<<endl;
    }

}
