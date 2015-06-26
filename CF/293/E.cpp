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
// Created Time  : 2015年06月01日 星期一 23时08分54秒
// File Name     : E.cpp

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

const int INF=0x3f3f3f3f;

int n,k;
int num[100005];
bool vis[100005];
char s[100];

inline bool jiejue(int start,int cou,int a,int b)
{
	if(b-a+1<cou)
		return 0;

	int temp;
	int xia,shang;

	if(a>=0)
	{
		temp=a;

		for(int j=0,i=start;j<cou;++j,i+=k)
		{
			vis[i]=0;
			num[i]=temp++;
		}
	}
	else if(b<=0)
	{
		temp=b;

		for(int i=start+k*(cou-1);i>=start;i-=k)
		{
			vis[i]=0;
			num[i]=temp--;
		}
	}
	else
	{
		xia=max(-(cou>>1),a);
		shang=cou+xia-1;
		temp=start;

		while(xia<1)
		{
			vis[temp]=0;
			num[temp]=xia;
			++xia;
			temp+=k;
		}

		temp=start+(cou-1)*k;

		while(shang)
		{
			vis[temp]=0;
			num[temp]=shang;
			--shang;
			temp-=k;
		}
	}

	return 1;
}

inline bool chuli(int x)
{
	int last=-INF;
	int temp,t,cou;

	while(x<=n)
	{
		if(vis[x]==0)
		{
			if(num[x]<=last)
				return 0;
			else
				last=num[x];
		}
		else
		{
			t=x;
			cou=0;

			while(t<=n && vis[t])
			{
				t+=k;
				++cou;
			}

			if(t>n)
				temp=INF;
			else
				temp=num[t];

			if(!jiejue(x,cou,last+1,temp-1))
				return 0;

			x=t-k;
			last=num[x];
		}

		x+=k;
	}

	return 1;
}

bool getans()
{
	for(int i=1;i<=k;++i)
		if(!chuli(i))
			return 0;

	return 1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&n,&k);

	for(int i=1;i<=n;++i)
	{
		scanf("%s",s);
		
		if(s[0]=='?')
			vis[i]=1;
		else
			sscanf(s,"%d",&num[i]);
	}

	if(getans())
	{
		for(int i=1;i<=n;++i)
			printf("%d ",num[i]);
		puts("");
	}
	else
		puts("Incorrect sequence");
	
	return 0;
}
