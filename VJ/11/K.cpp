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

const int MaxN=2000;
const int MaxM=1000000;
const int INF=0x3f3f3f3f;

struct Edge
{
	int to,next,cap,flow;
};

Edge E[MaxM];
int head[MaxN],Ecou;
int gap[MaxN],dis[MaxN],cur[MaxN];
int S,T;

void init(int N,int _S,int _T)
{
	S=_S;
	T=_T;
	Ecou=0;

	for(int i=1;i<=N;++i)
	{
		head[i]=-1;
		gap[i]=0;
		dis[i]=-1;
	}
}

void addEdge(int u,int v,int c,int rc=0)
{
	E[Ecou].to=v;
	E[Ecou].cap=c;
	E[Ecou].flow=0;
	E[Ecou].next=head[u];
	head[u]=Ecou++;

	E[Ecou].to=u;
	E[Ecou].cap=rc;
	E[Ecou].flow=0;
	E[Ecou].next=head[v];
	head[v]=Ecou++;
}

int que[MaxN],front,last;

void BFS()
{
	int u,v;

	gap[0]=1;
	dis[T]=0;
	front=last=0;
	que[last++]=T;

	while(front!=last)
	{
		u=que[front++];

		for(int i=head[u];i!=-1;i=E[i].next)
		{
			v=E[i].to;

			if(dis[v]!=-1)
				continue;

			dis[v]=dis[u]+1;
			++gap[dis[v]];
			que[last++]=v;
		}
	}
}

int stack[MaxN],top;

inline void update(int remm)
{
	for(int i=0;i<top;++i)
	{
		E[stack[i]].flow+=remm;
		E[stack[i]^1].flow-=remm;
	}
}

int SAP(int N)
{
	BFS();

	for(int i=1;i<=N;++i)
		cur[i]=head[i];

	int u,v,ret=0,remm=INF,mindis,inser;

	top=0;
	u=S;
	gap[0]=N;

	while(dis[S]<N)
	{
loop:
		for(int i=cur[u];i!=-1;i=E[i].next)
		{
			v=E[i].to;

			if(E[i].cap-E[i].flow && dis[u]==dis[v]+1)
			{
				cur[u]=i;
				stack[top++]=i;
				u=v;

				if(u==T)
				{
					for(int i=0;i<top;++i)
						if(remm>E[stack[i]].cap-E[stack[i]].flow)
						{
							remm=E[stack[i]].cap-E[stack[i]].flow;
							inser=i;
						}

					ret+=remm;
					update(remm);
					top=inser;
					u=E[stack[top]^1].to;
					remm=INF;
				}

				goto loop;
			}
		}

		mindis=N-1;

		for(int i=head[u];i!=-1;i=E[i].next)
			if(E[i].cap-E[i].flow && mindis>dis[E[i].to])
			{
				cur[u]=i;
				mindis=dis[E[i].to];
			}

		if(--gap[dis[u]]==0)
			break;

		dis[u]=mindis+1;
		++gap[dis[u]];

		if(u!=S)
			u=E[stack[--top]^1].to;
	}

	return ret;
}

char s[100];
int map1[100][100];
int num[100][100];
bool have[100][100];
int d,N,M;

inline bool judge(int dx,int dy,int x,int y)
{
	if(dx==0 && dy==0)
		return 0;

	if(abs(dx)+abs(dy)>d)
		return 0;

	if(x+dx>N || x+dx<1 || y+dy>M || y+dy<1)
		return 0;

	if(num[x+dx][y+dy]==0)
		return 0;

	return 1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int cou,couL;
	int ans;

	scanf("%d",&T);

	while(T--)
	{
		cou=0;
		couL=0;
		scanf("%d %d",&N,&d);

		for(int i=1;i<=N;++i)
		{
			scanf("%s",s+1);
			M=strlen(s+1);

			for(int j=1;j<=M;++j)
			{
				map1[i][j]=s[j]-'0';

				if(map1[i][j])
					num[i][j]=++cou;
				else
					num[i][j]=0;
			}
		}

		for(int i=1;i<=N;++i)
		{
			scanf("%s",s+1);

			for(int j=1;j<=M;++j)
				if(s[j]=='L')
				{
					have[i][j]=1;
					++couL;
				}
				else
					have[i][j]=0;
		}

	//	cout<<cou<<endl;

		init(cou*2+2,cou*2+1,cou*2+2);

		for(int i=1;i<=N;++i)
			for(int j=1;j<=M;++j)
				if(map1[i][j])
				{
					addEdge(num[i][j]*2-1,num[i][j]*2,map1[i][j]);

					if(have[i][j])
						addEdge(cou*2+1,num[i][j]*2-1,1);

					if(i<=d || j<=d || i+d>N || j+d>M)
						addEdge(num[i][j]*2,cou*2+2,INF);

					for(int x=-d;x<=d;++x)
						for(int y=-d;y<=d;++y)
							if(judge(x,y,i,j))
								addEdge(num[i][j]*2,num[i+x][j+y]*2-1,INF);
			}

		printf("Case #%d: ",cas++);
		
		ans=SAP(cou*2+2);

		if(ans==couL)
			printf("no");
		else
			printf("%d",couL-ans);

		printf("%s",couL-ans<=1 ? " lizard was left behind.\n" : " lizards were left behind.\n");
	}
	
	return 0;
}
