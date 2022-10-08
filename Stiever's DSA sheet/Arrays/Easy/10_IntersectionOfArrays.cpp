vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
  int i = 0, j = 0; 
  vector < int > ans; 
  while (i < n && j < m) {
    if (arr1[i] < arr2[j]) i++;
    else if (arr1[i] > arr2[j]) j++;
    else
    {
      ans.push_back(arr1[i]);
      i++;
      j++;
    }    
    
  }
  
  return ans;
}
