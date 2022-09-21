#include<iostream>
using namespace std;

/*

   *
  ***
 *****
*******

*/

void pattern(int n)
{
    int i=0,j=0,k=0;
    for(int i=n;i>0;i--){
        // spaces 
        while(j<=n-i-1){
            cout<<" ";
            j++;
        }
        j=0;
        while(k<(i*2-1)){
            cout<<"*";
            k++;
        }
        k=0;
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
