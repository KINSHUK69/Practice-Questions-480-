#include<iostream>
#include<algorithm>

using namespace std;

int max(int arr[],int n)
{
  sort(arr,arr+n+1);
  return arr[n-1];
}

int min(int arr[],int n)
{
  sort(arr,arr+n-1);
  return arr[0];
}
