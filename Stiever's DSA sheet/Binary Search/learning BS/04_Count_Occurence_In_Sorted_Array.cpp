class Solution {
public:
  /*
  Time Complexity: O(logN)

  Space Complexity: O(1)
  */
  int search(vector<int>&a,int t){
    int s=0,e=a.size()-1,m;
    while(s<=e){
      m=s+(e-s)/2;
      
      if(a[m]==t) return m;
      else if(t>a[m]) s=m+1;
      else e=m-1;
    }
    return -1;
  }
    vector<int> count(vector<int>& nums, int target) {
      int i=search(nums,target);
      if(i==-1) return -1;
      
      int k=1,right=k+1,left=k-1;
      while(right<nums.size()  && a[right]==target){
        k++;
        right++;
      }
      
      while(left>=0 && a[left]==target){
        k++;
        left--;
      }
      
      return k;
      
        
    }
};
