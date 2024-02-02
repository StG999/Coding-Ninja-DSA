#include <iostream>
#include <queue>

using namespace std;

void reverseQueue(queue <int> *queue);

int main()
{
    int t;
    cin>>t;
    queue <int> queues[t];

    for(int i=0; i<t; i++)
    {
        int n;
        cin>>n;

        for(int j=0; j<n; j++)
        {
            int x;
            cin>>x;
            queues[i].push(x);
        }

        reverseQueue(&queues[i]);
    }

    for(int i=0; i<t; i++)
    {
        while(!queues[i].empty())
        {
            cout<<queues[i].front()<<' ';
            queues[i].pop();
        }
        cout<<endl;
    }

}

void reverseQueue(queue <int> *queue)
{
    if((*queue).size() == 1)
        return;

    int front = (*queue).front();
    (*queue).pop();

    reverseQueue(queue);

    (*queue).push(front);
}