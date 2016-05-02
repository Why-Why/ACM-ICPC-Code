// ━━━━━━神兽出没━━━━━━
//      ┏┓       ┏┓
//     ┏┛┻━━━━━━━┛┻┓
//     ┃           ┃
//     ┃     ━     ┃
//     ████━████   ┃
//     ┃           ┃
//     ┃    ┻      ┃
//     ┃           ┃
//     ┗━┓       ┏━┛
//       ┃       ┃
//       ┃       ┃
//       ┃       ┗━━━┓
//       ┃           ┣┓
//       ┃           ┏┛
//       ┗┓┓┏━━━━━┳┓┏┛
//        ┃┫┫     ┃┫┫
//        ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2016年05月02日 星期一 14时40分58秒
// File Name     : D.cpp

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

const int MaxN=105;

// 匈牙利算法求二分匹配(临接矩阵)，复杂度 O(VE)。
// 输入：边集line，uN，vN。
// 输出：linker(每个v匹配的u，-1为无。)，最大匹配数。
// 注意：需要先初始化为二分图，先使用init初始化，然后使用addEdge加边，可以修改vis提高效率。

const int MaxU=110;
const int MaxV=110;

bool vis[MaxV];
int linker[MaxV];
int uN,vN;
int line[MaxU][MaxV];

bool find(int u)
{
	for(int v=1;v<=vN;++v)
		if(line[u][v] && !vis[v])
		{
			vis[v]=1;

			if(linker[v]==-1 || find(linker[v]))
			{
				linker[v]=u;
				
				return 1;
			}
		}

	return 0;
}

int Hungary()
{
	int ret=0;

	for(int u=1;u<=uN;++u)
	{
		memset(vis,0,sizeof(vis));

		if(find(u))
			++ret;
	}

	return ret;
}

void addEdge(int u,int v)
{
	line[u][v]=1;
}

void init(int _uN,int _vN)
{
	uN=_uN;
	vN=_vN;

	for(int i=1;i<=vN;++i)
	{
		linker[i]=-1;

		for(int j=1;j<=uN;++j)
			line[j][i]=0;
	}
}

int N;
int a[MaxN],b[MaxN],c[MaxN],d[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		for(int i=1;i<=N;++i) scanf("%d %d",a+i,b+i);
		for(int i=1;i<=N;++i) scanf("%d %d",c+i,d+i);
		init(N,N);
		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
					if(a[i]>d[j] && b[i]>=c[j]) line[i][j]=1;
		if(Hungary()>=N) puts("Yes");
		else puts("No");
	}
	
	return 0;
}
