#include <bits/stdc++.h>
using namespace std;
#define ll long long

void merge_array(int v[], int p, int mid, int r)
{
    int b[r];
    int k = p;
    int i = p;
    int j = mid + 1;

    while (i <= mid && j <= r)
    {
        if (v[i] <= v[j])
        {
            b[k] = v[i];
            k++;
            i++;
        }
        else if (v[i] > v[j])
        {
            b[k] = v[j];
            j++;
            k++;
        }
    }
    if (i <= mid)
    {
        while (i <= mid)
        {
            b[k] = v[i];
            i++;
            k++;
        }
    }
    else if (j <= r)
    {
        while (j <= r)
        {
            b[k] = v[j];
            j++;
            k++;
        }
    }
    for (int l = p; l <= r; l++)
    {
        v[l] = b[l];
    }
}
void merge_sort(int v[], int p, int r)
{
    if (p < r)
    {
        int mid = (p + r) / 2;
        merge_sort(v, p, mid);
        merge_sort(v, mid + 1, r);
        merge_array(v, p, mid, r);
    }
}
int main()
{
    int n;
    cout << "Enter the size of the array:-> ";
    cin >> n;
    int arr[n] = {0};

    clock_t start, end;
    start = clock();
    
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
    merge_sort(arr, 0, n - 1);
    end = clock();
    cout << "Sorted Array Elements: ";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    cout << endl;
    cout << "Time taken " << (end - start) << endl;
    return 0;
}