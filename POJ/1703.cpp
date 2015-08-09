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
// Created Time  : 2015年07月17日 星期五 19时13分10秒
// File Name     : 1703.cpp

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

	int t,tn=0;

	t=find(fa[x],tn);

	fa[x]=t;
	num=tn+val[x];
	val[x]+=tn;

	return t;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int a,b;
	int x,y,Q;
	int ra,rb;
	char s[10];

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&Q);
		memset(fa,-1,sizeof(fa));
		memset(val,0,sizeof(val));

		while(Q--)
		{
			scanf("%s %d %d",s,&a,&b);
			
			if(s[0]=='A')
			{
				x=y=0;

				if(N==2)
				{
					if(a!=b)
						puts("In different gangs.");
					else
						puts("In the same gang.");
				
					continue;
				}
				
				if(find(a,x)!=find(b,y))
					puts("Not sure yet.");
				else if((y-x)%2)
					puts("In different gangs.");
				else
					puts("In the same gang.");

				cout<<find(a,x)<<' '<<find(b,y)<<endl;
			}
			else
			{
				x=y=0;
				ra=find(a,x);
				rb=find(b,y);

				if(ra!=-1 && ra!=rb)
				{
					fa[ra]=rb;

					if(x%2+y%2==1)
						val[a]=x+y;
					else
						val[a]=x+y+1;
				}
			}
		}
	}
	
	return 0;
}
