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
// Created Time  : 2015年10月05日 星期一 10时13分40秒
// File Name     : H.cpp

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

char rem[20][5];
int N;

long long _pow(long long base,int N)
{
	long long ret=1;

	while(N)
	{
		if(N&1) ret*=base;
		base*=base;
		N>>=1;
	}
	return ret;
}

int judge()
{
	int wei[5];
	char d='A';

	for(int i=0;i<3;++i)
		for(int j=0;j<6;++j)
		{
			if(rem[j][0]==d)
			{
				wei[i]=rem[j][1];
				d=wei[i];
				break;
			}
		}

	if(wei[0]!=wei[2]) return 3;
	if(wei[1]=='A') return 1;
	return 2;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out1.txt","w",stdout);

	while(~scanf("%d",&N))
	{
		int t;

		for(int i=0;i<6;++i)
			scanf("%s",rem[i]);
		t=judge();

		if(t==1) printf("%lld\n",2*_pow(3,N-1)-1);
		else if(t==3) printf("%lld\n",_pow(2,N)-1);
		else
		{
			if(N==2) puts("3");
			else if(N==3) puts("9");
			else printf("%lld\n",_pow(3,N-1));
		}
	}
	
	return 0;
}
