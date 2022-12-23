#include<iostream>
using namespace std;
void quicksort(int[],int,int);
void swap(int,int);
int main()
{
    int n=10;
    int arr[n],i;
    cout<<"........Quick Sort........\n";
    for(i=0;i<n;i++)
    {
        cout<<"Enter Element:"<<i+1;
        cin>>arr[i];
    }
    quicksort(arr,0,n-1);
    cout<<"......Sorted Array......\n";
    for(i=0;i<n;i++)
    {
        cout<<"Element "<<i+1<<":"<<arr[i];
    }
}
void swap(int s,int e)
{
    int temp = arr[s];
    arr[s]=arr[e];
    arr[e]=temp;
}
void quicksort(int arr[],int low,int high)
{
    int start = low;
    int end = high;
    int mid = (low + high)/2;
    while(start<=end)
    {
        while(arr[start]<arr[mid])
        {
           start++;
        }
        while(arr[mid]>arr[end])
        {
           end++;
        }
        if(start<=end)
        {
            swap(start,end);
        }

    }
    quicksort(arr[],low,end);
    quicksort(arr[],start,high);
}