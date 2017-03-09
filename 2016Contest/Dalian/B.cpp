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
// Created Time  : 2016年11月11日 星期五 18时40分00秒
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

const int MaxN=1005;

int N;
int num[MaxN];
char s[5000006];

int next1[MaxN];

inline bool judge(int a,int b) {
	return num[a]&num[b];
}

inline int getE(int p) {
	for(int i=0;p<N;++i,++p)
		if(judge(i,p)==0) break;
	return p;
}

inline bool judge(char s[]) {
	for(int i=0;i<N;++i)
		if(num[i]&(1<<(s[i]-'0')));
		else return 0;
	return 1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int t,a;

	while(~scanf("%d",&N)) {
		for(int i=0;i<N;++i) {
			scanf("%d",&t);
			num[i]=0;
			while(t--) {
				scanf("%d",&a);
				num[i]|=1<<a;
			}
		}

		memset(next1,0,sizeof(next1));

		int p=0;
		for(int i=1;i<N;++i) {
			t=getE(i);
			for(;p<t;++p) next1[p+1]=max(0,p-i+1);
		}
		next1[0]=-1;

		scanf("%s",s);
		p=0;
		for(int i=0;s[i];) {
			while(p!=-1 && (num[p]&(1<<(s[i]-'0')))==0) p=next1[p];
			++i;
			++p;
			if(p>=N) {
				if(judge(s+i-p)==0) continue;

				t=s[i];
				s[i]=0;
				puts(s+i-p);
				s[i]=t;

				p=next1[p];
			}
		}
	}

	return 0;
}
