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
// Created Time  : 2015年08月18日 星期二 17时04分13秒
// File Name     : 1007_1.cpp

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

const int MaxN=110;

int N,M;
int map1[MaxN][MaxN];
int sum[MaxN][MaxN];
int sumh[MaxN];

int rhang,rlie;
int ans;

int getcuo(int hang,bool zuo,int &lie)
{
	int minn=0x3f3f3f3f;
	int ttt=1;

	if(M&1) return sumh[hang+1]-sumh[hang-1];

	if(zuo)
	{
		for(int i=1;i<=M;++i)
			if(minn>map1[hang+(i%2)][i])
			{
				minn=map1[hang+(i%2)][i];
				lie=i;
			}
	}
	else
	{
		for(int i=M;i>=1;--i)
			if(minn>map1[hang+(M-i+1)%2][i])
			{
				minn=map1[hang+(M-i+1)%2][i];
				lie=i;
			}
	}

	return sumh[hang+1]-sumh[hang-1]-minn;
}

void show0(int s,int x,bool you)
{
	for(int i=s;i<=x;++i)
	{
		for(int j=1;j<M;++j)
			printf("%c",you ? 'L' : 'R');
		if(i!=N)
			printf("%c",'D');
		you=!you;
	}
}

void show(int rhang,int rlie,bool zuo)
{
	if(M&1)
	{
		bool ttt=1;
		printf("D");
		for(int i=1;i<M;++i,ttt=!ttt)
			printf("%c%c",zuo ? 'R' : 'L',ttt ? 'U' : 'D');
		if(rhang+1!=N)
			printf("D");
		return;
	}

	if(zuo)
	{
		bool ttt;
		if(rlie==1) ttt=0;
		else ttt=1,printf("D");
		for(int i=2;i<=M;++i)
			if(i!=rlie)
			{
				printf("R%c",ttt ? 'U' : 'D');
				ttt=!ttt;
			}
			else printf("R");
	}
	else
	{
		bool ttt;
		if(rlie==1) ttt=0;
		else ttt=1,printf("D");
		for(int i=2;i<=M;++i)
			if(i!=rlie)
			{
				printf("L%c",ttt ? 'U' : 'D');
				ttt=!ttt;
			}
			else printf("L");
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d %d",&N,&M))
	{
		for(int i=1;i<=N;++i)
			for(int j=1;j<=M;++j)
			{
				scanf("%d",&map1[i][j]);
				sum[i][j]=sum[i][j-1]+map1[i][j];
			}

		for(int i=1;i<=N;++i)
			sumh[i]=sumh[i-1]+sum[i][M];

		if(N&1)
		{
			printf("%d\n",sumh[N]);
			show0(1,N,0);
			puts("");
			continue;
		}

		ans=-1;
		int t,tl;

		for(int i=1;i<N;++i)
		{
			t=sumh[i-1]+sumh[N]-sumh[i+1];
			t+=getcuo(i,i&1,tl);

			if(t>ans)
			{
				ans=t;
				rhang=i;
				rlie=tl;
			}
		}

		printf("%d\n",ans);
		show0(1,rhang-1,0);
		show(rhang,rlie,rhang%2);
		show0(rhang+2,N,rhang%2);
		puts("");
	}
	
	return 0;
}
