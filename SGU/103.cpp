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
// Created Time  : 2015年08月09日 星期日 19时36分41秒
// File Name     : 103.cpp

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

const int MaxN=310;
const int MaxM=30000;
const int INF=0x3f3f3f3f;

struct Edge
{
	int to,next;
	int cost;
};

Edge E[MaxM];
int head[MaxN],Ecou;

int N,M;
int lowcost[MaxN];

int R[MaxN],TB[MaxN],TP[MaxN],C[MaxN];
int pre[MaxN];

void init()
{
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v,int c)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	E[Ecou].cost=c;
	head[u]=Ecou++;
}

struct node
{
	int val;
	int id;

	node() {}
	node(int a,int b):val(a),id(b) {}

	bool operator < (const node &b) const
	{
		return val>b.val;
	}
};

priority_queue <node> que;
bool vis[MaxN];

int jiao(int a,int b,int c,int d)
{
	if(c>=b || a>=d)
		return INF;

	return max(a,c);
}

int getjiao(int s1,int t1,int T1,int s2,int t2,int T2,int xiao)
{
	int k;

/*	if(s1>=xiao) k=0;
	else k=(int)((xiao-s1+T1-1)/T1);
	s1+=k*T1;

	cout<<k<<endl;

	if(s2>=xiao) k=0;
	else k=(int)((xiao-s2+T2-1)/T2);
	s2+=k*T2;

	cout<<k<<endl;

	cout<<s1<<' '<<s2<<endl;

	if(T1==T2)
		return jiao(s1,s1+t1,s2,s2+t2);
	else*/

	{
		for(int i=xiao;;++i)
		{
			k=(int)((i-s1)/T1);
			if(k*T1+s1+t1>i)
			{
				k=(int)((i-s2)/T2);
				if(k*T2+s2+t2>i)
					return i;
			}

			if(T1==T2 && i-xiao>T1)
				return INF;
		}
	}
}

int getnum(int u,int v,int time)
{
	int suB,svB,suP,svP;
	int t;

	if(C[u]) suB=R[u]-TB[u],suP=R[u]-TB[u]-TP[u];
	else suB=R[u]-TB[u]-TP[u],suP=R[u]-TP[u];
	
	if(C[v]) svB=R[v]-TB[v],svP=R[v]-TB[v]-TP[v];
	else svB=R[v]-TB[v]-TP[v],svP=R[v]-TP[v];

	return min(getjiao(suB,TB[u],TB[u]+TP[u],svB,TB[v],TB[v]+TP[v],time),getjiao(suP,TP[u],TB[u]+TP[u],svP,TP[v],TB[v]+TP[v],time));
}

void getans(int start)
{
	for(int i=1;i<=N;++i)
	{
		vis[i]=0;
		lowcost[i]=INF;
	}
	lowcost[start]=0;
	que.push(node(0,start));
	pre[start]=-1;

	node t;
	int id,temp;

	while(!que.empty())
	{
		t=que.top();
		que.pop();
		id=t.id;

		if(vis[id])
			continue;
		vis[id]=1;

		for(int i=head[id];i!=-1;i=E[i].next)
			if(vis[E[i].to]==0)
			{
				temp=getnum(id,E[i].to,t.val)+E[i].cost;
				if(temp<lowcost[E[i].to])
				{
					lowcost[E[i].to]=temp;
					que.push(node(temp,E[i].to));
					pre[E[i].to]=id;
				}
			}
	}
}

int ans[MaxN];
int cou;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int start,end;
	int a,b,c;
	char s[10];

	while(~scanf("%d %d",&start,&end))
	{
		scanf("%d %d",&N,&M);
		init();

		for(int i=1;i<=N;++i)
		{
			scanf("%s %d %d %d",s,&R[i],&TB[i],&TP[i]);
			C[i]=(s[0]=='B');
		}

		while(M--)
		{
			scanf("%d %d %d",&a,&b,&c);
			addEdge(a,b,c);
			addEdge(b,a,c);
		}

		getans(start);

		if(lowcost[end]!=INF)
		{
			cou=0;
			printf("%d\n",lowcost[end]);
			for(int i=end;i!=start;i=pre[i])
				ans[cou++]=i;
			printf("%d",start);
			for(int i=cou-1;i>=0;--i)
				printf(" %d",ans[i]);
			puts("");
		}
		else
			puts("0");
	}
	
	return 0;
}

/*
int main()
{
	int a,b,c,x,y,z,t;

	while(cin>>a>>b>>c>>x>>y>>z>>t)
		cout<<getjiao(a,b,c,x,y,z,t)<<endl;
}*/
