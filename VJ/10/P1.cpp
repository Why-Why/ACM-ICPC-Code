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

// Kuhn-Munkres算法(邻接矩阵)求二分图最大权匹配，复杂度 O(N^3)。
// 输入：边集line(直接读入)，N。
// 输出：最大匹配值，linker数组。
// 注意：最大权匹配是在完美匹配的前提下。line要记得清空。
// 原理：点进行距离标号，不断寻找增广路，调整标号，知道完美匹配。

const int MaxN=310;
const int INF=10e8;

int line[MaxN][MaxN];
int linker[MaxN],lx[MaxN],ly[MaxN];
int slack[MaxN];
bool visx[MaxN],visy[MaxN];

bool find(int x,int N)
{
	int temp;

	visx[x]=1;

	for(int y=1;y<=N;++y)
	{
		if(visy[y])
			continue;

		temp=lx[x]+ly[y]-line[x][y];

		if(temp==0)
		{
			visy[y]=1;

			if(linker[y]==0 || find(linker[y],N))
			{
				linker[y]=x;
				return 1;
			}
		}
		else if(slack[y]>temp)
			slack[y]=temp;
	}

	return 0;
}

int KM(int N)
{
	int d,ret=0;

	for(int i=1;i<=N;++i)
	{
		linker[i]=-1;
		ly[i]=0;
		lx[i]=-INF;

		for(int j=1;j<=N;++j)
			if(line[i][j]>lx[i])
				lx[i]=line[i][j];
	}

	for(int x=1;x<=N;++x)
	{
		for(int i=1;i<=N;++i)
			slack[i]=INF;

		while(1)
		{
			memset(visx,0,sizeof(visx));
			memset(visy,0,sizeof(visy));

			if(find(x,N))
				break;

			d=INF;

			for(int i=1;i<=N;++i)
				if(!visy[i] && d>slack[i])
					d=slack[i];

			for(int i=1;i<=N;++i)
			{
				if(visx[i])
					lx[i]-=d;
			
				if(visy[i])
					ly[i]+=d;
				else
					slack[i]-=d;
			}
		}
	}

	for(int i=1;i<=N;++i)
		if(linker[i]!=-1)
			ret+=line[linker[i]][i];

	return ret;
}

int N;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d",&N))
	{
		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				scanf("%d",&line[i][j]);

		printf("%d\n",KM(N));
	}
	
	return 0;
}
