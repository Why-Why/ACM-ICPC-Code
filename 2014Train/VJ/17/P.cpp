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

// AC自动机进行多模式串匹配，复杂度 O(n+km)。
// 输入：k个模式串，要搜索的串。
// 输出：有几个模式串出现在基串中(可以改成出现几次。)。
// 注意：先使用Init初始化，然后使用Insert插入，然后Build，然后Query。
// 原理：模式串构建一个Trie，然后构建失败指针fail。

namespace ZDL
{

const double INF=1000000000000000.0;
const int MaxN=1010;

struct Edge
{
	int v;
	double cost;

	Edge(int _v,double _cost):v(_v),cost(_cost) {}
};

vector <Edge> E[MaxN];
bool vis[MaxN];
int couNode[MaxN];

bool SPFA(double lowcost[],int n,int start)
{
	queue <int> que;
	int u,v;
	double c;
	int len;

	for(int i=1;i<=n;++i)
	{
		lowcost[i]=INF;
		vis[i]=0;
		couNode[i]=0;
	}
	vis[start]=1;
	lowcost[start]=0;
	couNode[start]=1;

	que.push(start);

	while(!que.empty())
	{
		u=que.front();
		que.pop();

		vis[u]=0;
		len=E[u].size();

		for(int i=0;i<len;++i)
		{
			v=E[u][i].v;
			c=E[u][i].cost;

			if(lowcost[v]>lowcost[u]+c)
			{
				lowcost[v]=lowcost[u]+c;

				if(!vis[v])
				{
					vis[v]=1;
					++couNode[v];
					que.push(v);

					if(couNode[v]>n)			//这里应该是>=，也可能是>。
						return 0;
				}
			}
		}
	}

	return 1;
}

inline void addEdge(int u,int v,double c)
{
	E[u].push_back(Edge(v,c));
}

}

const int MaxL=1000;
const int MaxC=52;
const double eps=1e-8;

struct Point
{
	int x,y;
};

Point sta[60];

inline double dis(int a,int b)
{
	return sqrt((0.0+sta[a].x-sta[b].x)*(0.0+sta[a].x-sta[b].x)+(0.0+sta[a].y-sta[b].y)*(0.0+sta[a].y-sta[b].y));
}

int que[5010];
int first,last;

int n,m;
int num[10];
int k;

struct AC_auto
{
	int next[MaxL][MaxC],fail[MaxL];		// 这个节点结尾的单词的个数。
	int root,Tp;
	bool word[MaxL];
	int id[MaxL];

	int Newnode(int id1)
	{
		for(int i=0;i<n;++i)
			next[Tp][i]=-1;
		word[Tp++]=0;
		id[Tp-1]=id1;

		return Tp-1;
	}

	void Init()
	{
		Tp=0;
		root=Newnode(-1);
		first=last=0;
	}

	void Insert(int s[])
	{
		int p=root;
		for(int i=0;s[i]!=-1;++i)
		{
			if(next[p][s[i]-1]==-1)	next[p][s[i]-1]=Newnode(s[i]-1);
			p=next[p][s[i]-1];
		}
		word[p]=1;
	}

	void Build()
	{
		int p,temp;

		fail[root]=-1;
		que[last++]=root;

		while(last-first)
		{
			p=que[first++];
			for(int i=0;i<n;++i)
				if(next[p][i]!=-1)
				{
					if(p==root)	fail[next[p][i]]=root;
					else
					{
						temp=fail[p];
						while(temp!=-1)
						{
							if(next[temp][i]!=-1)
							{
								fail[next[p][i]]=next[temp][i];
								break;
							}
							temp=fail[temp];
						}
						
						if(temp==-1)	fail[next[p][i]]=root;
					}
					que[last++]=next[p][i];
				}
		}
	}

	double tans[1000];
	int que[1000];
	int first,last;
	bool vis[1000];

	bool judge(int a,int fang,int &b)
	{
		while(a!=root && next[a][fang]==-1)
			a=fail[a];

		if(next[a][fang]==-1)
			b=root;
		else
			b=next[a][fang];

		int temp=b;

		while(temp!=-1)
		{
			if(word[temp])
				return 0;
			temp=fail[temp];
		}

		return 1;
	}

	void jiantu()
	{
		using ZDL::addEdge;

		int N=n+Tp-1;
		int temp;

		for(int i=1;i<=N;++i)
			ZDL::E[i].clear();

		if(word[0]==0)
			for(int i=0;i<n;++i)
				if(judge(0,i,temp))
				{
					if(temp)
						for(int j=0;j<i;++j)
							addEdge(Tp+j,temp,dis(j,i));
					else
						for(int j=0;j<i;++j)
							addEdge(Tp+j,Tp+i,dis(j,i));
				}

		for(int i=1;i<Tp;++i)
			if(word[i]==0)
				for(int j=id[i]+1;j<n;++j)
					if(judge(i,j,temp))
					{
						if(temp==0)
							addEdge(i,Tp+j,dis(id[i],j));
						else
							addEdge(i,temp,dis(id[i],j));
					}
	}

	double lowcost[1000];

	double getans()
	{
		jiantu();
		int start;

		if(next[0][0]!=-1)
			start=next[0][0];
		else
			start=Tp;

		ZDL::SPFA(lowcost,n+Tp-1,start);

		double ret=lowcost[Tp+n-1];

		for(int i=1;i<Tp;++i)
			if(id[i]==n-1)
				ret=min(ret,lowcost[i]);

		return ret;
	}

}myAC;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	double ans;

	while(~scanf("%d %d",&n,&m) && n+m)
	{
		for(int i=0;i<n;++i)
			scanf("%d %d",&sta[i].x,&sta[i].y);

		myAC.Init();

		for(int i=1;i<=m;++i)
		{
			scanf("%d",&k);

			for(int i=0;i<k;++i)
				scanf("%d",&num[i]);
			num[k]=-1;

			myAC.Insert(num);
		}

		myAC.Build();

		ans=myAC.getans();

		if(ans>=ZDL::INF)
			printf("Can not be reached!\n");
		else
			printf("%.2lf\n",ans+eps);
	}
	
	return 0;
}
