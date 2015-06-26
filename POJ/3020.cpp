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

// Hopcroft-Carp 算法求二分匹配，复杂度 O(sqrt(V)＊E)。
// 输入：边集E(使用vector)，uN，vN。
// 输出：linkU，linkV，最大匹配数。
// 注意：需要先初始化为二分图，先使用init初始化，然后使用addEdge加边，可以修改vis提高效率，使用MaxMatch函数获得结果。

const int MaxU=300;
const int MaxV=300;
const int MaxM=MaxU*MaxV;
const int INF=0x3f3f3f3f;

vector <int> E[MaxU];
int dis,disU[MaxU],disV[MaxV];
int linkU[MaxU],linkV[MaxV];
bool vis[MaxV];

bool searchPath(int uN,int vN)
{
	queue <int> que;
	int u,v;
	int len;

	dis=INF;

	for(int i=1;i<=uN;++i)
		if(linkU[i]==-1)
		{
			que.push(i);
			disU[i]=0;
		}
		else
			disU[i]=-1;
	for(int i=1;i<=vN;++i)
		disV[i]=-1;

	while(!que.empty())
	{
		u=que.front();
		que.pop();

		if(disU[u]>dis)
			break;

		len=E[u].size();

		for(int i=0;i<len;++i)
		{
			v=E[u][i];

			if(disV[v]==-1)
			{
				disV[v]=disU[u]+1;
				
				if(linkV[v]==-1)
					dis=disV[v];
				else
				{
					disU[linkV[v]]=disV[v]+1;
					que.push(linkV[v]);
				}
			}
		}
	}

	return dis != INF;
}

bool find(int u)
{
	int len=E[u].size();
	int v;

	for(int i=0;i<len;++i)
	{
		v=E[u][i];

		if(!vis[v] && disV[v]==disU[u]+1)
		{
			vis[v]=1;

			if(linkV[v]!=-1 && disV[v]==dis)
				continue;

			if(linkV[v]==-1 || find(linkV[v]))
			{
				linkV[v]=u;
				linkU[u]=v;

				return 1;
			}
		}
	}

	return 0;
}

int MaxMatch(int uN,int vN)
{
	int ret=0;

	while(searchPath(uN,vN))
	{
		for(int v=1;v<=vN;++v)
			vis[v]=0;

		for(int u=1;u<=uN;++u)
			if(linkU[u]==-1 && find(u))
				++ret;
	}

	return ret;
}

void addEdge(int u,int v)
{
	E[u].push_back(v);
}

void init(int uN,int vN)
{
	for(int i=1;i<=uN;++i)
		E[i].clear();

	for(int i=1;i<=uN;++i)
		linkU[i]=-1;
	for(int i=1;i<=vN;++i)
		linkV[i]=-1;
}

int map1[50][20];
int H,W;
char s[20];
int uN,vN;
int que[10000];
int first,last;

const int step[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

void bfs(int x,int y)
{
	first=last=0;
	int temp;
	int tx,ty,nx,ny;

	++uN;

	que[last++]=x*1000+y;
	map1[x][y]=uN;

	while(last-first)
	{
		temp=que[first++];
		tx=temp/1000;
		ty=temp-tx*1000;

		for(int i=0;i<4;++i)
		{
			nx=tx+step[i][0];
			ny=ty+step[i][1];

			if(nx>0 && ny>0 && nx<=H && ny<=W && map1[nx][ny]==100000)
			{
				if(map1[tx][ty]<0)
					map1[nx][ny]=++uN;
				else
					map1[nx][ny]=-(++vN);

				que[last++]=nx*1000+ny;
			}
		}
	}
}

void add()
{
	int tx,ty;

	for(int i=1;i<=H;++i)
		for(int j=1;j<=W;++j)
			if(map1[i][j]>0)
				for(int k=0;k<4;++k)
				{
					tx=i+step[k][0];
					ty=j+step[k][1];

					if(tx>0 && ty>0 && tx<=H && ty<=W && map1[tx][ty])
						addEdge(map1[i][j],-map1[tx][ty]);
				}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&H,&W);

		uN=vN=0;

		for(int i=1;i<=H;++i)
		{
			scanf("%s",s+1);

			for(int j=1;j<=W;++j)
				map1[i][j]=s[j]=='o' ? 0 : 100000;
		}

		for(int i=1;i<=H;++i)
			for(int j=1;j<=W;++j)
				if(map1[i][j]==100000)
					bfs(i,j);

		init(uN,vN);
		add();

		printf("%d\n",uN+vN-MaxMatch(uN,vN));
	}
	
	return 0;
}
