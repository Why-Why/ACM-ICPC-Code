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
// Created Time  : 2015年10月01日 星期四 10时27分10秒
// File Name     : J.cpp

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

const int MaxN=10004;

int N;

struct Point
{
	int id;
	int x,y;
};

bool cmpx(const Point &a,const Point &b)
{
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}

bool cmpy(const Point &a,const Point &b)
{
	if(a.y==b.y) return a.x<b.x;
	return a.y<b.y;
}

bool cmpx1(const Point &a,const Point &b)
{
	return a.x<b.x;
}

bool cmpy1(const Point &a,const Point &b)
{
	return a.y<b.y;
}


Point P[MaxN];
Point PX[MaxN];
Point PY[MaxN];
bool vis[MaxN];

void zhuan(int &x,int &y,int fang,int id)
{
	x=P[id].x;
	y=P[id].y;

	if(fang==0) --x;
	if(fang==1) ++y;
	if(fang==2) ++x;
	if(fang==3) --y;
}

int find1(int fang,int x,int y)
{
	if(fang==0 || fang==2)
	{
		Point p;
		p.x=x; p.y=y;
		int L=lower_bound(PY+1,PY+N+1,p,cmpy1)-PY;
		if(PY[L].y!=p.y) return -1;
		++p.y;
		int R=lower_bound(PY+1,PY+N+1,p,cmpy1)-PY-1;
		--p.y;
		int t;

		if(fang==0)
		{
			if(PY[R].x<=x) return -1;
			t=upper_bound(PY+L,PY+R+1,p,cmpx1)-PY;
			return PY[t].id;
		}
		else
		{
			if(PY[L].x>=x) return -1;
			t=lower_bound(PY+L,PY+R+1,p,cmpx1)-PY-1;
			return PY[t].id;
		}
	}
	else
	{
		Point p;
		p.x=x; p.y=y;
		int L=lower_bound(PX+1,PX+N+1,p,cmpx1)-PX;
		if(PX[L].x!=p.x) return -1;
		++p.x;
		int R=lower_bound(PX+1,PX+N+1,p,cmpx1)-PX-1;
		--p.x;
		int t;

		if(fang==3)
		{
			if(PX[R].y<=y) return -1;
			t=upper_bound(PX+L,PX+R+1,p,cmpy1)-PX;
			return PX[t].id;
		}
		else
		{
			if(PX[L].y>=y) return -1;
			t=lower_bound(PX+L,PX+R+1,p,cmpy1)-PX-1;
			return PX[t].id;
		}
	}
}

int getans()
{
	int ret=0;
	int fang=0;
	int px=0,py=0;
	int t;

	while((t=find1(fang,px,py))!=-1)
	{
		if(t==-1) break;
		if(vis[P[t].id*10+fang]) return -1;
		vis[P[t].id*10+fang]=1;
		zhuan(px,py,fang,t);
		(fang+=1)%=4;
		++ret;
	}

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d",&N))
	{
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=N;++i)
		{
			scanf("%d %d",&P[i].x,&P[i].y);
			P[i].id=i;
			PX[i]=PY[i]=P[i];
		}

		sort(PX+1,PX+N+1,cmpx);
		sort(PY+1,PY+N+1,cmpy);

		printf("%d\n",getans());
	}
	
	return 0;
}
