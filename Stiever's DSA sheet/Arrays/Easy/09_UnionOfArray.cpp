vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    { int i=0,j=0,k=0;
    vector<int>ans;
      while(i<n && j<m)
      {
          if(arr1[i]<=arr2[j] )
             if(ans.back()!=arr1[i]||ans.size()==0){
              ans.push_back(arr1[i++]);            
              
          }
          else 
          {
            if(ans.back()!=arr2[j] || ans.size()==0)
              ans.push_back(arr2[j++]);
              
          }
          
          
      }
      while(i<n) if(ans.back()!=arr1[i])ans.push_back(arr1[i++]);
      while(j<m) if(ans.back()!=arr2[j])ans.push_back(arr2[j++]);
      return ans;
    }
