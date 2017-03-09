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
// Created Time  : 2016年01月03日 星期日 22时59分46秒
// File Name     : K.cpp

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

const int MaxN=10004;
const int MaxM=80004;

struct HASHMAP {
	const static int HASH=500003;
	const static int MaxS=2500000;

	int head[HASH],Hcou,next[MaxS];
	int key[MaxS],val[MaxS];

	void init() {
		Hcou=0;
		memset(head,-1,sizeof(head));
	}

	void insert(unsigned int k,int v) {
		int h=k%HASH;
		for(int i=head[h];i!=-1;i=next[i])
			if(key[i]==k) {
				val[i]+=v;
				return;
			}
		key[Hcou]=k;
		val[Hcou]=v;
		next[Hcou]=head[h];
		head[h]=Hcou++;
	}
	
	int query(unsigned int k) {
		int h=k%HASH;
		for(int i=head[h];i!=-1;i=next[i])
			if(key[i]==k) return val[i];
		return 0;
	}
}sta;

int N,M,W;

inline int lowbit(int x) {
	return x&(-x);
}

inline void add(int x,int y,int z) {
	if(x<=0 || y<=0 || x>W || y>W) return;
	for(;x<=W;x+=lowbit(x))
		for(int i=y;i<=W;i+=lowbit(i)) sta.insert(x*W+i,z);
}

inline int query(int x,int y) {
	if(x<=0 || y<=0) return 0;
	if(x>W) x=W;
	if(y>W) y=W;
	int ret=0;
	for(;x;x-=lowbit(x))
		for(int i=y;i;i-=lowbit(i)) ret+=sta.query(x*W+i);
	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,x,y,z;
	while(~scanf("%d",&N) && N) {
		scanf("%d",&M);
		sta.init();
		W=N<<1;
		for(int i=1;i<=M;++i) {
			scanf("%d %d %d %d",&a,&x,&y,&z);
			if(a==1) add(x-y+N,x+y-1,z);
			else printf("%d\n",query(x+z-y+N,x+z+y-1)-query(x-y+z+N,x+y-z-2)-query(x-y-z+N-1,x+z+y-1)+query(x-y-z+N-1,x+y-z-2));
		}
	}
	
	return 0;
}
