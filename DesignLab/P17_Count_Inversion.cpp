#include <bits/stdc++.h>
using namespace std;
#define ll long long int
pair<vector<int>, ll> merge(vector<int> &v1)
{
    if (v1.size() == 1)
    {
        return {v1, 0};
    }
    int size = v1.size();
    vector<int> cur;
    vector<int> a(v1.begin(), v1.begin() + size / 2);
    vector<int> b(v1.begin() + size / 2, v1.end());
    pair<vector<int>, ll> p1 = merge(a);
    pair<vector<int>, ll> p2 = merge(b);
    int n = a.size(), m = b.size();
    ll inv = p1.second + p2.second;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] <= b[j])
        {
            cur.push_back(a[i]);
            i++;
        }
        else
        {
            cur.push_back(b[j]);
            j++;
            inv += 1ll * (n - i);
        }
    }
    while (i < n)
    {
        cur.push_back(a[i++]);
    }
    while (j < m)
    {
        cur.push_back(b[j++]);
    }

    return {cur, inv};
}
int main()
{
    vector<int> a = {36343342, 658445766, 281323766, 703538013, 437455363, 900766801, 84401391, 159903601, 626186515, 127519304, 222484765, 609828661, 190927389, 152625748, 358752776, 522920848, 494568773, 977351598, 782415711, 966011559};
    pair<vector<int>, ll> ans = merge(a);
    cout << ans.second << endl;
    return 0;
}