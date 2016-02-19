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
// Created Time  : 2016年01月23日 星期六 20时10分56秒
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

#pragma comment(linker, "/STACK:102400000,102400000")

using namespace std;

char map1[105][105];
int N,M,cou,H,L;
long long sum;

const int step[4][2]={{0,1},{0,-1},{-1,0},{1,0}};

bool dfs(int h,int l,int sta,long long a,long long b) {
	if(a%b==0 && a/b==sum) return 1;
	int nh,nl;
	int num;
	char ope;
	long long ta,tb;

	for(int i=0;i<4;++i) {
		nh=h+step[i][0];
		nl=l+step[i][1];

		if(nh>=0 && nh<H && nl>=0 && nl<L && !(sta&(1<<(nh*L+nl)))) {
			ope=map1[(h<<1)+step[i][0]][(l<<1)+step[i][1]];
			num=map1[nh<<1][nl<<1]-'0';
			ta=a;
			tb=b;
			if(ope=='/') tb=b*num;
			else if(ope=='+') ta=a+b*num;
			else if(ope=='-') ta=a-b*num;
			else ta=a*num;

			if(tb==0) continue;

			if(dfs(nh,nl,sta|(1<<(nh*L+nl)),ta,tb)) return 1;
		}
	}

	return 0;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);
	while(T--) {
		bool ok=0;
		scanf("%d %d %I64d",&N,&M,&sum);
		for(int i=0;i<N;++i)
			scanf("%s",map1[i]);
		H=(N+1)/2;
		L=(M+1)/2;
		for(int i=0;i<H;++i)
			for(int j=0;j<L;++j)
				if(dfs(i,j,(1<<(i*L+j)),map1[i*2][j*2]-'0',1)) {
					ok=1;
					goto end;
				}
end:
		if(ok) puts("Possible");
		else puts("Impossible");
	}
	
	return 0;
}
