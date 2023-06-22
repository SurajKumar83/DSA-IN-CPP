#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1])
        {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}

void rec(vector<int> &arr, int ind)
{
    if (ind == arr.size())
        return;
    int j = ind;
    while (j > 0 && arr[j] < arr[j - 1])
    {
        swap(arr[j], arr[j - 1]);
        j--;
    }
    rec(arr, ind + 1);
}

int main()
{
    vector<int> arr;
    int n;
    cout << "Enter the size of array : ";
    cin >> n;
    cout << "Enter " << n << " elements : ";
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    cout << "Sorted array : ";
    // insertionSort(arr);
    rec(arr, 0);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
