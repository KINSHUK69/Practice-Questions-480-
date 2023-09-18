// T.C. = O(n^3)    
// S.C. = O(n)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans(nums1.size(),-1);
        int n1=nums1.size();
        int n2=nums2.size();
        for(int i=0;i<n1;i++){
          int j=0;
          for(;j<n2;j++){
            if(nums1[i]==nums2[j]) break;
          }
          while(j<n2){
            if(nums1[i]<nums2[j]){
              ans[i]=nums2[j];
              j++;
              break;
            }
            else
             j++;
          }          
          
        }
        return ans;        
    }
};
