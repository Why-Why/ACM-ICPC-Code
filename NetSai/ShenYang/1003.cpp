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
// Created Time  : 2015年09月19日 星期六 12时48分56秒
// File Name     : 1003.cpp

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

const int MAXN = 100010;//点数的最大值
const int MAXM = 400010;//边数的最大值
const int INF = 0x3f3f3f3f;
struct Edge
{
int to,next,cap,flow;
}edge[MAXM];//注意是MAXM
int tol;
int head[MAXN];
int gap[MAXN],dep[MAXN],cur[MAXN];
void init(int N)
{
tol = 0;
for(int i=0;i<=N;++i)
	head[i]=-1;
}
void addedge(int u,int v,int w,int rw = 0)
{
edge[tol].to = v; edge[tol].cap = w; edge[tol].flow = 0;
edge[tol].next = head[u]; head[u] = tol++;
edge[tol].to = u; edge[tol].cap = rw; edge[tol].flow = 0;
edge[tol].next = head[v]; head[v] = tol++;
}
int Q[MAXN];
void BFS(int start,int end)
{
memset(dep,-1,sizeof(dep));
memset(gap,0,sizeof(gap));
gap[0] = 1;
int front = 0, rear = 0;
dep[end] = 0;
Q[rear++] = end;
while(front != rear)
{
int u = Q[front++];
for(int i = head[u]; i != -1; i = edge[i].next)
{
int v = edge[i].to;
if(dep[v] != -1)continue;
Q[rear++] = v;
dep[v] = dep[u] + 1;
gap[dep[v]]++;
}
}
}
int S[MAXN];
int sap(int start,int end,int N)
{
BFS(start,end);
memcpy(cur,head,sizeof(head));
int top = 0;
int u = start;
int ans = 0;
while(dep[start] < N)
{
if(u == end)
{
int Min = INF;
int inser;
for(int i = 0;i < top;i++)
if(Min > edge[S[i]].cap - edge[S[i]].flow)
{
Min = edge[S[i]].cap - edge[S[i]].flow;
inser = i;
}
for(int i = 0;i < top;i++)
{
edge[S[i]].flow += Min;
edge[S[i]^1].flow -= Min;
}
ans += Min;
top = inser;
u = edge[S[top]^1].to;
continue;
}
bool flag = false;
int v;
for(int i = cur[u]; i != -1; i = edge[i].next)
{
v = edge[i].to;
if(edge[i].cap - edge[i].flow && dep[v]+1 == dep[u])
{
flag = true;
cur[u] = i;
break;
}
}
if(flag)
{
S[top++] = cur[u];
u = v;
continue;
}
int Min = N;
for(int i = head[u]; i != -1; i = edge[i].next)
if(edge[i].cap - edge[i].flow && dep[edge[i].to] < Min)
{
Min = dep[edge[i].to];
cur[u] = i;
}
gap[dep[u]]--;
if(!gap[dep[u]])return ans;
dep[u] = Min + 1;
gap[dep[u]]++;
if(u != start)u = edge[S[--top]^1].to;
}
return ans;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int N,a,b,M,c;
	int ans;
	int cas=1;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&M);
		init(N);
		for(int i=1;i<=M;++i)
		{
			scanf("%d %d",&a,&b);
			if(i<N) c=300000;
			else c=1;
			addedge(a,b,c,c);
		}

		ans=sap(1,N,N);

		printf("Case #%d: %d\n",cas++,ans%300000+1);
	}
	
	return 0;
}
