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
// Created Time  : 2016年05月04日 星期三 16时55分48秒
// File Name     : 5513_1.cpp

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int MaxN=900;
const int Mod=1000000007;

int N,M;
int map1[805][9];
int map2[805][9];

////////////

int rem[MaxN],rcou,rrem[MaxN][10];
int trem[10];

void dfs(int p,int lim) {
	if(p>M) {
		int sta=0;
		for(int i=M;i>=1;--i) {
			sta<<=3;
			sta|=trem[i];
		}
		rem[rcou++]=sta;
		return;
	}

	for(int i=1;i<=lim;++i) {
		trem[p]=i;
		dfs(p+1,lim+(i==lim));
	}
}

////////////

int ans1;
long long ans2;

int dp[2][MaxN];
long long dp2[2][MaxN];

inline void init(int flag) {
	for(int i=0;i<rcou;++i) dp[flag][i]=-1,dp2[flag][i]=0;
}

inline int find(int x) {
	return lower_bound(rem,rem+rcou,x)-rem;
}

inline bool unique(int num[],int p) {
	int cou=0;
	for(int i=1;i<=M;++i)
		if(num[i]==num[p]) ++cou;
	return cou<=1;
}

inline int cover(int k,int a,int b) {
	int ret=0;
	int trem[10];
	for(int i=1;i<=M;++i)
		if(rrem[k][i]==a) trem[i]=b;
		else if(rrem[k][i]>a) trem[i]=rrem[k][i]-1;
		else trem[i]=rrem[k][i];
	for(int i=M;i>=1;--i) {
		ret<<=3;
		ret|=trem[i];
	}
	return find(ret);
}

inline int set(int k,int p,int d) {
	int t=rrem[k][p];
	rrem[k][p]=d;

	int cou[10]={},tcou=0;
	for(int i=1;i<=M;++i)
		if(cou[rrem[k][i]]==0) cou[rrem[k][i]]=++tcou;

	int ret=0;
	for(int i=M;i>=1;--i) {
		ret<<=3;
		ret|=cou[rrem[k][i]];
	}
	rrem[k][p]=t;

	return find(ret);
}

inline void insert(int flag,int sta,int v1,long long v2) {
	if(dp[flag][sta]==-1 || dp[flag][sta]>v1) {
		dp[flag][sta]=v1;
		dp2[flag][sta]=v2;
	}
	else if(dp[flag][sta]==v1) (dp2[flag][sta]+=v2)%=Mod;
}

void getans() {
	int flag=0;
	int s=0;

	for(int i=M;i>=1;--i) {
		s<<=3;
		s|=i;
	}
	s=find(s);

	init(0);
	dp[flag][s]=0;
	dp2[flag][s]=1;

	for(int i=1;i<=N;++i) {
		init(flag^1);
		for(int k=0;k<rcou;++k)
			if(dp[flag][k]!=-1) {
				if(!unique(rrem[k],1))
					insert(flag^1,set(k,1,0),dp[flag][k],dp2[flag][k]);
				insert(flag^1,set(k,1,rrem[k][1]),dp[flag][k]+map2[i][1],(dp2[flag][k]*(i==1 ? 1 : 2))%Mod);
			}
		flag^=1;

		for(int j=2;j<=M;++j) {
			init(flag^1);
			for(int k=0;k<rcou;++k)
				if(dp[flag][k]!=-1) {
					if(rrem[k][j-1]==rrem[k][j]) {
						insert(flag^1,set(k,j,0),dp[flag][k],dp2[flag][k]);
						insert(flag^1,k,dp[flag][k]+map1[i][j],(dp2[flag][k]*2)%Mod);
						insert(flag^1,k,dp[flag][k]+map2[i][j],(dp2[flag][k]*(i==1 ? 1 : 2))%Mod);
					}
					else {
						if(!unique(rrem[k],j)) {
							insert(flag^1,set(k,j,0),dp[flag][k],dp2[flag][k]);
							insert(flag^1,set(k,j,rrem[k][j-1]),dp[flag][k]+map1[i][j],(dp2[flag][k]*2)%Mod);
						}
						insert(flag^1,k,dp[flag][k]+map2[i][j],(dp2[flag][k]*(i==1 ? 1 : 2))%Mod);
						insert(flag^1,cover(k,max(rrem[k][j],rrem[k][j-1]),min(rrem[k][j],rrem[k][j-1])),dp[flag][k]+map1[i][j]+map2[i][j],(dp2[flag][k]*(i==1 ? 2 : 3))%Mod);
					}
				}

			flag^=1;
		}
	}

	int end=0;
	for(int i=1;i<=M;++i) {
		end<<=3;
		end|=1;
	}
	end=find(end);

	ans1=dp[flag][end];
	ans2=dp2[flag][end];
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	scanf("%d",&T);
	
	while(T--) {
		scanf("%d %d",&N,&M);
		for(int i=1;i<=N;++i)
			for(int j=2;j<=M;++j)
				scanf("%d",&map1[i][j]);
		for(int i=2;i<=N;++i)
			for(int j=1;j<=M;++j)
				scanf("%d",&map2[i][j]);

		rcou=0;
		dfs(1,1);
		sort(rem,rem+rcou);

		int temp;

		for(int i=0;i<rcou;++i) {
			temp=rem[i];
			for(int j=1;j<=M;++j,temp>>=3)
				rrem[i][j]=temp&7;
		}

		ans1=0;
		ans2=1;
		getans();
		printf("Case #%d: %d %d\n",cas++,ans1,(int)ans2);
	}
	
	return 0;
}
