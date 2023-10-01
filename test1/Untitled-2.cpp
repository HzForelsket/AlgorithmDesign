#include <bits/stdc++.h>
using namespace std;
bool pd[1000000010];
int main()
{
    // freopen("out2.txt", "w", stdout);
    int js=0;
    for (long long int i = 2; i <= 100000; i++)
    {
        if(!pd[i])
        {
            js++;
            // printf("%d,",i);
            long long int k=i*i;
            while(k<=100000 )
            {
                pd[k]=true;
                k+=i;
            }
        }
    }
    cout<<js;
    return 0;
}
