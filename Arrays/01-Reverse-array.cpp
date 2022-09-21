string reverseWord(string str)
{    
  reverse(str.begin(),str.end());
  return str;
}

//    ANOTHER METHOD TO REVERSE A STRING

string reverseWord(string s)
{
  str.size();               // returns the size of the string
  n=str.length();             //         "
  strlen(str.c_str()) ;     //         "
  string s1[n];
  for(int i=n-1,j=0;i>=0 && j<n;i--,j++)
  {
    s1[j]=s[i];
  }
  return s1;  
}
