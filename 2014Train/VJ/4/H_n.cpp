#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int INF=10e8;

int N,M;
int map1[110][110];

int main()
{
	int a,b;
	int ans;
	bool ok;

	while(cin>>N>>M)
	{
		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				map1[i][j]= i==j ? 0 : INF;

		for(int i=1;i<=M;++i)
		{
			cin>>a>>b;
			map1[a][b]=1;
		}

		for(int k=1;k<=N;++k)
			for(int i=1;i<=N;++i)
				for(int j=1;j<=N;++j)
					map1[i][j]=min(map1[i][j],map1[i][k]+map1[k][j]);

		ans=N;

		for(int i=1;i<=N;++i)
		{
			ok=1;

			for(int j=1;j<=N;++j)
				if(map1[i][j]==INF && map1[j][i]==INF)
				{
					ok=0;
					break;
				}

			if(!ok)
				--ans;
		}

		cout<<ans<<endl;
	}

	return 0;
}
