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

const int MaxN=14505;
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
//	cout<<u<<' '<<v<<' '<<c<<endl;
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

int rem[10004];
int map1[105][105];
int rema[105][105],remb[105][105];
int numa[105][105],numb[105][105];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int n,m;
	char s[20],st[20];
	int a,b;
	int cou,coua,coub;
	int temp;

	while(~scanf("%d %d",&n,&m))
	{
		cou=coua=coub=0;

		memset(map1,0,sizeof(map1));
		memset(numa,0,sizeof(numa));
		memset(numb,0,sizeof(numb));

		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				scanf("%s",s);

				if(s[0]=='.')
				{
					map1[i][j]=++cou;
					numa[i][j]=numb[i][j]=0;
				}
				else if(s[3]=='X')
				{
					map1[i][j]=0;
					numa[i][j]=numb[i][j]=0;
				}
				else
				{
					map1[i][j]=0;

					if(s[0]=='X')
						a=-1;
					else
						a=(s[0]-'0')*100+(s[1]-'0')*10+s[2]-'0';
					
					if(s[4]=='X')
						b=-1;
					else
						b=(s[4]-'0')*100+(s[5]-'0')*10+s[6]-'0';

					if(a!=-1)
					{
						rema[i][j]=a;
						numa[i][j]=++coua;
					}
					else
					{
						rema[i][j]=-1;
						numa[i][j]=0;
					}

					if(b!=-1)
					{
						remb[i][j]=b;
						numb[i][j]=++coub;
					}
					else
					{
						remb[i][j]=-1;
						numb[i][j]=0;
					}
				}
			}

		init(coua+cou+coub+2,coua+cou+coub+1,coua+cou+coub+2);

		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				if(numa[i][j])
				{
			//		addEdge(coub+cou+numa[i][j],coua+cou+coub+2,rema[i][j]);

					temp=0;

					for(int k=i+1;k<=n;++k)
						if(map1[k][j]==0)
							break;
						else
						{
							addEdge(coub+map1[k][j],coub+cou+numa[i][j],8);
							++temp;
						}

					addEdge(coub+cou+numa[i][j],coua+cou+coub+2,rema[i][j]-temp);
				}

				if(numb[i][j])
				{
			//		addEdge(coua+cou+coub+1,numb[i][j],remb[i][j]);

					temp=0;

					for(int k=j+1;k<=m;++k)
						if(map1[i][k]==0)
							break;
						else
						{
							rem[map1[i][k]]=Ecou;
							addEdge(numb[i][j],coub+map1[i][k],8);
							++temp;
						}

					addEdge(coua+cou+coub+1,numb[i][j],remb[i][j]-temp);
				}
			}

		SAP(coua+cou+coub+2);

		int p=1;

		for(int i=1;i<=n;++i)
		{
			printf("_");

			for(int j=2;j<=m;++j)
				if(map1[i][j]==0)
					printf(" _");
				else
					printf(" %d",E[rem[map1[i][j]]].flow+1);

			printf("\n");
		}
	}
	
	return 0;
}
