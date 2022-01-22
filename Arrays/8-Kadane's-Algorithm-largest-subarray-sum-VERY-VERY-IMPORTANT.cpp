 long long maxSubarraySum(int arr[], int n)                   // Time Complexity : O(n)
    {
        int currentsum=0;
        int maxsum=INT_MIN;                       
        for(int i=0; i<n; i++)                            
        {
          currentsum+=arr[i];
          maxsum=max(maxsum, currentsum);         // only stores max out of the two 
          if(currentsum<0)                        // if current sum becomes negative then reset the value to 0
          {
            currentsum=0;
          }
        }
        return maxsum;
    }
