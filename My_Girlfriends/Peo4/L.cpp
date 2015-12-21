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
// Created Time  : 2015年11月29日 星期日 11时46分30秒
// File Name     : L.cpp

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

struct TIME {
	int a,b,c;
	int id;

	bool operator < (const TIME & y) const {
		if(a!=y.a) return a<y.a;
		if(b!=y.b) return b<y.b;
		return c<y.c;
	}

	TIME operator + (int L) {
		TIME ret=*this;
		ret.c+=L;
		ret.b+=ret.c/60;
		ret.c%=60;
		ret.a+=ret.b/60;
		ret.b%=60;
		return ret;
	}
};

TIME ttt[20005];
int N,L;

int ans[20005];
int anscou;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&N,&L);
		for(int i=1;i<=N;++i)
			scanf("%d:%d:%d",&ttt[i].a,&ttt[i].b,&ttt[i].c),ttt[i].id=i;
		sort(ttt+1,ttt+N+1);
		anscou=0;

		ans[anscou++]=ttt[1].id;
		TIME temp=ttt[1]+L;
		for(int i=2;i<=N;++i)
			if(ttt[i]<temp) continue;
			else ans[anscou++]=ttt[i].id,temp=ttt[i]+L;

		sort(ans,ans+anscou);

		printf("%d\n",anscou);
		printf("%d",ans[0]);
		for(int i=1;i<anscou;++i)
			printf(" %d",ans[i]);
		puts("");
	}
	
	return 0;
}
