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
// Created Time  : 2015年09月08日 星期二 22时42分01秒
// File Name     : A.cpp

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

const int MaxN=110;

int cou[MaxN]={0};
int N,M;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a;
	int maxn,rem=-1;

	scanf("%d %d",&N,&M);

	for(int i=1;i<=M;++i)
	{
		rem=-1;
		for(int j=1;j<=N;++j)
		{
			scanf("%d",&a);

			if(rem==-1 || maxn<a)
			{
				rem=j;
				maxn=a;
			}
		}

		++cou[rem];
	}

	rem=-1;
	for(int i=1;i<=N;++i)
		if(rem==-1 || maxn<cou[i])
		{
			rem=i;
			maxn=cou[i];
		}

	cout<<rem<<endl;
	
	return 0;
}
