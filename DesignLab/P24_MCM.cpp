#include <bits/stdc++.h>
using namespace std;
int mcm(int i, int j, vector<int> &v,vector<vector<int>>&dp)
{
    if (i == j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp = v[i - 1] * v[k] * v[j] + mcm(i, k, v,dp) + mcm(k + 1, j, v,dp);
        ans = min(ans, temp);
    }
    return dp[i][j]=ans;
}
int main()
{

    int n;
    cout << "Enter the number of Elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the numbers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<vector<int> >dp(n,vector<int>(n,-1));
    cout << "The minimum cost of the Matrix Chain Multiplication: " << mcm(1, n - 1, arr,dp) << endl;
}