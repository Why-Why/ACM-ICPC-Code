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
// Created Time  : 2016年03月23日 星期三 23时38分05秒
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

const int MaxN=300005;

int N,M;
int U;
int blen,bcou;
int num[MaxN];
int brem[MaxN];

inline int query(int L,int R,int c) {
	int ret=0;
	for(int i=L;i<=R;++i) if(num[i]<c) ++ret;
	return ret;
}

inline int query(int p,int c) {
	return lower_bound(brem+(p-1)*blen+1,brem+p*blen+1,c)-(brem+(p-1)*blen+1);
}

void update(int p,int c) {
	num[p]=c;
	int x=(p-1)/blen+1;
	for(int i=(x-1)*blen+1;i<=x*blen && i<=N;++i) brem[i]=num[i];
	sort(brem+(x-1)*blen+1,brem+min(N,x*blen)+1);				// !!!
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,c,d,x,y;
	long long ans;

	while(~scanf("%d %d %d",&N,&M,&U)) {
		blen=sqrt(double(N));
		bcou=(N+blen-1)/blen;

		for(int i=1;i<=N;++i) { scanf("%d",num+i); brem[i]=num[i]; }
		for(int i=1;i<=bcou;++i) sort(brem+(i-1)*blen+1,brem+min(N,i*blen)+1);

		while(M--) {
			scanf("%d %d %d %d",&a,&b,&c,&d);
			x=(a-1)/blen+1;
			y=(b-1)/blen+1;
			if(x==y) ans=query(a,b,c);
			else {
				ans=query(a,x*blen,c)+query((y-1)*blen+1,b,c);
				for(int i=x+1;i<y;++i) ans+=query(i,c);
			}
			update(d,U*ans/(b-a+1));
		}

		for(int i=1;i<=N;++i)
			printf("%d\n",num[i]);
	}
	
	return 0;
}
