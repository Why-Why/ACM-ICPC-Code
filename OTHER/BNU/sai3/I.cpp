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
// Created Time  : 2015年10月04日 星期日 14时31分02秒
// File Name     : I.cpp

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

int H,W;
int h,w;

int get111(int W,int H,int w,int h)
{
	int ans=0;

	int tw=W%w,th=H%h;
	int k,n;
	int t;

	int last=0;

	if(tw)
	{
		k=w/tw;
		n=(H+h-1)/h;
		t=(n+k-1)/k;
		ans+=t;

		last=h*t-H;
	}

	if(th)
	{
		k=h/th;
		n=W/w;
		n-=last/th;
		ans+=(n+k-1)/k;
	}

	if(tw && th) --ans;

	int tans=0;
	last=0;

	if(th)
	{
		k=h/th;
		n=(W+w-1)/w;
		t=(n+k-1)/k;
		tans+=t;

		last=w*t-W;
	}

	if(tw)
	{
		k=w/tw;
		n=H/h;
		n-=last/tw;
		tans+=(n+k-1)/k;
	}

	return min(ans,tans);
}


int getans(int W,int H,int w,int h)
{
	int ans=(W/w)*(H/h);

	int tw=W%w,th=H%h;
	int k,n;
	int t;
	int last=0;

	if(tw)
	{
		k=w/tw;
		n=(H+h-1)/h;
		t=(n+k-1)/k;
		ans+=t;

		if((H/h)%k)
			last=0;
		else
			last=h-th;
	}

	if(th)
	{
		k=h/th;
		n=W/w;
		n-=last/th;
		ans+=(n+k-1)/k;
	}

	return ans;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d %d %d %d",&W,&H,&w,&h))
	{
		int ans=getans(W,H,w,h);
		swap(W,H);
		swap(w,h);
		ans=min(ans,getans(W,H,w,h));
		printf("%d\n",ans);
	}
	
	return 0;
}
