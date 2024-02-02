#include <iostream>
#include <cmath>

using namespace std;

int permutations(string input, string output[])
{
    if(input.empty())
        return 1;
    
    int counter = 0;
    for(int i=0; i<input.length(); i++)
    {
        string erased = input.substr(i, 1);
        int ans = permutations(input.erase(i, 1), output + counter);

        for(int j=0; j<ans; j++)
            output[counter + j] = erased + " " + output[counter + j];
            cout<<erased<<" erased\n";

        counter += ans;
    }

    return counter;
}

int main(void)
{
    string input, output[int(pow(2, input.length()))];
    cin>>input;

    int ans = permutations(input, output);
    cout<<"ans: "<<ans<<endl;

    for(int i=0; i<ans; i++)
        cout<<output[i]<<endl;
}