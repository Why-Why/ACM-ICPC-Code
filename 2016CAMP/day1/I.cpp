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
// Created Time  : 2017年02月12日 星期日 12时44分47秒
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

const int HASH=100003;
const int MaxN=10000000;
const long long BASE=10000000%HASH;

struct HASHMAP {
	int head[HASH];
	int hcou;
	long long key1[MaxN],key2[MaxN];
	int next[MaxN],val[MaxN];

	void init() {
		hcou=0;
		memset(head,-1,sizeof(head));
	}

	void insert(long long k1,long long k2,int v) {
		int h=(k1%HASH*BASE+k2)%HASH;

		key1[hcou]=k1;
		key1[hcou]=k2;
		val[hcou]=v;
		next[hcou]=head[h];
		head[h]=hcou++;
	}

	int get(long long k1,long long k2) {
		int h=(k1%HASH*BASE+k2)%HASH;

		for(int i=head[h];i!=-1;i=next[i])
			if(key1[i]==k1 && key2[i]==k2)
				return val[i];
		return -1;
	}
}sta;

int N,M;
int a[2003],b[2003],c[2003],d[2003];

int getans(int p1,int p2,int l1,int l2) {
	if(p1==0 || p2==0) return 0;

	int t=sta.get(l1*1000000010LL+l2,p1*3000+p2);
	if(t!=-1) return t;

	int ans;

	if(c[p1]!=d[p2]) ans=max(getans(p1-1,p2,a[p1-1],b[p2]),getans(p1,p2-1,a[p1],b[p2-1]));
	else {
		if(l1==l2) ans=getans(p1-1,p2-1,a[p1-1],b[p2-1])+l1;
		else if(l1<l2) ans=getans(p1-1,p2,a[p1-1],l2-l1)+l1;
		else ans=getans(p1,p2-1,l1-l2,b[p2-1])+l2;
	}

	sta.insert(l1*1000000010LL+l2,p1*3000+p2,ans);
	return ans;

}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d %d",&N,&M)) {
		sta.init();
		for(int i=1;i<=N;++i) scanf("%d %d",c+i,a+i);
		for(int i=1;i<=M;++i) scanf("%d %d",d+i,b+i);

		printf("%d\n",getans(N,M,a[N],b[M]));
	}

	return 0;
}
