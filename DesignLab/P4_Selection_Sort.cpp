#include <bits/stdc++.h>
using namespace std;

int min_ind(int a[], int l, int h)
{
    int ind = l;
    for (int i = l + 1; i <= h; i++)
    {
        if (a[ind] > a[i])
        {
            ind = i;
        }
    }
    return ind;
}
int main()
{
    int n;
    cout << "Enter the Size of the Array: ";
    cin >> n;
    cout << endl;
    int a[n];
    cout << "Enter the Array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int minind = min_ind(a, i + 1, n - 1);

        if (a[minind] < a[i])
        {
            swap(a[minind], a[i]);
        }
    }
    cout<<"Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}