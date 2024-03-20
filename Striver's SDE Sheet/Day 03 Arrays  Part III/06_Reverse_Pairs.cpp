class Solution {
public:
    void merge(vector<int>&nums,int low,int mid,int high){
        vector<int>temp;
        int left=low,right=mid+1;

        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left++]);
            }
            else{
                temp.push_back(nums[right++]);
            }
        }
        while(left<=mid)temp.push_back(nums[left++]);
        while(right<=high)temp.push_back(nums[right++]);

        for(int i=low;i<=high;i++) nums[i]=temp[i-low];
    }
    int count(vector<int>&nums,int low,int mid,int high){
        int ctr=0;
        int right = mid+1;
        for(int i=low;i<=mid;i++){
            while(right<=high && nums[i]>(long long)2*nums[right]) right++;
            ctr += right-(mid+1);
        }
        return ctr;
    }
    int mergeSort(vector<int>&nums,int low,int high){
        int ctr=0;
        if(low>=high)return ctr;
        int mid=(low+high)/2;

        ctr += mergeSort(nums,low,mid);
        ctr += mergeSort(nums,mid+1,high);
        ctr += count(nums,low,mid,high);
        merge(nums,low,mid,high);

        return ctr;
    }
    int reversePairs(vector<int>& nums) {
       return mergeSort(nums,0,nums.size()-1);
    }
};
