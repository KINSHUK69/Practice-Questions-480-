
class Solution
{
    public
    
    static bool comp(pair<int,int>&a,pair<int,int>&b){
        return a.second<b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        int ctr=1;
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++){
            arr.push_back({start[i],end[i]});
        }
        int j=0;
        sort(arr.begin(),arr.end(),comp);
        for(int i=1;i<n;i++){
            if(arr[i].first>arr[j].second){
                j=i;
                ctr++;
            }
        }
        return ctr;
        
    }
};
