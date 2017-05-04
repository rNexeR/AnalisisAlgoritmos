#include "Test.h"

void test()
{
    int arr1[100];
    int arr1cmp[] = { 150, 100, 85, 90, 75, 70, 80, 40, 10, 65, 45, 50};
    int heap1_size = 0;
    for(int i=0;i<100;i++)
        arr1[i] = -1;

    insertOnHeap(arr1,heap1_size,40);heap1_size++;
    insertOnHeap(arr1,heap1_size,100);heap1_size++;
    insertOnHeap(arr1,heap1_size,70);heap1_size++;
    insertOnHeap(arr1,heap1_size,90);heap1_size++;
    insertOnHeap(arr1,heap1_size,65);heap1_size++;
    insertOnHeap(arr1,heap1_size,80);heap1_size++;
    insertOnHeap(arr1,heap1_size,85);heap1_size++;
    insertOnHeap(arr1,heap1_size,150);heap1_size++;
    insertOnHeap(arr1,heap1_size,10);heap1_size++;
    insertOnHeap(arr1,heap1_size,75);heap1_size++;
    insertOnHeap(arr1,heap1_size,45);heap1_size++;
    insertOnHeap(arr1,heap1_size,50);heap1_size++;


    bool check1_pass = true;
    for(int i=0;i<heap1_size;i++)
    {
        if(arr1[i]!=arr1cmp[i])
            check1_pass=false;
    }

    int arr2[100];
    int arr2cmp[] = { 6, 5, 4, 1, 3, 2 };
    int heap2_size = 0;
    for(int i=0;i<100;i++)
        arr2[i] = -1;

    insertOnHeap(arr2,heap2_size,1);heap2_size++;
    insertOnHeap(arr2,heap2_size,6);heap2_size++;
    insertOnHeap(arr2,heap2_size,4);heap2_size++;
    insertOnHeap(arr2,heap2_size,5);heap2_size++;
    insertOnHeap(arr2,heap2_size,3);heap2_size++;
    insertOnHeap(arr2,heap2_size,2);heap2_size++;

    bool check2_pass = true;
    for(int i=0;i<heap2_size;i++)
    {
        if(arr2[i]!=arr2cmp[i])
            check2_pass=false;
    }

    if(check1_pass
       && check2_pass
       )
    {
        cout<<"Test: Pass"<<endl;
    }else
    {
        cout<<"Test: Fail"<<endl;
    }

}
