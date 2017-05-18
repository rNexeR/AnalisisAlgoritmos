#include "Test.h"
#include "Map.h"

void test()
{
    Map map;
    map.put("A",10);
    map.put("B",20);
    map.put("C",30);
    map.put("arroz",100);
    map.put("zorra",200);
    map.put("abc",1);
    map.put("acb",2);
    map.put("bac",3);
    map.put("bca",4);

    map.remove("A");
    map.remove("zorra");
    map.remove("bac");

    map.put("cab",5);

    Map map2;
    map2.put("A",10);
    map2.put("B",20);
    map2.put("C",30);

    Map map3;
    map3.put("A",10);
    map3.put("B",20);
    map3.put("C",30);
    map3.remove("C");
    map3.clear();
    map3.put("A",100);

    Map map4;

    Map map5;
    map5.put("A",10);
    map5.clear();

    if(map.getSize()==7
       && !map.isEmpty()

       && map2.getSize() == 3
       && !map2.isEmpty()

       && map3.getSize() == 1
       && !map3.isEmpty()
       && map3.get("A") == 100
       && map3.exists("A")
       && !map3.exists("B")
       && !map3.exists("C")

       && map4.getSize() == 0
       && map4.isEmpty()

       && map5.getSize() == 0
       && map5.isEmpty()
       )
   {
       cout<<"Pass"<<endl;
   }else
   {
       cout<<"Fail"<<endl;
   }

}
