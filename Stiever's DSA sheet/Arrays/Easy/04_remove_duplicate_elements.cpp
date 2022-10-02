/*
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/

int remove_duplicate(int a[],int n)   // T.C.= O(nlogn)+O(n)  S.C. = O(n)
   {
        set<int>s(a,a+n);
        int k= s.size();
        int i=0;
        for(auto it:s){
            a[i++]=it;
        }
        return i;
    }

 int removeDuplicates(vector<int>& a)   // T.C.= O(n)  S.C. = O(1)     Two pointer approach
 {
        int i=0,j=0;
        for(j=1;j<a.size();j++)
        {
            if(a[i]!=a[j]) {
                a[++i]=a[j];
            }            
        }
        return (i+1);
    }
