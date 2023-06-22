#include <bits/stdc++.h>
using namespace std;
void f(int i, vector<int> &cur, vector<int> &v, vector<vector<int>> &ans)
{
    if (i == v.size())
    {
        if (cur.size())
        {
            ans.push_back(cur);
        }

        return;
    }
    cur.push_back(v[i]);
    f(i + 1, cur, v, ans);
    cur.pop_back();
    f(i + 1, cur, v, ans);
}
vector<vector<int>> pwset(vector<int> v)
{
    vector<vector<int>> ans;
    vector<int> cur;
    f(0, cur, v, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
// Power Set
vector<string> AllPossibleStrings(string s)
{
    vector<string> ans;
    int n = s.length();
    int size = (1 << n);
    for (int i = 1; i < size; i++)
    {
        string res = "";
        for (int j = 0; j < n; j++)
        {
            if ((1 << j) & i)
                res += s[j];
        }
        ans.push_back(res);
    }
    sort(ans.begin(), ans.end());
    return ans;
}