#include<iostream>
using namespace std;
/* 

12345
1234
123
12
1
   
*/
 void pattern(int n)
 {
    for(int i=n;i>0;i--)
    {
        for(int j=1;j<=i;j++){
            cout<<j<<" ";            
        }
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
