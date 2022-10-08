/*
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
*/

 
    void moveZeroes(vector<int>& a) {
      
        /*
        Two pointers approach count first occurance of Zero and iterate from it
        
        int k=0,i=0,j,n=a.size();
        
        while(k<n){
            if(a[k]==0){
                break;
            }k++;
        }
        i=k,j=k+1;
        
        while(i<n &&j<n){
            if(a[j]!=0){
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
                i++;
            }
            j++;
        }
        */
      
      //  using stl an two pointers within a loop
      
        for(int i=0,j=0;i<a.size();++i)
        {
            if(a[i]) swap(a[i],a[j++]);
        }       
   
    }
