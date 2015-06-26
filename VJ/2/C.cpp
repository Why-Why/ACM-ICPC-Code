#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>

#define max1(a,b,c) (max(max(a,b),c))
#define min1(a,b,c) (min(min(a,b),c))

using namespace std;

int ans[70][30];
int base[200][30];
int bas[30];
int cou=0;
int sta;

bool vis[30];
int bian[30][3];

void copy()
{
	for(int i=0;i<20;++i)
		base[cou][i]=bas[i];
}

void dfs(int x,int G)
{
	if(G==20)
	{
		if(bian[x][0]==sta||bian[x][1]==sta||bian[x][2]==sta)
		{
			copy();
			++cou;
		}

		return;
	}

	for(int i=0;i<3;++i)
		if(vis[bian[x][i]]==0)
		{
			vis[bian[x][i]]=1;
			bas[G]=bian[x][i];

			dfs(bian[x][i],G+1);

			vis[bian[x][i]]=0;
		}
}

void dis(int x)
{
	cout<<x+1<<":  ";

	for(int i=0;i<20;++i)
		cout<<base[x][i]<<' ';

	cout<<sta;
	cout<<endl;
}

int main()
{
	ios::sync_with_stdio(false);

	int a,b,c;

	for(int i=1;i<=20;++i)
	{
		cin>>a>>b>>c;

		bian[i][0]=min1(a,b,c);
		bian[i][2]=max1(a,b,c);
		bian[i][1]=a+b+c-bian[i][0]-bian[i][2];
	}

	for(cin>>sta;sta;cin>>sta)
	{
		cou=0;
		memset(vis,0,sizeof(vis));

		vis[sta]=1;
		bas[0]=sta;
	
		dfs(sta,1);

		for(int i=0;i<cou;++i)
			dis(i);
	}

	return 0;
}
