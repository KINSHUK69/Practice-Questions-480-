#include<iostream>

void RotatePtr(int arr[], int n)   // using two pointers
{
   int left=0,right=n-1;
    while(left<right)
    {
        swap(arr[left],arr[right]);
        left++;
    }
}

void RotateShift(int arr[],int n)    // shifting the array elements to the right 
{
  int f=a[n-1];
   for(int i=n-2;i>=0;i--)
    {
        a[i+1]=arr[i];
    }
   a[0]=f;
}
int main()
{
   int arr[]={1,2,3,4,5};
   int n=sizeof(arr)/size0f(arr[n]);
   RotatePtr(arr,n);
   RotateShift(arr,n);
   return 0;
}
