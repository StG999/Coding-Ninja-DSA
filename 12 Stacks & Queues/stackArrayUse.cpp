#include <iostream>
#include "stackUsingArray.cpp"

using namespace std;

int main()
{
    StackUsingArray <int> stack(2);
    cout<<stack.getCapacity()<<endl;
    stack.push(10);
    cout<<stack.getSize()<<endl;
    stack.push(20);
    cout<<stack.getCapacity()<<endl;
    stack.push(30);
    cout<<stack.top()<<endl;
    cout<<stack.pop()<<endl;
    stack.push(40);
    cout<<stack.getCapacity()<<endl;
    stack.push(50);
    cout<<stack.pop()<<endl;
    stack.push(60);
    cout<<stack.getCapacity()<<endl;
    cout<<stack.getSize()<<endl;
    stack.push(99);
    cout<<stack.getCapacity()<<endl;
    cout<<stack.getSize()<<endl;
}