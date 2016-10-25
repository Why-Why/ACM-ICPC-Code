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
// Created Time  : 2016年10月25日 星期二 00时09分52秒
// File Name     : H.cpp

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

int N,M;
int a[111];
char s[111][111];
bool vis[111];
char ans[111];

inline bool check(char s[],char base[]) {
	int i;
	for(i=0;s[i];++i) {
		if(base[i]==0) return 0;
		if(base[i]!='?' && base[i]!=s[i]) return 0;
	}

	if(base[i]) return 0;
	return 1;
}

bool judge() {
	for(int i=1;i<=N;++i)
		if(vis[i]==0)
			if(check(s[i],ans)) return 0;
	return 1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;++i) scanf("%s",s[i]);
	for(int i=1;i<=M;++i) scanf("%d",a+i),vis[a[i]]=1;

	for(int j=2;j<=M;++j)
		if(strlen(s[a[j]])!=strlen(s[a[j-1]])) {
			puts("No");
			return 0;
		}

	for(int i=0;;++i) {
		bool ok=0,ook=1;

		for(int j=1;j<=M;++j) {
			if(s[a[j]][i]!=0) ok=1;
			if(j!=1 && s[a[j-1]][i]!=s[a[j]][i]) ook=0;
		}

		if(ok==0) break;
		if(ook) ans[i]=s[a[1]][i];
		else ans[i]='?';
	}

	if(judge()) {
		puts("Yes");
		puts(ans);
	}
	else puts("No");

	return 0;
}
