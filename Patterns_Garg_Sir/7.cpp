#include<iostream>
using namespace std;

void pattern(int n)
{
    for(int i=n-1;i>0;i--)
    {
        cout<<" ";
        for(int j=0;j<(n-i);j++){
            cout<<"* ";
        }
        for(int k=0;k<n;k++)
        cout<<"* ";

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
