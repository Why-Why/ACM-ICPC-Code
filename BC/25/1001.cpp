#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

bool vis[105];
bool rem[105];
int n,m;
int first[105];
int next[10005];
int bs[10005],be[10005];

bool dfs(int x)
{
	int t=first[x];
	
	while(t)
	{
		if(rem[be[t]])				//这里要注意先判断。
			return 0;

		if(vis[be[t]]==0)
		{
			vis[be[t]]=1;
			rem[be[t]]=1;
			
			if(dfs(be[t])==0)
				return 0;
			rem[be[t]]=0;
		}

		t=next[t];				//不然会无限循环。
	}	

	return 1;
}

bool getans()
{
	for(int i=1;i<=n;++i)
		if(vis[i]==0)
		{
			memset(rem,0,sizeof(rem));		//这里要注意清零。
			rem[i]=1;
			vis[i]=1;
			if(dfs(i)==0)
				return 0;
		}

	return 1;
}

int main()
{
	int a,b;
	int temp;

	while(~scanf("%d %d",&n,&m))
	{
		memset(vis,0,sizeof(vis));
		memset(first,0,sizeof(first));
		memset(next,0,sizeof(next));
		
		for(int i=1;i<=m;++i)
		{
			scanf("%d %d",&a,&b);
			bs[i]=b;
			be[i]=a;
			temp=first[b];
			first[b]=i;
			next[i]=temp;
		}

		if(getans())
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}

	return 0;
}
