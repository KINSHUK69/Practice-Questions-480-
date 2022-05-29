void sort012(int arr[], int n)
    {
        /*   bubble sort
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(a[i]>a[j])
                {
                    int temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
            } 
        }                       
        Time Complexity : O(n*n)
        */
      /*
        //  sort(arr,arr+n);        // Time complexity : O(nlogn)
       
        int i, cnt0 = 0, cnt1 = 0, cnt2 = 0;
 
    // Count the number of 0s, 1s and 2s in the array
    for (i = 0; i < n; i++)
    {
        switch (arr[i]) 
        {
        case 0:
            cnt0++;
            break;
        case 1:
            cnt1++;
            break;
        case 2:
            cnt2++;
            break;
        }
    }
 
    // Update the array
    i = 0;
 
    // Store all the 0s in the beginning
    while (cnt0 > 0) 
    {
        arr[i++] = 0;
        cnt0--;
    }
 
    // Then all the 1s
    while (cnt1 > 0)
    {
        arr[i++] = 1;
        cnt1--;
    }
 
    // Finally all the 2s
    while (cnt2 > 0) 
    {
        arr[i++] = 2;
        cnt2--;
    }
        
       
    }
*/
    class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0,m=0,h=nums.size()-1;
        
        while(m<=h){
            
            // if(nums[m]==0){
            //     swap(nums[l++],nums[m++]);                
            // }
            // if(nums[m]==1){
            //     m++;
            // }
            // if(nums[m]==2){
            //     swap(nums[m],nums[h--]);                
            // }
            switch(nums[m]){
                case 0:
                    swap(nums[l++],nums[m++]);
                    break;
                case 1:
                    m++;
                    break;
                case 2:
                    swap(nums[m],nums[h--]);
                    break;
            }
        }
    }
};

    
};
