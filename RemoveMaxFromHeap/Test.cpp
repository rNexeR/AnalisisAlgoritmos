#include "Test.h"

bool compare(vector<int> a, vector<int> b)
{
    for(int i=0;i<(int)a.size();i++)
        if(a[i]!=b[i])
            return false;
    return true;
}

void test()
{

    int arr1[] = { 100, 90, 70, 80, 85, 65, 40};
    vector<int> vec1 (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]) );

    vector<int> answer1 = removeTopFromHeap(vec1);
    int arr1_cmp[] = { 90, 85, 70, 80, 40, 65};
    vector<int> vec1_comp (arr1_cmp, arr1_cmp + sizeof(arr1_cmp) / sizeof(arr1_cmp[0]) );
    bool check1_pass = compare(answer1, vec1_comp);

    vector<int> answer2 = removeTopFromHeap(vec1_comp);
    int arr1b_cmp[] = { 85, 80, 70, 65, 40};
    vector<int> vec2_comp (arr1b_cmp, arr1b_cmp + sizeof(arr1b_cmp) / sizeof(arr1b_cmp[0]) );
    bool check2_pass = compare(answer2, vec2_comp);

    vector<int> answer3 = removeTopFromHeap(vec2_comp);
    int arr1c_cmp[] = { 80, 65, 70, 40};
    vector<int> vec3_comp (arr1c_cmp, arr1c_cmp + sizeof(arr1c_cmp) / sizeof(arr1c_cmp[0]) );
    bool check3_pass = compare(answer3, vec3_comp);

    vector<int> answer4 = removeTopFromHeap(vec3_comp);
    int arr1d_cmp[] = { 70, 65, 40};
    vector<int> vec4_comp (arr1d_cmp, arr1d_cmp + sizeof(arr1d_cmp) / sizeof(arr1d_cmp[0]) );
    bool check4_pass = compare(answer4, vec4_comp);

    vector<int> answer5 = removeTopFromHeap(vec4_comp);
    int arr1e_cmp[] = { 65, 40};
    vector<int> vec5_comp (arr1e_cmp, arr1e_cmp + sizeof(arr1e_cmp) / sizeof(arr1e_cmp[0]) );
    bool check5_pass = compare(answer5, vec5_comp);

    vector<int> answer6 = removeTopFromHeap(vec5_comp);
    int arr1f_cmp[] = { 40};
    vector<int> vec6_comp (arr1f_cmp, arr1f_cmp + sizeof(arr1f_cmp) / sizeof(arr1f_cmp[0]) );
    bool check6_pass = compare(answer6, vec6_comp);

    if(check1_pass
       && check2_pass
       && check3_pass
       && check4_pass
       && check5_pass
       && check6_pass
       )
    {
        cout<<"Test: Pass"<<endl;
    }else
    {
        cout<<"Test: Fail"<<endl;
    }

}
