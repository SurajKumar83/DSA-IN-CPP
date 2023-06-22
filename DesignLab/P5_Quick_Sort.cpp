#include <bits/stdc++.h>
#include <chrono>
using namespace std;

int partition(vector<int> &arr, int l, int h)
{
    int x = arr[h];
    int i = l - 1;
    for (int j = l; j < h; j++)
    {
        if (arr[j] <= x)
        {
            i = i + 1;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return i + 1;
}
void quick_sort(vector<int> &arr, int l, int h)
{
    if (l < h)
    {
        int q = partition(arr, l, h);
        quick_sort(arr, l, q - 1);
        quick_sort(arr, q + 1, h);
    }
}
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << endl;
    vector<int> arr(n);
    clock_t start, end;
    start = clock();
    cout << "Enter the Array Elements: ";
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % n;
    }
    cout << endl;

    quick_sort(arr, 0, n - 1);
    end = clock();
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Time Taken " << double(end - start) << " microsecond" << endl;
}