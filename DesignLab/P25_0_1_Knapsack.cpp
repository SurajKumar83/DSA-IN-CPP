#include <bits/stdc++.h>
using namespace std;
int maximum_profit(int i, int W, vector<pair<int, int>> &wp, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (W >= wp[0].first)
        {
            W -= wp[0].first;
            return wp[0].second;
        }
        else
            return 0;
    }
    if (dp[i][W] != -1)
        return dp[i][W];
    int nottake = 0 + maximum_profit(i - 1, W, wp, dp);
    int take = 0;
    if (W >= wp[i].first)
    {
        W -= wp[i].first;
        take = wp[i].second + maximum_profit(i - 1, W, wp, dp);
    }
    return dp[i][W] = max(take, nottake);
}
int main()
{
    int n;
    cout << "Enter the size: ";
    cin >> n;
    cout << "Enter the pairs of weight and profit: " << endl;
    vector<pair<int, int>> wp;
    int w, p;
    for (int i = 0; i < n; i++)
    {
        cin >> w >> p;
        wp.push_back({w, p});
    }
    int target;
    cout << "Enter the target ";
    cin >> target;
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    cout << "Maximum Profit: " << maximum_profit(n - 1, target, wp, dp) << endl;
    return 0;
}
