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
// Created Time  : 2015年09月13日 星期日 09时09分32秒
// File Name     : 1001.cpp

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

const int MaxN=150005;

int N,M,Q;
char name[MaxN][205];

struct People
{
	int id,v;

	People(int a=0,int b=0)
	{
		id=a;
		v=b;
	}

	bool operator < (const People & b) const
	{
		if(v==b.v)
			return id>b.id;
		return v<b.v;
	}
};

struct Jin
{
	int t,p;

	bool operator < (const Jin &b) const
	{
		return t<b.t;
	}
};

Jin remj[MaxN];
int remv[MaxN];

int ans[MaxN];

priority_queue <People> que;

void getans()
{
	sort(remj+1,remj+M+1);

	int tp;
	int cou=1;
	int zcou=1;
	People temp;

	for(int i=1;i<=N;++i)
	{
		que.push(People(i,remv[i]));
		while(cou<=M && remj[cou].t<=i)
		{
			tp=remj[cou].p;
			while(tp-- && !que.empty())
			{
				temp=que.top();
				que.pop();

				ans[zcou++]=temp.id;
			}
			++cou;
		}
	}

	tp=N;
	while(tp-- && !que.empty())
	{
		temp=que.top();
		que.pop();

		ans[zcou++]=temp.id;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);

	while(T--)
	{
		while(!que.empty())
			que.pop();
		scanf("%d %d %d",&N,&M,&Q);
		for(int i=1;i<=N;++i)
			scanf("%s %d",name[i],&remv[i]);

		for(int i=1;i<=M;++i)
			scanf("%d %d",&remj[i].t,&remj[i].p);

		getans();

		int a;
		while(Q--)
		{
			scanf("%d",&a);
			printf("%s",name[ans[a]]);
			if(Q>=1) printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
