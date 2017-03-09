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
// Created Time  : 2017年03月03日 星期五 13时04分28秒
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

struct pii {
	int a;
	char b;

	pii(int a,char b):a(a),b(b) {}
	pii() {}

	bool operator < (const pii & y) const {
		if(a!=y.a) return a>y.a;
		return b<y.b;
	}
};

const char C[]="CDEGA";

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	char s[30];
	int N,M;
	int cou[256];
	pii ans[10];

	while(~scanf("%d %d",&N,&M) && N+M) {
		memset(cou,0,sizeof(cou));
		for(int i=1;i<=N;++i) {
			scanf("%s",s+1);
			for(int j=1;j<=M;++j) ++cou[s[j]];
		}

		for(int i=0;i<5;++i) ans[i]=pii(cou[C[i]],C[i]);
		sort(ans,ans+5);
		if(ans[0].a) printf("%c %d",ans[0].b,ans[0].a);
		for(int i=1;i<5;++i) if(ans[i].a) printf(" %c %d",ans[i].b,ans[i].a);
		puts("");
	}

	return 0;
}
