#include <bits/stdc++.h>
using namespace std;
int find_index_Binery_Search(int arr[], int target, int l,int h)
{
    if(l>h){
        return -1;
    }
    int mid=l+(h-l)/2;
    if(arr[mid]==target){
        return mid;
    }
    if(arr[mid]<target){//check in right half
        return find_index_Binery_Search(arr,target,mid+1,h);
    }
    //check in left half
    return find_index_Binery_Search(arr,target,l,mid-1);
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
    cout << "Enter the Array in Sorted Form: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "The Index of the Number we are find is: " << find_index_Binery_Search(arr, target, 0,n-1) << endl;
    return 0;
}