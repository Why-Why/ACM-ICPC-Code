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
// Created Time  : 2015年10月01日 星期四 11时09分57秒
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

const int INF = 10e8;
const int MaxM = 200000;
const int MaxN = 505;
const int MaxNode = MaxM<<1;

struct DLX
{
	int U[MaxNode], D[MaxNode], L[MaxNode], R[MaxNode], col[MaxNode], row[MaxNode];
	int H[MaxN], S[MaxM];
	int size, n, m;
	int ansnum;

	void init(int _n, int _m)
	{
		n = _n; m = _m; size = m; ansnum = INF;

		for (int i = 0; i <= m; ++i)
		{
			L[i] = i - 1; R[i] = i + 1; U[i] = D[i] = i;
			S[i] = 0;
		}
		L[0] = m; R[m] = 0;

		for (int i = 1; i <= n; ++i) H[i] = -1;
	}
	void Link(int r, int c)
	{
		col[++size] = c; ++S[c]; row[size] = r;
		U[size] = U[c]; D[size] = c; D[U[c]] = size; U[c] = size;

		if (H[r] == -1) H[r] = L[size] = R[size] = size;
		else { L[size] = L[H[r]]; R[size] = H[r]; R[L[H[r]]] = size; L[H[r]] = size; }
	}
	void remove(int c)
	{
		for (int i = D[c]; i != c; i = D[i]) { L[R[i]] = L[i]; R[L[i]] = R[i]; }
	}
	void resume(int c)
	{
		for (int i = U[c]; i != c; i = U[i]) L[R[i]] = R[L[i]] = i;
	}
	bool vis[MaxM];
	int getH()
	{
		int ret = 0;

		for (int c = R[0]; c; c = R[c]) vis[c] = 1;
		for (int c = R[0]; c; c = R[c])
			if (vis[c])
			{
				++ret;
				vis[c] = 0;
				for (int i = D[c]; i != c; i = D[i])
					for (int j = R[i]; j != i; j = R[j])
						vis[col[j]] = 0;
			}
		return ret;
	}
	void Dance(int d)
	{
		if (d + getH() >= ansnum) return;
		if (R[0] == 0)
		{
			if (d<ansnum) ansnum = d;
			return;
		}

		int c = R[0];

		for (int i = R[0]; i; i = R[i]) if (S[i]<S[c]) c = i;
		for (int i = D[c]; i != c; i = D[i])
		{
			remove(i);
			for (int j = R[i]; j != i; j = R[j]) remove(j);
			Dance(d + 1);
			for (int j = L[i]; j != i; j = L[j]) resume(j);
			resume(i);
		}
	}
}dlx;

int N,M;
int map1[MaxN][MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;
	int cou=0;

	while(~scanf("%d %d",&N,&M))
	{
		memset(map1,0,sizeof(map1));
		cou=0;
		while(M--)
		{
			scanf("%d %d",&a,&b);
			if(map1[a][b]==0)
				map1[a][b]=map1[b][a]=++cou;
		}
		dlx.init(N,cou);
		for(int i=1;i<=N;++i)
			for(int j=i+1;j<=N;++j)
				if(map1[i][j])
				{
					dlx.Link(i,map1[i][j]);
					dlx.Link(j,map1[i][j]);
				}
		dlx.Dance(0);
		printf("%d\n",dlx.ansnum);
	}
	
	return 0;
}
