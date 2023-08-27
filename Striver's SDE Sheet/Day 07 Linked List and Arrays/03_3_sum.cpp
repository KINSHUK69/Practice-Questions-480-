class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // T.L.E.   308/310 test cases
        // set<vector<int>>arr;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         for(int k=j+1;k<n;k++){
        //             if(nums[i]+nums[j]+nums[k]==0){
        //                 vector<int>t={nums[i],nums[j],nums[k]};
        //                 sort(t.begin(),t.end());
        //                 arr.insert(t);
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>>ans(arr.begin(),arr.end());
        // return ans;

        // T.L.E.   310/312 test cases
        // int n=nums.size();
        // set<vector<int>>arr;
        // for(int i=0;i<n;i++){
        //     set<int>s;
        //     for(int j=i+1;j<n;j++){
        //         int a,b;
        //         int c=-(nums[i]+nums[j]);
        //         if(s.find(c)!=s.end()){
        //             vector<int>temp={nums[i],nums[j],c};
        //             sort(temp.begin(),temp.end());
        //             arr.insert(temp);
        //         }
        //         s.insert(nums[j]);
        //     }
            
        // }
        // vector<vector<int>>ans(arr.begin(),arr.end());        
        
        // return ans;

      
        //  T.C. = O(N log N)+ O(N^2)
        // Two Pointer Method

        
        int n=nums.size();
        vector<vector<int>>ans;
        // sorting the array
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            // removing duplicates
            if(i>0 && nums[i]==nums[i-1])continue;

            int j=i+1;
            int k=n-1;

            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum>0) k--;
                else if(sum<0) j++;
                else{
                    // pushing in a sorted array
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                  
                    // removing duplicates
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }

        }
        return ans;

    
    }
};
