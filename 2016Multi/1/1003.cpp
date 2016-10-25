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
// Created Time  : 2016年07月27日 星期三 20时31分46秒
// File Name     : 1003.cpp

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

int N,M;
long long ans;
char s[MaxN];

int remh[MaxN],reml[MaxN];
int numh[MaxN],numl[MaxN];

void getans() {
	for(int i=1;i<=N;++i)
		for(int j=1;j<i;++j)
			ans+=numh[j]*(long long)numh[i]*(0LL+i-j);
	for(int i=1;i<=M;++i)
		for(int j=1;j<i;++j)
			ans+=numl[j]*(long long)numl[i]*(0LL+i-j);
	ans<<=1;

	long long sum=0;

	for(int i=1;i<=N;++i) {
		if(remh[i]>remh[i-1]) sum+=remh[i]-1;
		else sum=remh[i] ? remh[i]-1 : 0;

		ans+=4LL*sum*(M-remh[i]);
	}

	sum=0;
	for(int i=N;i>=1;--i) {
		if(remh[i]>remh[i+1]) sum+=remh[i]-1;
		else sum=remh[i] ? remh[i]-1 : 0;

		ans+=4LL*sum*(M-remh[i]);
		if(remh[i]) ans-=4LL*(remh[i]-1LL)*(M-remh[i]);
	}

	sum=0;
	for(int i=1;i<=M;++i) {
		if(reml[i]>reml[i-1]) sum+=reml[i]-1;
		else sum=reml[i] ? reml[i]-1 : 0;

		ans+=4LL*sum*(N-reml[i]);
	}

	sum=0;
	for(int i=M;i>=1;--i) {
		if(reml[i]>reml[i+1]) sum+=reml[i]-1;
		else sum=reml[i] ? reml[i]-1 : 0;

		ans+=4LL*sum*(N-reml[i]);
		if(reml[i]) ans-=4LL*(reml[i]-1LL)*(N-reml[i]);
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	long long cou;
	scanf("%d",&T);

	while(T--) {
		memset(remh,0,sizeof(remh));
		memset(reml,0,sizeof(reml));
		memset(numh,0,sizeof(numh));
		memset(numl,0,sizeof(numl));
		cou=0;

		scanf("%d %d",&N,&M);

		for(int i=1;i<=N;++i) {
			scanf("%s",s+1);
			for(int j=1;j<=M;++j) {
				if(s[j]=='G') remh[i]=j,reml[j]=i;
				else ++numh[i],++numl[j],++cou;
			}
		}

		ans=0;
		getans();

		printf("%.4f\n",(double)ans/double(cou*cou));
	}

	return 0;
}
