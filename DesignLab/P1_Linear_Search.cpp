#include <bits/stdc++.h>
using namespace std;
int findindex(int ind, int arr[], int target, int n)
{
    if (ind == n)
    {
        return -1;
    }
    if (arr[ind] == target)
    {
        return ind;
    }
    return findindex(ind + 1, arr, target, n);
}
int main()
{
    int n, target;
    cout << "Enter the Size: ";
    cin >> n;
    cout << endl;
    cout << "Enter the Target: ";
    cin >> target;
    cout << endl;
    int arr[n];
    cout << "Enter the Array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "The Index of the Number we are find is: " << findindex(0, arr, target, n) << endl;
    return 0;
}