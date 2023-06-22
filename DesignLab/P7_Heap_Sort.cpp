#include <bits/stdc++.h>
using namespace std;
#define ll long long

void heapify(vector<int> &v, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && v[largest] <= v[l])
    {
        largest = l;
    }

    if (r < n && v[r] >= v[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        swap(v[i], v[largest]);
        heapify(v, n, largest);
    }
}

void Build_Max_Heap(vector<int> &v)
{
    int n = v.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(v, n, i);
    }
}

vector<int> Heap_sort(vector<int> &v)
{
    
    Build_Max_Heap(v);
    vector<int> ans;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        ans.push_back(v[0]);
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
    return ans;
}

int max_element(vector<int> &v)
{
    int n = v.size();
    if (n == 0)
        return -1;
    int mx = v[0];
    return mx;
}

void heap_increase(vector<int> &v, int i, int key)
{
    if (key < v[i])
    {
        cout << "Error" << endl;
        return;
    }
    v[i] = key;
    while (i >= 0 && v[ceil(float(i)/2.0)-1] < v[i])
    {
        swap(v[i], v[ceil(float(i)/2.0)-1]);
        i = ceil(float(i)/2.0)-1;
    }
}
void insert_element(vector<int> &v, int key)
{
    v.push_back(key);
    heapify(v, v.size(), 0);
}
int main()
{
    int n;
    cout << "Enter the Size of the Array: ";
    cin >> n;
    vector<int> v1(n, 0);

    clock_t start1, end1; // for heap_sort
    start1 = clock();
    for (int i = 0; i < n; i++)
    {
        v1[i] = rand() % 100 +1;
    }
    cout << endl
         << "Entered Elements of the Array: ";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << v1[i] << " ";
    // }
    // cout << endl;

    vector<int> sortedv1 = Heap_sort(v1);
    end1 = clock();

    // cout << "Sorted Array: ";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << sortedv1[i] << " ";
    // }
    // cout << endl;
    cout << "Time for Heap Sort: " << end1 - start1 << endl
         << endl;


    // // for maxelement
    // clock_t start2, end2;
    // start2 = clock();
    // int maxelement = max_element(sortedv1);
    // end2 = clock();

    // cout << "Max element: " << maxelement << endl;

    // cout << "Time for Max Element : " << end2 - start2 << endl
    //      << endl;


    // // insert Element
    // clock_t start3, end3;
    // int element;
    // cout << "Enter the value you want to insert ";
    // cin >> element;
    // cout << "Array before the insert " << endl;

    // // for (int i = 0; i < sortedv1.size(); i++)
    // // {
    // //     cout << sortedv1[i] << " ";
    // // }
    // // cout << endl;

    // start3 = clock();

    // insert_element(sortedv1, element);
    // vector<int> v2=Heap_sort(sortedv1);
    // end3 = clock();

    // cout << "Array after the insert " << endl;

    // // for (int i = 0; i < v2.size(); i++)
    // // {
    // //     cout << v2[i] << " ";
    // // }
    // // cout << endl;
    // cout << "Time for insert element " << end3 - start3 << endl<<endl;


    // // for Value change
    // clock_t start4, end4;

    // int index;
    // cout << "Enter the Index where you want to change the value: ";
    // cin >> index;
    // int key;
    // cout << "Enter the value: ";
    // cin >> key;
    // cout << "Array before the change at the ith index " << endl;
    // // for (int i = 0; i < v2.size(); i++)
    // // {
    // //     cout << v2[i] << " ";
    // // }
    // // cout << endl;
    // start4 = clock();
    // heap_increase(v2, index, key);
    // end4 = clock();
    // cout << "Elements of the array after the change at the ith index " << endl;

    // for (int i = 0; i < v2.size(); i++)
    // {
    //     cout << v2[i] << " ";
    // }
    // cout << endl;
    // cout << "Time for the changing the element at " << index << " th index " << end4 - start4 << endl;
   
    return 0;
}