#include<bits/stdc++.h>
using namespace std;

void mergeAlgo(int arr[],int l,int mid,int h)
{
    int b[h+1];
    int i,j,k;
    i = l;
    j = mid+1;
    k=l;
    //COMPARE TWO LIST
    
    while(i<=mid && j<=h)
    {
        if(arr[i] <= arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else if(arr[i] > arr[j])
        {
            b[k] = arr[j];
            j++;

        }
        k++;
    }
    //COPY REMAINING ELEMENT IF ANY
   for(;i<=mid;i++)
   {
       b[k++] = arr[i];
   }
    //COPY REMAINING ELEMENTS IF ANY
   for(;j<=h;j++)
   {
       b[k++] = arr[j];
   }
    //COPY ALL THE SORTED  ELEMENT BACK TO ARRAY ARR
    for(int i=l;i<=h;i++)
    {
        arr[i] = b[i];
    }

}

void mergeSort(int arr[],int l,int h)
{
    if(l<h)
    {
        int mid = (l+h)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,h);
        mergeAlgo(arr,l,mid,h);
    }

}

int main()
{
    int arr[] = {4,3,5,8,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int b[n];
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout << arr[i] <<" ";
    }
    return 0;
}


