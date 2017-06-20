#include "Map.h"

Map::Map()
{
  size = 100000;
  for(unsigned int i=0;i<size;i++)
  {
    array.push_back(new pair<string,int>("",0));
  }
}

int Map::hash(string str)
{
  int sum = 0;

  for(unsigned int i=0;i < (unsigned int)str.length();i++)
  {
    sum+=str[i];
  }

  return sum;
}

void Map::put(string key, int value)
{
  pair<string,int>* empty_pos = array[hash(key)];
  if(empty_pos->first != "" && empty_pos->first != "deleted"){
    empty_pos->second *= value;
  }else{
    empty_pos->first = key;
    empty_pos->second = value;
  }
}

int Map::get(string key)
{
  return array[hash(key)]->second;
}


