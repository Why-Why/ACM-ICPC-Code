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
// Created Time  : 2015年09月25日 星期五 09时56分55秒
// File Name     : C.cpp

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

const int MaxN=100000;

bool vis[MaxN];
int prime[MaxN],pcou=0;

void init()
{
	for(int i=2;i<MaxN;++i)
		if(!vis[i])
		{
			prime[pcou++]=i;
			for(int j=i+i;j<MaxN;j+=i)
				vis[j]=1;
		}
}

int fen[MaxN],cou[MaxN];
int fcou=0;

void fenjie(long long N)
{
	int tcou;

	for(int i=0;i<pcou;++i)
	{
		if(N%prime[i]==0)
		{
			fen[fcou]=prime[i];
			tcou=0;
			while(N%prime[i]==0)
			{
				N/=prime[i];
				++tcou;
			}
			cou[fcou]=tcou;
			++fcou;
		}
	}

	if(N>1)
	{
		cou[fcou]=1;
		fen[fcou]=N;
		++fcou;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N;

	init();

	scanf("%d",&N);
	fenjie(N);

	long long ans=N;
	for(int i=0;i<fcou;++i)
		for(int j=0;j<cou[i];++j)
		{
			N/=fen[i];
			ans+=N;
		}
	cout<<ans<<endl;
	
	return 0;
}
