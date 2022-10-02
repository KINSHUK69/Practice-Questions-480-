 /*
Input:
N = 5
arr[] = {10, 20, 30, 40, 50}
Output: 1
Explanation: The given array is sorted.
 */



bool arraySortedOrNot(int arr[], int n) 
 {
        int c=0;
        for(int i=0;i<n;i++){
            if(arr[i]<arr[i-1]) c=1;
        }
   
        if (c==1)return false;
        return true;
   }
