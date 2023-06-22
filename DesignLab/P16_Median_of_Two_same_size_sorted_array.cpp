#include <bits/stdc++.h>
using namespace std;
double median(vector<int> &a)
{
    int n = a.size();
    if (n % 2)
    {
        return double(a[n / 2]);
    }
    return (1.0 * a[n / 2] + 1.0 * a[n / 2 - 1]) / 2.0;
}

double median_two_sorted_array(vector<int> &a, vector<int> &b)
{
    if (a.size() == 2 and b.size() == 2)
    {
        int num1 = max(a[0], b[0]);
        int num2 = min(a[1], b[1]);
        return (1.0 * num1 + 1.0 * num2) / 2.0;
    }
    double m1 = median(a);
    double m2 = median(b);

    if (m1 == m2)
    {
        return m1;
    }
    else if (m1 > m2)
    {
        a.erase(a.begin() + (a.size() / 2) + 1, a.end());
        int st = b.size() % 2 ? b.size() / 2 : b.size() / 2 - 1;
        b.erase(b.begin(), b.begin() + st);
    }
    else
    {
        int st = a.size() % 2 ? a.size() / 2 : a.size() / 2 - 1;
        a.erase(a.begin(), a.begin() + st);
        b.erase(b.begin() + (b.size() / 2) + 1, b.end());
    }
    return median_two_sorted_array(a, b);
}
int main()
{
    // vector<int> a = {1, 12, 20, 40, 50};
    // vector<int> b = {5, 16, 19, 25, 60};
    vector<int> a = {1, 4, 5, 6, 10};
    vector<int> b = {2, 3, 4, 5, 7};
    cout << "The median of two sorted array is: " << median_two_sorted_array(a, b);
}
