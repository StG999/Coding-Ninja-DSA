#include <iostream>
#include "ourMap.h"

using namespace std;

int main()
{
    ourMap<int> map;
    for(int i=0; i<10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = i + 1;
        map.insert(key, value);
        cout<<map.getLoadFactor()<<endl;
    }

    cout<<map.size()<<endl;
    cout<<map.remove("abc2")<<endl;
    cout<<map.remove("abc7")<<endl;
    cout<<map.remove("abc11")<<endl;

    cout<<map.size()<<endl;
    for(int i=0; i<10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        cout<<key<<':'<<map.getValue(key)<<endl;
    }

    cout<<map.size()<<endl;
}