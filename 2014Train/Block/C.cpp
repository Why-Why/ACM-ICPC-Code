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
// Created Time  : 2016年03月21日 星期一 23时37分41秒
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

struct QUE {
	int L,R,id;

	bool operator < (const QUE &b) const {
		return L>b.L;
	}
}que[MaxN];

int N,M;
int num[MaxN];
int ans[MaxN];

int C[MaxN];

inline int lowbit(int x) { return x&(-x); }
void add(int x,int d) {
	for(;x<=N;x+=lowbit(x)) C[x]+=d;
}
int query(int x) {
	int ret=0;
	for(;x;x-=lowbit(x)) ret+=C[x];
	return ret;
}

void update(int L,int R,int d) {
	add(L,d);
	add(R+1,-d);
}

bool rem[MaxN];
int zhuan[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d",&N,&M);
		memset(rem,0,sizeof(rem));
		for(int i=1;i<=N;++i) {
			scanf("%d",num+i);
			zhuan[num[i]]=i;
			C[i]=0;
		}
		for(int i=1;i<=M;++i) {
			ans[i]=0;
			scanf("%d %d",&que[i].L,&que[i].R);
			que[i].id=i;
		}
		sort(que+1,que+M+1);

		int p=1,t;

		for(int i=N;i>=1;--i) {
			t=num[i];
			if(rem[t+1] && rem[t-1]) {
				update(i,min(zhuan[t+1],zhuan[t-1])-1,1);
				update(max(zhuan[t+1],zhuan[t-1]),N,-1);
			}
			else if(rem[t+1] || rem[t-1])
				update(i,(rem[t+1] ? zhuan[t+1] : zhuan[t-1])-1,1);
			else
				update(i,N,1);
			rem[t]=1;

			while(p<=M && que[p].L==i) {
				ans[que[p].id]=query(que[p].R);
				++p;
			}
			if(p>M) break;
		}
		for(int i=1;i<=M;++i)
			printf("%d\n",ans[i]);
	}
	
	return 0;
}
