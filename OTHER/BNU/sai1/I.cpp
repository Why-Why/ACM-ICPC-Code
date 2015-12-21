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
// Created Time  : 2015年10月01日 星期四 12时37分11秒
// File Name     : I.cpp

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

int N,M,A,B;

vector <int> E[MaxN];

int rem[MaxN];
int que[MaxN],first,last;
int vis[MaxN];

int getans1()
{
	memset(vis,0,sizeof(vis));
	int u,len;

	first=last=0;
	que[last++]=1;
	vis[1]=1;

	while(last-first)
	{
		u=que[first++];
		len=E[u].size();
		for(int i=0;i<len;++i)
			if(vis[E[u][i]]==0)
			{
				if(E[u][i]==N) return vis[u];
				vis[E[u][i]]=vis[u]+1;
				que[last++]=E[u][i];
			}
	}
	return 1000000000;
}

int COL[MaxN<<2];
set <int> sta;

int getans()
{
	memset(COL,0,sizeof(COL));
	sta.clear();

	int u,len;

	first=last=0;
	que[last++]=1;
	vis[1]=1;

	int p=0,t;
	set <int> ::iterator iter;

	for(int i=2;i<=N;++i)
		sta.insert(i);

	while(last-first)
	{
		u=que[first++];
		len=E[u].size();

		for(iter=sta.begin();iter!=sta.end();++iter)
		{
			t=*iter;
			while(p<len && E[u][p]<t) ++p;
			if(E[u][p]==t) continue;

			vis[t]=vis[u]+1;
			sta.erase(t);
			if(t==N) return vis[u];
			que[last++]=t;
		}

/*		for(int i=1;i<=N;++i) tvis[i]=0;
		for(int i=0;i<len;++i) tvis[E[u][i]]=1;
		for(int i=1;i<=N;++i)
			if(tvis[i]==0 && vis[i]==0)
			{
				if(i==N) return vis[u];
				vis[i]=vis[u]+1;
				que[last++]=i;
			}
*/
	}
	return 1000000000;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;
	int t;
	bool ok;

	while(~scanf("%d %d %d %d",&N,&M,&A,&B))
	{
		ok=0;
		for(int i=1;i<=N;++i) E[i].clear();
		while(M--)
		{
			scanf("%d %d",&a,&b);
			E[a].push_back(b);
			E[b].push_back(a);
			if((a==1 && b==N) || (a==N && b==1)) ok=1;
		}

		if(ok)
		{
			if(A<=B) printf("%d\n",A);
			else printf("%lld\n",min((long long)A,getans()*(long long)B));
		}
		else
		{
			if(A>=B) printf("%d\n",B);
			else printf("%lld\n",min((long long)B,getans1()*(long long)A));
		}
	}
	
	return 0;
}
