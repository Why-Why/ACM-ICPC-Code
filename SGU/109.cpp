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
// Created Time  : 2015年08月12日 星期三 19时50分32秒
// File Name     : 109.cpp

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

int NNN;

inline int zhuan(int x,int y)
{
	return x+(y-1)*NNN;
}

void getans2(int N,int x0,int y0,int zou)
{
	if(N==2)
	{
		printf("%d %d\n",zou,zhuan(x0-1,y0));
		printf("%d %d %d\n",zou-1,zhuan(x0-1,y0-1),zhuan(x0,y0));
		return;
	}

	printf("%d",zou);
	for(int i=2;i<=N/2;++i) printf(" %d",zhuan(x0-N/2-1+2*i,y0-N/2));
	for(int i=2;i<N/2;++i) printf(" %d",zhuan(x0+N/2-1,y0-N/2+2*i-2));
	for(int i=1;i<N/2;++i) printf(" %d",zhuan(x0-N/2+2*i-2,y0+N/2-1));
	for(int i=2;i<N/2;++i) printf(" %d",zhuan(x0-N/2,y0-N/2-1+2*i));
	puts("");

	printf("%d",zou-1);
	for(int i=1;i<=N/2;++i) printf(" %d",zhuan(x0-N/2+2*i-2,y0-N/2));
	for(int i=1;i<=N/2;++i) printf(" %d",zhuan(x0-N/2+1+2*i-2,y0+N/2-1));
	for(int i=1;i<N/2;++i) printf(" %d",zhuan(x0+N/2-1,y0-N/2+1+2*i-2));
	for(int i=2;i<=N/2;++i) printf(" %d",zhuan(x0-N/2,y0-N/2+2*i-2));
	puts("");

	printf("%d",zou-3);
	printf(" %d %d %d %d\n",zhuan(x0-N/2-1+2,y0-N/2),zhuan(x0+N/2-1,y0-N/2+N-2),zhuan(x0-N/2+N-2,y0+N/2-1),zhuan(x0-N/2,y0-N/2-1+2));
	
	getans2(N-2,x0,y0,zou-4);
}

void getans1(int N,int x0,int y0,int zou)
{
	if(N==1)
		return;

	printf("%d",zou);
	for(int i=1;i<=(N+1)/2;++i) printf(" %d %d",zhuan(x0-(N-1)/2+2*i-2,y0-(N-1)/2),zhuan(x0-(N-1)/2+2*i-2,y0+(N-1)/2));
	for(int i=2;i<(N+1)/2;++i) printf(" %d %d",zhuan(x0-(N-1)/2,y0-(N-1)/2+2*i-2),zhuan(x0+(N-1)/2,y0-(N-1)/2+2*i-2));
	puts("");

	printf("%d",zou-2);
	for(int i=1;i<=(N-1)/2;++i) printf(" %d %d %d %d",zhuan(x0-(N-1)/2+1+2*i-2,y0-(N-1)/2),zhuan(x0-(N-1)/2+1+2*i-2,y0+(N-1)/2),zhuan(x0-(N-1)/2,y0-(N-1)/2+1+2*i-2),zhuan(x0+(N-1)/2,y0-(N-1)/2+1+2*i-2));
	puts("");

	getans1(N-2,x0,y0,zou-4);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d",&NNN))
		if(!(NNN&1))
			getans2(NNN,NNN/2+1,NNN/2+1,298);
		else
			getans1(NNN,(NNN+1)/2,(NNN+1)/2,299);
	
	return 0;
}
