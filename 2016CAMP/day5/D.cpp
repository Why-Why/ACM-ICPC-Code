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
// Created Time  : 2017年02月17日 星期五 10时43分48秒
// File Name     : D.cpp

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
#include <stack>

using namespace std;

const int MaxN=200005;

int N;
int a[MaxN];
int ans[MaxN];

stack <int> sta;

inline bool slove(){
	for (int i=1;i<=N;i++) {
		if (a[i]&1) return 0;
		a[i]/=2;
		if (abs(a[i]-a[i-1])>1) return 0;
	}

	for (int i=1;i<=N;i++) ans[i]=i;

	for (int i=1;i<=N;i++){
		if (a[i]>a[i-1]) sta.push(i);
		else if (a[i]<a[i-1]){
			ans[sta.top()]=i;
			ans[i]=sta.top();
			sta.pop();
		}
	}

	if(!sta.empty()) return 0;

	return 1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);
	for(int i=1;i<N;++i) scanf("%d",a+i);
	a[0]=a[N]=0;

	if (!slove()) puts("No");
	else {
		puts("Yes");
		printf("%d",ans[1]);
		for (int i=2;i<=N;i++) printf(" %d",ans[i]);
		puts("");
	}

	int last=1;

	return 0;
}
