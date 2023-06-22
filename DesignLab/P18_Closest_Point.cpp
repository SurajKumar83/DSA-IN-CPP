#include <bits/stdc++.h>
using namespace std;
bool comparex(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}
bool comparey(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
float dist(pair<int, int> p1, pair<int, int> p2)
{
    int x = p1.first - p2.first;
    int y = p1.second - p2.second;
    return sqrt(x * x + y * y);
}
float stripClosest(vector<pair<int, int>> strip, int size, float d)
{
    float mini = d;
    sort(strip.begin(), strip.end(), comparey);
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size && (strip[j].second - strip[i].second < mini); j++)
        {
            if (dist(strip[i], strip[j]) < mini)
            {
                mini = dist(strip[i], strip[j]);
            }
        }
    }
    return mini;
}
float bruteforce(vector<pair<int, int>> &v)
{
    float mini = INT_MAX;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            float dis = dist(v[i], v[j]);
            if (dis < mini)
            {
                mini = dis;
            }
        }
    }
    return mini;
}
float closest(vector<pair<int, int>> &v)
{

    if (v.size() <= 3)
    {
        return bruteforce(v);
    }
    int mid = v.size() / 2;
    pair<int, int> midpoint = v[mid];
    vector<pair<int, int>> left(v.begin(), v.begin() + mid);
    vector<pair<int, int>> right(v.begin() + mid, v.end());
    float dl = closest(left);
    float dr = closest(right);
    float d = min(dl, dr);
    vector<pair<int, int>> strip(v.size());
    int j = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (abs(v[i].first - midpoint.first) < d)
        {
            strip[j] = v[i];
            j++;
        }
    }
    return min(d, stripClosest(strip, j, d));
}
int main()
{
    vector<pair<int, int>> points{{1, 2}, {3, 2}, {4, 2}, {5, 2}, {6, 2}};
    int n = points.size();
    sort(points.begin(), points.end(), comparex);
    cout << "Smallest Dist: " << closest(points) << endl;
}