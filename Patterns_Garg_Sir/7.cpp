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
    for(int i=1;i<=n;i++){
        // spaces 
        while(j<=n-i-1){
            cout<<" ";
            j++;
        }
        j=0;
        // stars
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
