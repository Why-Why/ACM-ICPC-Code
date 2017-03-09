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
// Created Time  : 2017年01月16日 星期一 22时10分27秒
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

int N;

struct QUE {
	int k;
	int a[1003];
	int ans[1003];

	QUE() { k=0; }
	void add(int x) { a[++k]=x; }

	void ask() {
		if(!k) return;

		printf("%d\n",k);
		for(int i=1;i<=k;++i) printf("%d ",a[i]);
		puts("");
		fflush(stdout);

		for(int i=1;i<=N;++i) scanf("%d",ans+i);
	}

}que[23][2];

int ans[1003];

void getans(int L,int R,int dis) {
	if(L==R) return;

	int M=(L+R)>>1;
	for(int i=L;i<=M;++i) que[dis][0].add(i);
	for(int i=M+1;i<=R;++i) que[dis][1].add(i);

	getans(L,M,dis+1);
	getans(M+1,R,dis+1);
}

void showans(int L,int R,int dis) {
	if(L==R) return;

	int M=(L+R)>>1;

	for(int i=M+1;i<=R;++i) ans[i]=min(ans[i],que[dis][0].ans[i]);
	for(int i=L;i<=M;++i) ans[i]=min(ans[i],que[dis][1].ans[i]);

	showans(L,M,dis+1);
	showans(M+1,R,dis+1);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	memset(ans,0x3f,sizeof(ans));

	scanf("%d",&N);
	getans(1,N,1);

	for(int i=1;i<=20;++i)
		for(int j=0;j<2;++j)
			que[i][j].ask();

	showans(1,N,1);

	puts("-1");
	for(int i=1;i<=N;++i) printf("%d ",ans[i]);
	puts("");
	fflush(stdout);

	return 0;
}
