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
// Created Time  : 2015年12月25日 星期五 21时01分22秒
// File Name     : C.cpp

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
const int mod=1000000007;

struct Edge {
	int to,next;
};

Edge E[MaxN];
int head[MaxN],Ecou;
int N;

long long dp[MaxN][2];

void init() {
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

long long inv(long long a,long long m)
{
	if(a == 1)return 1;
	return inv(m%a,m)*(m-m/a)%m;
}

long long dfs(int u,int pre) {
	int cou=0;
	long long sum=0;
	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre) {
			++cou;
			(sum+=dfs(E[i].to,u))%=mod;
		}

	long long C=cou;
	long long t;
	dp[u][0]=sum;
	for(long long i=1;i<=cou;++i) {
		t=i*(i+1LL)/2LL;
		t%=mod;
		(dp[u][0]+=(C*t)%mod)%=mod;
		C=C*(cou-i)%mod*inv(i+1,mod)%mod;
	}
	dp[u][1]=sum;

	cout<<u<<' '<<dp[u][0]<<' '<<dp[u][1]<<' '<<cou<<endl;

	return (dp[u][0]+dp[u][1])%mod;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	scanf("%d",&N);
	init();

	for(int i=1;i<N;++i) {
		scanf("%d %d",&a,&b);
		addEdge(a,b);
		addEdge(b,a);
	}

	dfs(1,-1);
	printf("%d\n",(int)((dp[1][0]+dp[1][1])%mod));
	
	return 0;
}
