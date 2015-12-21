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
// Created Time  : 2015年10月02日 星期五 19时07分07秒
// File Name     : 1_C.cpp

// Good Problem.

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

const int MaxN=1000006;

int N;

struct Point
{
	int x,y;
	int id;

	bool operator < (const Point &b) const
	{
		if(x==b.x) return y<b.y;
		return x<b.x;
	}
};

Point P[MaxN];

bool cmp(const Point &a,const Point &b)
{
	return a.y<b.y;
}

void show(int L,int R,bool ok)
{
	if(R<L) return;

	sort(P+L,P+R+1,cmp);

	if(ok==0)
		for(int i=L;i<=R;++i)
			printf("%d ",P[i].id);
	else
		for(int i=R;i>=L;--i)
			printf("%d ",P[i].id);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);
	for(int i=1;i<=N;++i)
	{
		scanf("%d %d",&P[i].x,&P[i].y);
		P[i].id=i;
	}
	sort(P+1,P+N+1);

	int t=1000,last=1;
	bool ok=0;
	for(int i=1;i<=N+1;++i)
		if(i==N+1 || P[i].x>t)
		{
			show(last,i-1,ok);
			last=i;
			t+=1000;
			ok=!ok;
		}
	puts("");
	
	return 0;
}
