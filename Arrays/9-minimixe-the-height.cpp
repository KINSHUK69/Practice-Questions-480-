
int getMinDiff(int arr[], int n, int k)           // not passing for multiple test cases
    {
        for(int i=0;i<n;i++)
        {
            if(arr[i]-k<=0)
            arr[i]+=k;
            else 
            arr[i]-=k;
        }
        sort(arr,arr+n);
        return arr[n-1]-arr[0];
    }

int getMinDiff(int arr[], int n, int k)
   {
       sort(arr, arr+n);       
       // idea ->  minimize the min ht & maximize the max ht
       int res = arr[n-1] - arr[0];
       int maxi = arr[n-1];
       int mini = arr[0];
       
       for(int i = 0; i < n-1; i++)
       {
           if(arr[i+1] - k < 0)
              continue;
              
           // minimum element will be either (next_elem - k) or (first_elem + k)
           mini = min(arr[0] + k, arr[i+1] - k);
           
           // maximum element will be either (cur_elem + k) or (last_elem - k)
           maxi = max(arr[i] + k, arr[n-1] - k);
           
           res = min(res, maxi - mini);  //take min
       }
   
     return res;
   }
