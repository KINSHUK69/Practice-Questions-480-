int cout(int n)
{
  int c=0;
  while(n){
    n&=(n-1);
    c++;
  }
  return c;
}
