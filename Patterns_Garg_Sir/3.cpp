#include<iostream>
using namespace std;
/* 

1
12
123
1234
   
*/
void pattern(int n){
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        cout<<j<<" ";

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
