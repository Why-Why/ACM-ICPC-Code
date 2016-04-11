// ━━━━━━神兽出没━━━━━━
// 　　 ┏┓       ┏┓
// 　　┏┛┻━━━━━━━┛┻┓
// 　　┃           ┃
// 　　┃     ━     ┃
//     ████━████   ┃
// 　　┃           ┃
// 　　┃    ┻      ┃
// 　　┃           ┃
// 　　┗━┓       ┏━┛
// 　　  ┃       ┃
// 　　  ┃       ┃
// 　　　┃       ┗━━━┓
// 　　　┃           ┣┓
// 　　　┃           ┏┛
// 　　　┗┓┓┏━━━━━┳┓┏┛
// 　　　 ┃┫┫     ┃┫┫
// 　　　 ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2015年05月30日 星期六 22时17分35秒
// File Name     : A.cpp

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

char map1[110][110];
int N,M;

const int step[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

inline int change(char c)
{
	if(c=='^')
		return 0;

	if(c=='>')
		return 1;

	if(c=='v')
		return 2;

	return 3;
}

inline int judge(int x,int y)
{
	bool ok=0;

	for(int i=1;i<=N;++i)
		if(x!=i && map1[i][y]!='.')
		{
			ok=1;
			break;
		}

	for(int i=1;i<=M;++i)
		if(y!=i && map1[x][i]!='.')
		{
			ok=1;
			break;
		}

	if(!ok)
		return -1;

	int t=change(map1[x][y]);
	int tx=x+step[t][0],ty=y+step[t][1];
	ok=0;

	while(tx<=N && tx>=1 && ty<=M && ty>=1)
	{
		if(map1[tx][ty]!='.')
			ok=1;
		
		tx+=step[t][0];
		ty+=step[t][1];
	}

	if(!ok)
		return 0;

	return 1;
}

int getans()
{
	int ret=0;
	int t;

	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j)
			if(map1[i][j]!='.')
			{
				t=judge(i,j);

				if(t==-1)
					return -1;
				else if(t==0)
					++ret;
			}

	return ret;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int T,cas=1;
	int ans;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&M);

		for(int i=1;i<=N;++i)
			scanf("%s",map1[i]+1);

		ans=getans();

		if(ans!=-1)
			printf("Case #%d: %d\n",cas++,ans);
		else
			printf("Case #%d: IMPOSSIBLE\n",cas++);
	}
	
	return 0;
}
