/*
Input:
N = 5, K = 2
arr[] = {1,3,4,5,6}
Output: -1
Exlpanation: Since, 2 is not present 
in the array, output is -1.
*/
int searchInSorted(int arr[], int N, int K) 
{ 
    
       int ans=-1;
       for(int i=0;i<N;i++){
           if(arr[i]==K){
               ans=1;
               break;
           }
       }
       return ans;
       
}
