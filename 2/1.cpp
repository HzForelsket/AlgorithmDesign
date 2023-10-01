#include<bits/stdc++.h>
using namespace std;
int pd[100010];
int n;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>pd[i];
    }
    int maxx=0,maxxn=0;
    for(int i=0;i<n;i++)
    {
        if(pd[i]>maxx)
        {
            maxx=pd[i];
            maxxn=i;
        }
    }
    cout<<maxxn<<" "<<maxx;
    return 0;
}