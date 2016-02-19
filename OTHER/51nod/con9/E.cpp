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
// Created Time  : 2015年12月26日 星期六 16时48分41秒
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

const int mod=1000000007;

struct HASHMAP {
	const static int MaxS=1000000,HASH=30007;

	int head[HASH],Hcou,next[MaxS];
	long long V[3][MaxS];
	unsigned int key[MaxS];

	void init() {
		Hcou=0;
		memset(head,-1,sizeof(head));
	}

	void insert(unsigned int k,long long v,int id) {
		int h=k%HASH;
		
		for(int i=head[h];i!=-1;i=next[i])
			if(key[i]==k) {
				V[id]+=v;
				return;
			}
	}
}dp[2];

int N,M;
int sx,sy,ex,ey;

long long A,B,C,S;

void solve() {

}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d %d %d %d %d",&N,&M,&sx,&sy,&tx,&ty);
	S=(_pow(2,M*(N-1)+N*(M-1))*M*N)%mod;
	A=B=C=0;
	solve();

	printf("%d\n%d\n%d\n%d\n",(int)((((S+C)%mod-(A+B)%mod)%mod+mod)%mod),(int)(((B-C)%mod+mod)%mod),(int)(((A-C)%mod+mod)%mod),(int)(C));
	
	return 0;
}
