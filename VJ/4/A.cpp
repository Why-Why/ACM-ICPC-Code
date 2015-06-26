#include<iostream>
#include<cstring>

using namespace std;

const int INF=10e7;

int map1[1005][1005];
int ans[1005];
int N,T;
bool vis[1005];

int main()
{
	ios::sync_with_stdio(false);

	int a,b,c;

	while(cin>>T>>N)
	{
	memset(map1,0,sizeof(map1));

	for(int i=1;i<=N;++i)
	{
		ans[i]=INF;
		vis[i]=0;
	}
	ans[N]=0;

	for(int i=1;i<=T;++i)
	{
		cin>>a>>b>>c;

		if(map1[a][b]==0 || c<map1[a][b])
			map1[a][b]=map1[b][a]=c;
	}

	for(int i=1;i<=N;++i)
	{
		int minn=INF;
		int minnp=-1;

		for(int j=1;j<=N;++j)
			if(vis[j]==0 && ans[j]<minn)
			{
				minn=ans[j];
				minnp=j;
			}

		if(minnp==-1)
			break;

		vis[minnp]=1;

		for(int j=1;j<=N;++j)
			if(map1[minnp][j] && vis[j]==0 && ans[minnp]+map1[minnp][j]<ans[j])
				ans[j]=ans[minnp]+map1[minnp][j];
	}

	cout<<ans[1]<<endl;
	}

	return 0;
}
