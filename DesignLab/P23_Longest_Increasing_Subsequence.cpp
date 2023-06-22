#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    
    for (int i = n - 1; i >= 0; i--)
    {
        for (int prev = i - 1; prev >= -1; prev--)
        {
            int skip = dp[i + 1][prev + 1];
            int take = 0;
            if (prev == -1 || arr[i] > arr[prev])
            {
                take = 1 + dp[i + 1][i + 1];
            }
            dp[i][prev + 1] = max(take, skip);
        }
    }
    cout << "The the longest increasing Subsequence length:  " << dp[0][0] << endl;
    return 0;
}