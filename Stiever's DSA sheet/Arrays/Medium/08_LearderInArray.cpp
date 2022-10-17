/*
Input: arr = [4, 7, 1, 0]
Output: 7 1 0
Explanation:
 Rightmost element is always a leader. 7 and 1 are greater than the elements in their right side.
*/

vector<int>solve(vector<int>a)   // T.C. = O(N) 
{
  
  int n=a.size();
  int m=a[n-1];
  vector<int>ans;
  ans.push_back(m);
  for(int i=n-2;i>=0;i--)
  {
    m=max(m,a[i]);
    
    if(m==a[i]) ans.push_back(a[i]);
    
  }
  reverse(ans.begin(),ans.end());
  return ans;
}
