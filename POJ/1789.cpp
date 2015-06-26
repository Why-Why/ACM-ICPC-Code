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

const int MaxN=2010;
const int INF=0x3f3f3f3f;

int N;
char s[MaxN][10];

bool vis[MaxN];
int lowc[MaxN];

inline int getcost(int a,int b)
{
	int ret=0;

	for(int i=0;i<7;++i)
		if(s[a][i]!=s[b][i])
			++ret;

	return ret;
}

int Prim(int N)
{
	int ans=0;
	int minn,k;

	memset(vis,0,sizeof(vis));
	vis[1]=1;

	for(int i=1;i<=N;++i)
		lowc[i]=getcost(1,i);

	for(int i=1;i<N;++i)
	{
		minn=INF;
		k=-1;

		for(int j=1;j<=N;++j)
			if(!vis[j] && minn>lowc[j])
			{
				minn=lowc[j];
				k=j;
			}

		ans+=minn;
		vis[k]=1;

		for(int j=1;j<=N;++j)
			if(!vis[j] && lowc[j]>getcost(k,j))
				lowc[j]=getcost(k,j);
	}

	return ans;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d",&N) &&N)
	{
		for(int i=1;i<=N;++i)
			scanf("%s",s[i]);

		printf("The highest possible quality is 1/%d.\n",Prim(N));
	}
	
	return 0;
}
