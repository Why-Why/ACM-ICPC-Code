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
// Created Time  : 2016年06月11日 星期六 18时14分08秒
// File Name     : B.cpp

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

const int MaxN=1005;

int N,M,Q;
int head[MaxN],next1[MaxN],val[MaxN],cou;

int buf[MaxN];
typedef pair<int,int> pii;
pii num[MaxN];

inline void add(int u,int v) {
	val[cou]=v;
	next1[cou]=head[u];
	head[u]=cou++;
}

inline int * find(int a,int b) {
	int *x=NULL;

	if(b==0) x=&head[a];
	else {
		for(int i=head[a],j=1;i!=-1;i=next1[i],++j) {
			if(j==b) {
				x=&next1[i];
				break;
			}
		}
	}

	return x;
}

inline void change(int a,int b,int c,int d) {
	int *x=find(a,b);
	int *y=find(c,d);

	int t1=*x,t2=*y;

	*x=t2;
	*y=t1;

	swap(head[a],head[c]);
}

inline pii solve(int u) {
	int ret=0,sum=0;
	for(int i=head[u];i!=-1;i=next1[i]) {
		ret=max(ret,val[i]-sum);
		++sum;
	}
	return pii(ret,sum);
}

int getans() {
	for(int i=1;i<=N;++i) num[i]=solve(i);
	sort(num+1,num+N+1);

	int sum=0;
	int ans=0;
	pii temp;
	
	for(int i=1;i<=N;++i) {
		ans=max(ans,num[i].first-sum);
		sum+=num[i].second;
	}
	return ans;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,c,d;

	scanf("%d",&N);
	memset(head,-1,sizeof(head));
	int t;
	for(int i=1;i<=N;++i) {
		scanf("%d",&t);
		for(int j=1;j<=t;++j) scanf("%d",buf+j);
		for(int j=t;j>=1;--j) add(i,buf[j]);
	}

	scanf("%d",&Q);
	for(int i=1;i<=Q;++i) {
		scanf("%d %d %d %d",&a,&b,&c,&d);
		change(a,b,c,d);
		printf("%d\n",getans());
	}
	
	return 0;
}
