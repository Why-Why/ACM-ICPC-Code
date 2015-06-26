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
// Created Time  : 2015年05月10日 星期日 16时27分22秒
// File Name     : 1416.cpp

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

int tnum;
char base[10];
int len;
int rem,maxn;

int judge(int x)
{
	int ret=0;
	int cou=0;

	for(int i=0;i<len;++i)
	{
		cou=cou*10+base[i]-'0';

		if((1<<i) & x)
		{
			ret+=cou;
			cou=0;
		}
	}

	ret+=cou;

	if(ret>tnum)
		ret=-2;

	return ret;
}

void chuli(int x)
{
	int cou=0;

	for(int i=0;i<len;++i)
	{
		cou=cou*10+base[i]-'0';

		if((1<<i) & x)
		{
			printf(" %d",cou);
			cou=0;
		}
	}

	printf(" %d\n",cou);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int t;
	char temp;

	while(~scanf("%d %s",&tnum,base) && (tnum || base[0]-'0'))
	{
		rem=-1;
		maxn=-1;
		len=strlen(base);

		for(int i=0;i<(1<<(len-1));++i)
		{
			t=judge(i);

			if(t==maxn)
				rem=-2;
			else if(t>maxn)
			{
				maxn=t;
				rem=i;
			}
		}

		if(rem==-1)
			puts("error");
		else if(rem==-2)
			puts("rejected");
		else
		{
			printf("%d",maxn);
			chuli(rem);
		}
	}
	
	return 0;
}
