#include<iostream>
#include<cstring>
#include<cmath>

#define min(a,b) (a<b ? a:b)

using namespace std;

const int INF=10e8;

int N;
int map1[1010][1010];
int ans[1010];
bool vis[1010];

void Dijkstra()
{
	int k;
	int maxn;

	for(int i=1;i<=N;++i)
	{
		vis[i]=0;
		ans[i]=0;
	}
	ans[1]=INF;

	for(int i=1;i<=N;++i)
	{
		k=-1;
		maxn=0;

		for(int j=1;j<=N;++j)
			if(!vis[j] && ans[j]>maxn)
			{
				maxn=ans[j];
				k=j;
			}

		if(k==-1)
			break;

		vis[k]=1;

		for(int j=1;j<=N;++j)
			if(!vis[j] && min(map1[j][k],ans[k])>ans[j])
				ans[j]=min(map1[j][k],ans[k]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cout.setf(ios::fixed);
	cout.precision(3);

	int T;
	int M;
	int a,b,c;

	cin>>T;

	for(int cas=1;cas<=T;++cas)
	{
		cin>>N>>M;

		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				map1[i][j]=0;

		for(int i=1;i<=M;++i)
		{
			cin>>a>>b>>c;
			map1[a][b]=map1[b][a]=c;
		}

		Dijkstra();

		cout<<"Scenario #"<<cas<<':'<<endl;
		cout<<ans[N]<<endl<<endl;
	}

	return 0;
}
