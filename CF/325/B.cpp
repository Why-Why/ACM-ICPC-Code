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
// Created Time  : 2015年10月12日 星期一 17时32分08秒
// File Name     : B.cpp

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

int n;
int a1[100],a2[100];
int ta[2][100];
int b[100];

int getmin(int t,int x,int y)
{
	if(x==0) x=1;
	if(y>=n) y=n-1;

	int ret=0x3f3f3f3f;

	for(int i=x;i<=y;++i)
		ret=min(ret,ta[t-1][i]);
	return ret;
}

int getans(int x,int y)
{
	if(x==y)
		return 0x3f3f3f3f;
	else
		return b[x]+b[y]+a1[x-1]+a2[n-1]-a2[x-1]+a1[y-1]+a2[n-1]-a2[y-1];
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&n);

	a1[0]=a2[0]=0;
	for(int i=1;i<n;++i)
	{
		scanf("%d",a1+i);
		ta[0][i]=a1[i];
		a1[i]+=a1[i-1];
	}
	for(int i=1;i<n;++i)
	{
		scanf("%d",a2+i);
		ta[1][i]=a2[i];
		a2[i]+=a2[i-1];
	}

	for(int i=1;i<=n;++i)
		scanf("%d",b+i);

	int ans=0x3f3f3f3f;

	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			ans=min(ans,getans(i,j));

	printf("%d\n",ans);
	
	return 0;
}
