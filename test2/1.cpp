#include<bits/stdc++.h>
using namespace std;
int pd[10010];
void work()
{
	int n;
	cin>>n;
	for(int i=0,a;i<n;i++)
	{
		cin>>a;
		pd[a]++;
	}
	int ans=0,js=0;
	for(int i=0;i<n;i++)
	{
		if(pd[i]>js)
		{
			js=pd[i];
			ans=i;
		}
	}
	printf("%d %d\n",ans,js);
}
int main()
{
	int k;
	cin>>k;
	for(int i=0;i<k;i++)
	{
		memset(pd,0,sizeof(int)*10010);
		work();
	}
	
	return 0;
}
