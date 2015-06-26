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

const int MaxN=310;
const int INF=10e8;

int zuo[MaxN],you[MaxN];
int map1[MaxN][MaxN];
int N;
bool visx[MaxN],visy[MaxN];
int linker[MaxN];
int slack[MaxN];

bool find(int x)
{
	int temp;

	visx[x]=1;

	for(int y=1;y<=N;++y)
	{
		if(visy[y])
			continue;

		temp=zuo[x]+you[y]-map1[x][y];

		if(temp==0):
		{
			visy[y]=1;

			if(linker[y]==0 || find(linker[y]))
			{
				linker[y]=x;
				return 1;
			}
		}
		else
		{
			if(slack[y]>temp)
				slack[y]=temp;
		}
	}

	return 0;
}

int KM()
{
	int minn;
	int ret=0;

	for(int i=1;i<=N;++i)
	{
		zuo[i]=-INF;
		you[i]=0;
		linker[i]=0;

		for(int j=1;j<=N;++j)
			if(map1[i][j]>zuo[i])
				zuo[i]=map1[i][j];
	}

	for(int i=1;i<=N;++i)
	{
		for(int j=1;j<=N;++j)
			slack[j]=INF;

		while(1)
		{
			memset(visx,0,sizeof(visx));
			memset(visy,0,sizeof(visy));

			if(find(i))
				break;

			minn=INF;

			for(int j=1;j<=N;++j)
				if(!visy[j] && minn>slack[j])
					minn=slack[j];

			for(int j=1;j<=N;++j)
			{
				if(visx[j])
					zuo[j]-=minn;
				
				if(visy[j])
					you[j]+=minn;
				else
					slack[j]-=minn;
			}
		}
	}

	for(int i=1;i<=N;++i)
		ret+=zuo[i]+you[i];

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d",&N))
	{
		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				scanf("%d",&map1[i][j]);

		printf("%d\n",KM());
	}
	
	return 0;
}
