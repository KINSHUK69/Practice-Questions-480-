#include<iostream>
using namespace std;
/* 

1
22
333
4444
   
*/

void pattern(int n){
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        cout<<i<<" ";

        cout<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    pattern(n);
    return 0;
}
