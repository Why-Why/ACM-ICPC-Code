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
// Created Time  : 2015年07月17日 星期五 20时24分40秒
// File Name     : 1703_1.cpp

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

const int MaxN=100005;

int N;
int fa[MaxN],val[MaxN];

int find(int x,int &num)
{
	if(fa[x]==-1)
		return x;

	int tn=0;
	int t=find(fa[x],tn);

	fa[x]=t;
	num=tn+val[x];
	val[x]=num;

	return fa[x];
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int T,Q;
	int a,b;
	int ba,bb;
	int x,y;
	char s[10];

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&Q);

		memset(fa,-1,sizeof(fa));
		
		while(Q--)
		{
			scanf("%s %d %d",s,&a,&b);

			if(s[0]=='D')
			{
				x=y=0;
				ba=find(a,x);
				bb=find(b,y);
    
				if(ba!=bb)
				{
					fa[ba]=bb;
					val[ba]=x+y+1;
				}
			}
			else
			{
				x=y=0;
				ba=find(a,x);
				bb=find(b,y);

				if(ba!=bb)
					puts("Not sure yet.");
				else if((y-x)%2)
					puts("In different gangs.");
				else
					puts("In the same gang.");
			}
		}
	}
	
	return 0;
}
