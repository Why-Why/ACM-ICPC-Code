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
// Created Time  : 2015年11月01日 星期日 16时22分01秒
// File Name     : A_1.cpp

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

const long long v[15]={0,1,5,10,20,50,100,200,500,1000,2000};

int p;
int c[15];
long long tsum[15];
int ans;

bool dfs(int dis,int use,int d)
{
	if(!dis)
	{
		ans=use;
		return 1;
	}
	if(d<1) return 0;
	if(tsum[d]<dis) return 0;
	int len=min(dis/v[d],(long long)c[d]);

	for(int i=0;i<=len;++i)
		if(dfs(dis-i*v[d],use+i,d-1)) return 1;
	return 0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&p);
		long long temp=0;
		for(int i=1;i<=10;++i)
		{
			scanf("%d",c+i);
			temp+=c[i]*v[i];
			tsum[i]=temp;
		}

		ans=-1;
		dfs(p,0,10);
		printf("%d\n",ans);
	}
	
	return 0;
}
