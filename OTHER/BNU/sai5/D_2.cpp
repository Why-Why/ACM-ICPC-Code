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
// Created Time  : 2015年10月08日 星期四 16时02分37秒
// File Name     : D_2.cpp

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

const int MaxN=101005;

long long cou[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int a,x;
	int N;

	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		memset(cou,0,sizeof(cou));

		while(N--)
		{
			scanf("%d %d",&a,&x);
			cou[a]+=x;
		}

		bool ok=0;
		long long last=0;
		int rem;

		for(int i=MaxN-1;i>=0;--i)
		{
			if(cou[i]>=last)
			{
				cou[i]-=last;
				last=0;
			}
			else last-=cou[i];

			if(last==0 && (cou[i] & 1)) last=1,rem=i;
			last<<=1;

			if(last>(1LL<<60))
			{
				ok=1;
				break;
			}
		}
		if(last) ok=1;

		printf("Case #%d: ",cas++);
		if(ok)
		{
			cou[rem]=1;
			for(int i=0;i<=rem;++i)
			{
				cou[i+1]+=(cou[i]>>1);
				cou[i]=(cou[i] & 1) ? 0 : 1;
			}
			++cou[0];
			for(int i=0;i<=rem;++i)
				if(cou[i]>1) ++cou[i+1],cou[i]-=2;
				else break;
			ok=0;
			for(int i=rem;i>=0;--i)
				if(ok || cou[i]) putchar(cou[i]+'0'),ok=1;
			puts("");
		}
		else puts("0");
	}
	
	return 0;
}
