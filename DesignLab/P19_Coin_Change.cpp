#include <bits/stdc++.h>
using namespace std;

void minimum_coin(vector<int> &denomination, int targetvalue)
{
    int ans = 0, n = denomination.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (targetvalue >= denomination[i])
        {
            
            ans = targetvalue / denomination[i];
            targetvalue %= denomination[i];
            cout << denomination[i] << " "<<ans<<endl;
        }
        if (targetvalue == 0)
        {
            break;
        }
    }
}
int main()
{

    vector<int> denomination{1, 2, 5, 10, 20, 50, 100, 200, 2000};
    int targetvalue;
    cout << "Enter the Target Value: " << endl;
    cin >> targetvalue;
    cout << "Coins and their numbers" << endl;
    minimum_coin(denomination, targetvalue);
    return 0;
}