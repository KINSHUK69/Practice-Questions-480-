#include<iostream>
using namespace std;

/* 
  

    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
   
*/
void pattern1(int n) // triangle
{
    int i=0,j=0,k=0;
    for(int i=1;i<=n;i++){
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

void pattern2(int n) // upside down triangle
{
    int i=0,j=0,k=0;
    for(int i=n;i>0;i--){
        // spaces 
        while(j<=n-i){
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
    pattern1(n);
    pattern2(n-1);
    return 0;
}
