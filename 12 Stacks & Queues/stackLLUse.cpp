#include <iostream>
#include "stackUsingLL.cpp"

using namespace std;

template <typename T>
void queryHandler(StackUsingLL <T> *stc, int qNo)
{
    switch(qNo)
    {
        case 1:
        {
            int element;
            cin>>element;
            
            (*stc).push(element);
            return;
        }

        case 2:
        {
            cout<<(*stc).pop()<<endl;
            return;
        }
        
        case 3:
        {
            cout<<(*stc).top()<<endl;
            return;
        }

        case 4:
        {
            cout<<(*stc).getSize()<<endl;
            return;
        }

        case 5:
        {
            cout<<(*stc).isEmpty()<<endl;
            return;
        }
    }
}

int main()
{
    StackUsingLL <int> stc;
    int q, qNo;
    cin>>q;

    for(int i=0; i<q; i++)
    {
        cin>>qNo;
        queryHandler(&stc, qNo);
    }
}