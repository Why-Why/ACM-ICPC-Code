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

struct OPE {
	int type;
	int x,y,z,id;
	int oid;

	bool operator < (const OPE &b) const {
		if(b.x==x)
			if(type==0) return 1;
			else return 0;
		return x<b.x;
	}

}ope[MaxM<<1];

inline bool cmp(const OPE &a,const OPE &b) {
	return a.oid<b.oid;
}

int cou;
int N,M;
int ans[MaxM],anscou;

int C[MaxN<<2];

inline int lowbit(int x) {
	return x&(-x);
}

inline void add(int x,int d) {
	if(x<=0) return;
	if(x>N) x=N;
	for(;x<=N;x+=lowbit(x)) C[x]+=d;
}

inline int query(int x) {
	if(x>N) x=N;
	if(x<=0) return 0;
	int ret=0;
	for(;x;x-=lowbit(x)) ret+=C[x];
	return ret;
}

void solve(int L,int M,int R) {
	sort(ope+L,ope+R+1);
	for(int i=L;i<=R;++i) {
		if(ope[i].oid<=M && ope[i].type==0) add(ope[i].y,ope[i].z);
		else if(ope[i].oid>M && ope[i].type)
			ans[ope[i].id]+=ope[i].type*(query(ope[i].z)-query(ope[i].y));
	}
	for(int i=L;i<=R;++i)
		if(ope[i].oid<=M && ope[i].type==0) add(ope[i].y,-ope[i].z);
	sort(ope+L,ope+R+1,cmp);
}

void CDQ(int L,int R) {
	if(L==R) return;

	int M=(L+R)>>1;
	CDQ(L,M);
	solve(L,M,R);
	CDQ(M+1,R);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,x,y,z;
	while(~scanf("%d",&N) && N) {
		scanf("%d",&M);
		memset(ans,0,sizeof(ans));
		memset(C,0,sizeof(C));
		cou=anscou=0;
		for(int i=1;i<=M;++i) {
			scanf("%d %d %d %d",&a,&x,&y,&z);
			if(a==1) {
				ope[++cou].type=0;
				ope[cou].oid=cou;
				ope[cou].x=x-y+N;
				ope[cou].y=x+y-1;
				ope[cou].z=z;
			}
			else {
				ope[++cou].type=-1;
				ope[cou].oid=cou;
				ope[cou].x=x-z-y+N-1;
				ope[cou].y=x+y-z-2;
				ope[cou].z=x+y+z-1;
				ope[cou].id=++anscou;

				ope[++cou].type=1;
				ope[cou].oid=cou;
				ope[cou].x=x+z-y+N;
				ope[cou].y=x+y-z-2;
				ope[cou].z=x+z+y-1;
				ope[cou].id=anscou;
			}
		}
		N<<=1;
		CDQ(1,cou);
		for(int i=1;i<=anscou;++i)
			printf("%d\n",ans[i]);
	}
	
	return 0;
}
