#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
	
using namespace std;

const int INF=10e8;

int dp[40000][20];
int dead[20],cost[20];
int N;
map <int,string> mapstate;
int rem1[40000][20],rem2[40000][20];

int getcou(int state,int x)
{
	int ret=0;

	for(int i=1;i<=N;++i)
		if(state & (1<<(i-1)))
			ret+=cost[i];

	ret-=dead[x];

	return ret<0 ? 0 : ret;
}

void showans(int remi,int remj)
{
	int cou=0;
	int anscou[20];
	int temp;

	while(remj!=0)
	{
		anscou[cou++]=remj;

		temp=remi;
		remi=rem1[remi][remj];
		remj=rem2[temp][remj];
	}

	map <int,string>::iterator it;

	for(int i=cou-1;i>=0;--i)
	{
		it=mapstate.find(anscou[i]);

		cout<<it->second<<endl;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	char s[110];
	int minn;
	int remi,remj;

	scanf("%d",&T);

	while(T--)
	{
		mapstate.clear();
		scanf("%d",&N);

		for(int i=1;i<=N;++i)
		{
			scanf("%s %d %d",s,&dead[i],&cost[i]);

			mapstate.insert(pair<int,string> (i,s));
		}

		memset(dp[0],0,sizeof(dp[0]));

		for(int i=1;i<(1<<N);++i)
			for(int j=N;j>=1;--j)
				if((1<<(j-1)) & i)
				{
					minn=INF;
					rem1[i][j]=rem2[i][j]=0;

					for(int k=N;k>=1;--k)
						if(((i^(1<<(j-1))) & (1<<(k-1))) && minn>dp[i^(1<<(j-1))][k])
						{
							minn=dp[i^(1<<(j-1))][k];

							rem1[i][j]=i^(1<<(j-1));
							rem2[i][j]=k;
						}

					if(minn==INF)
						minn=0;

					dp[i][j]=minn+getcou(i,j);
				}

		minn=INF;

		for(int k=N;k>=1;--k)
			if(minn>dp[(1<<N)-1][k])
			{
				minn=dp[(1<<N)-1][k];
				remj=k;
				remi=(1<<N)-1;
			}

		printf("%d\n",minn);
		showans(remi,remj);
	}
	
	return 0;
}
