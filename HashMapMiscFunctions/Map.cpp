#include "Map.h"

int Map::hash(string str, int rehash)
{
  int sum = 0;

  for(int i=0;i < (int)str.length();i++)
  {
    sum+=str[i];
  }

  return sum + rehash;
}

Map::Map()
{
  for(int i=0;i<999999;i++)
  {
    array.push_back(new pair<string,int>("",0));
  }
}

void Map::put(string key, int value)
{
  int rehash = 0;
  while(array[hash(key,rehash)]->first != ""
        && array[hash(key,rehash)]->first != "deleted")
  {
    rehash++;
  }
  array[hash(key,rehash)] = new pair<string, int>(key,value);
}

int Map::get(string key)
{
  int rehash = 0;
  pair<string, int> current_pair;
  do
  {
    current_pair = *(array[hash(key,rehash)]);
    rehash++;
    if(current_pair.first == key)
      return current_pair.second;

  }while(current_pair.first != "");

  return -1;
}

bool Map::exists(string key)
{
  return get(key) != -1;
}

void Map::remove(string key)
{
  int rehash = 0;
  pair<string, int>* current_pair;
  do
  {
    current_pair = array[hash(key,rehash)];
    rehash++;
    if(current_pair->first == key)
      current_pair->first = "deleted";

  }while(current_pair->first != "");
}

void Map::clear()
{
}

int Map::getSize()
{
  return -1;
}

bool Map::isEmpty()
{
  return false;
}
