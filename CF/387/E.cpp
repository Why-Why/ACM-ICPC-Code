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
// Created Time  : 2017年01月16日 星期一 15时22分13秒
// File Name     : E.cpp

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

struct State {
	int d,a,b,id;

	bool operator < (const State & y) const {
		if(d!=y.d) return d<y.d;
		return id<y.id;
	}
}ans[1000006];

int acou,maxn;

char s[1000006];

int stk[1000006];
int top;

inline void addAns(int d,int a,int b) {
	maxn=max(maxn,d);

	++acou;
	ans[acou].id=acou;
	ans[acou].d=d;
	ans[acou].a=a;
	ans[acou].b=b;
}

inline void showAns() {
	printf("%d\n",maxn+1);

	sort(ans+1,ans+acou+1);
	ans[0].d=ans[1].d;

	for(int i=1;i<=acou;++i) {
		if(ans[i].d!=ans[i-1].d) puts("");
		s[ans[i].b]=0;
		printf("%s ",s+ans[i].a);
	}
	puts("");
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int d[2],dcou=0;
	int last=0;
	int len,t;

	scanf("%s",s);
	len=strlen(s)+1;
	s[len-1]=',';

	for(int i=0;i<len;++i)
		if(s[i]==',') {
			d[dcou++]=i;

			if(dcou==2) {
				dcou=0;
				s[d[1]]=0;
				sscanf(s+d[0]+1,"%d",&t);				// O(N) 一直到最后！！！

				while(top && stk[top-1]==0) --top;
				if(top) --stk[top-1];

				addAns(top,last,d[0]);
				last=d[1]+1;

				stk[top++]=t;
			}
		}

	showAns();

	return 0;
}
