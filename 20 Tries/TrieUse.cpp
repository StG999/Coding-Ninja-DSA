#include <iostream>
#include "TrieClass.h"

using namespace std;

int main()
{
    Trie t;
    t.insert("and");
    t.insert("are");
    t.insert("dot");

    cout << t.search("are")<<endl;
    cout << t.search("dot")<<endl;
    t.remove("dot");
    cout << t.search("dot")<<endl;
}