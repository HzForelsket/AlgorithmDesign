#include<bits/stdc++.h>
using namespace std;
int dfs(int k);
int main()
{
	int n;
	cin>>n;
	cout<<dfs(n);
	return 0;	
}
int dfs(int k)
{
	int t=1;
	for(int i=k/2;i!=0;i--)
	{
		t+=dfs(i);
	}
	return t;
}
