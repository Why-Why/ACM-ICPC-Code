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
// Created Time  : 2015年10月07日 星期三 19时01分16秒
// File Name     : D.cpp

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

const int MaxN=100100;

long long cou[MaxN];
long long rem[MaxN];
int num[MaxN];
int ans[MaxN];
bool ok;
int N;

void chuli1(int x)
{
	cou[x+1]+=(cou[x]>>1);
	if((cou[x] & 1)) cou[x]=1;
	else cou[x]=0;
}

void chuli2(int x)
{
	if(rem[x]<=2) return;
	rem[x+1]+=(rem[x]>>1);
	if(rem[x] & 1) rem[x]=1;
	else rem[x]=2,--rem[x+1];
}

void jian()
{
	int jie=0;

	for(int i=0;i<MaxN;++i)
		if(num[i]>=jie+ans[i])
		{
			num[i]-=jie+ans[i];
			jie=0;
		}
		else
		{
			num[i]=num[i]+2-jie-ans[i];
			jie=1;
		}
}

void show()
{
	bool ok=0;

	for(int i=MaxN-1;i>=0;--i)
		if(num[i]) putchar('1'),ok=1;
		else if(ok) putchar('0');
	printf("%lld\n",cou[0]);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int a,x;

	scanf("%d",&T);
	while(T--)
	{
		memset(cou,0,sizeof(cou));
		memset(rem,0,sizeof(rem));

		scanf("%d",&N);
		while(N--)
		{
			scanf("%d %d",&a,&x);
			cou[a]+=x;
			rem[a]+=x;
		}
		for(int i=0;i<MaxN-1;++i)
		{
			chuli1(i);
			chuli2(i);
			if(i) num[i-1]=cou[i];
		}
		ok=0;
		bool tok=0;
		bool in=0;
		for(int i=MaxN-1;i>=0;--i)
		{
			if(!in && cou[i])
			{
				in=1;
				tok=0;
			}

			if(ok) ans[i]=cou[i];
			else
			{
				if(in)
				{
					if(tok) ans[i]=num[i];
					else
					{
						if(cou[i]==num[i]) ans[i]=num[i];
						else if(cou[i]>num[i]) tok=1,ans[i]=num[i];
						else ans[i]=0,ok=1;
					}
				}
				else
				{
					ans[i]=0;
					if(num[i]) ok=1;
				}
			}

			if(in && i && !rem[i-1]) in=0;
		}
		jian();
		printf("Case #%d: ",cas++);
		show();
	}
	
	return 0;
}
