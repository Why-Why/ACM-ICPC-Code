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
// Created Time  : 2016年03月12日 星期六 17时12分01秒
// File Name     : F.cpp

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

const int MaxN=60005;

int N;
int num1[MaxN],num2[MaxN],num3[MaxN];

int bcou,blen,blenl;

long long rem[MaxN][4];

inline void merge(int a[],int b[],int to,int x,int y) {
	int ans[4];
	ans[0]=min(a[0]+b[0]+x+y,a[0]+b[2]
}

inline void change(int L,int R,int p) {

}

inline void change(int p) { change((p-1)*blen+1,p*blen,p); }

void init() {
	blen=sqrt(N+0.0)+1;
	bcou=(N-1)/blen+1;
	blenl=N-(bcou-1)*blen;

	for(int i=1;i<=bcou;++i) change(i);
}

void update(int type,int p,int v) {
	if(type==1) num1[p]=v;
	if(type==2) num2[p]=v;
	if(type==3) num3[p]=v;
	change((p-1)/blen+1);
}

long long getans(int L,int R) {
	int b1=(L-1)/blen+1;
	int b2=(R-1)/blen+1;

	if(b1==b2) change(L,R,0);
	else {
		change(L,b1*blen,0);
		change((b2-1)*blen+1,R,N+1);
		merge(rem[0],rem[b1+1],0,num1[b1*len],num2[b1*len]);
		for(int i=b1+2;i<b2;++i) merge(rem[i],rem[0],0,num1[(i-1)*len],num2[(i-1)*len]);
		merge(rem[N+1],rem[0],0,num1[(b2-1)*len],num2[(b2-1)*len]);
	}

	return rem[0][3];
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int M,a,b,c,d,e;
	char s[10];

	while(~scanf("%d %d",&N,&M)) {
		for(int i=1;i<N;++i) scanf("%d",num1+i);
		for(int i=1;i<N;++i) scanf("%d",num2+i);
		for(int i=1;i<=N;++i) scanf("%d",num3+i);

		init();
		
		while(M--) {
			scanf("%s",s);
			if(s[0]=='C') {
				scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
				if(a==c) update(a,b,e);
				else update(3,b,e);
			}
			else {
				scanf("%d %d",&a,&b);
				printf("%lld\n",getans(a,b));
			}
		}
	}
	
	return 0;
}
