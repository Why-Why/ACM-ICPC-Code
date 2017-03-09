#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

int N,M;
bool map1[110][110];
bool vis[110];

int bfs(int x)
{
	bool rem[110]={0};
	queue <int> que1,que2;
	int cou;
	int temp1,temp2;

	rem[x]=1;
	que1.push(x);
	que2.push(x);

	while(!que1.empty())
	{
		temp1=que1.front();
		que1.pop();

		for(int i=1;i<=N;++i)
			if(rem[i]==0 && map1[temp1][i])
			{
				rem[i]=1;
				que1.push(i);
			}
	}

	while(!que2.empty())
	{
		temp2=que2.front();
		que2.pop();

		for(int i=1;i<=N;++i)
			if(rem[i]==0 && map1[i][temp2])
			{
				rem[i]=1;
				que2.push(i);
			}
	}

	cou=N;

	for(int i=1;i<=N;++i)
		if(rem[i])
			--cou;
		else
			vis[i]=1;

	if(cou==0)
		return 0;

	vis[x]=1;
	return cou+1;
}

int main()
{
	int ans;
	int a,b;

	while(cin>>N>>M)
	{
		memset(map1,0,sizeof(map1));

		for(int i=1;i<=M;++i)
		{
			scanf("%d %d",&a,&b);
			map1[a][b]=1;
		}

		memset(vis,0,sizeof(vis));
		ans=N;

		for(int i=1;i<=N;++i)
			if(vis[i]==0)
			{
				ans-=bfs(i);
			}

		cout<<ans<<endl;
	}

	return 0;
}
