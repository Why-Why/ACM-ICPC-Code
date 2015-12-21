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
// Created Time  : 2015年09月10日 星期四 19时52分29秒
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

const int MaxN=1010;

int N,S;
struct Node
{
	int p,q;
	bool operator < (const Node & b) const
	{
		return p>b.p;
	}
};

Node rem1[MaxN],rem2[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	char s[10];
	int p,q;
	int cou1=0,cou2=0;

	scanf("%d %d",&N,&S);

	for(int i=1;i<=N;++i)
	{
		scanf("%s %d %d",s,&p,&q);
		if(s[0]=='S')
		{
			rem1[cou1].p=p;
			rem1[cou1++].q=q;
		}
		else
		{
			rem2[cou2].p=p;
			rem2[cou2++].q=q;
		}
	}

	sort(rem1,rem1+cou1);
	sort(rem2,rem2+cou2);

	reverse(rem1,rem1+cou1);

	int k=1;
	for(int i=1;i<cou1;++i)
		if(rem1[i].p==rem1[i-1].p)
			rem1[k-1].q+=rem1[i].q;
		else
			rem1[k++]=rem1[i];
	if(cou1) cou1=k;

	k=1;
	for(int i=1;i<cou2;++i)
		if(rem2[i].p==rem2[i-1].p)
			rem2[k-1].q+=rem2[i].q;
		else
			rem2[k++]=rem2[i];
	if(cou2) cou2=k;

	for(int i=min(S,cou1)-1;i>=0;--i)
		printf("S %d %d\n",rem1[i].p,rem1[i].q);
	for(int i=0;i<S && i<cou2;++i)
		printf("B %d %d\n",rem2[i].p,rem2[i].q);

	return 0;
}
