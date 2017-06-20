#include "Test.h"
#include <iostream>
#include <map>
using namespace std;
#include<string>
// CantCoins - < amount - ways to return >
map< int, map<int, int> > memo;
int countSolutionsRecursive(vector<int> coins, int amount)
{
  if(amount == 0)
    return 1;

  if(amount < 0)
    return 0;

  if(coins.size()==0 && amount > 0)
    return 0;

  vector<int> coins_wo_last = coins;
  coins_wo_last.pop_back();
  if(memo.find(coins.size()) == memo.end()
      || memo[coins.size()].find(amount) == memo[coins.size()].end())
  {
    memo[coins.size()][amount] = countSolutionsRecursive(coins_wo_last, amount)
           + countSolutionsRecursive(coins, amount - coins[coins.size()-1]);
  }

  return memo[coins.size()][amount];
}

map<string, map<int, int > > memo_2;
							// coin, cant
int countWithCoinsLimit(vector< int >coins, vector<int> cants, int amount ){

	cout<<"-->"<<endl;

	if(amount == 0)
		return 1;

	if(amount < 0)
		return 0;

	if(coins.size() == 0 && amount >0)
		return 0;

	// bool utilizar = false;
	vector< int > coins_copy = coins;
	vector< int > coins_copy_wo_last = coins;

	vector<int> cants_copy = cants;
	vector<int> cants_copy_wo_last = cants;

	coins_copy_wo_last.pop_back();
	cants_copy_wo_last.pop_back();

	if(cants[coins.size()-1] > 0){
		cants_copy[coins.size()-1]--;
		return countWithCoinsLimit(coins_copy, cants_copy, amount - coins[coins.size()-1]) + 
		countWithCoinsLimit(coins_copy_wo_last, cants_copy_wo_last, amount);
	}else{
		return countWithCoinsLimit(coins_copy_wo_last, cants_copy_wo_last, amount);
	}


}


int countSolutions(vector<int> coins, int amount)
{
  memo.clear();
  return countSolutionsRecursive(coins, amount);
}
int main ()
{
    test();
    vector < int > coins;
    vector < int > cants;
    coins.push_back( 1 ); cants.push_back(3);
    coins.push_back( 2 ); cants.push_back(2);
    coins.push_back( 3 ); cants.push_back(1);

    cout<<"possible ways: "<<countWithCoinsLimit(coins, cants,4)<<endl;
    return 0;
}
