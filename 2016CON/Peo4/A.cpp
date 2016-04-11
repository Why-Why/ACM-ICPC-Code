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
// Created Time  : 2016年03月12日 星期六 15时47分49秒
// File Name     : A.cpp

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

const int MaxN=(1<<12)+5;

int num[14][MaxN],N;
long long ans;
long long jie[20];

inline int judge(int n[]) {
	if((n[0]&1) && (n[2]&1)) {
		n[0]=(n[0]+1)/2;
		n[1]=(n[2]+1)/2;
		return 2;
	}

	if((n[0]&1) && (n[1]&1)) {
		if(n[0]>n[1] && n[2]>n[3]) {
			n[0]=(n[0]+1)/2;
			n[1]=(n[1]+1)/2;
			return 1;
		}
		if(n[0]<n[1] && n[2]<n[3]) {
			n[0]=(n[0]+1)/2;
			n[1]=(n[1]+1)/2;
			return 1;
		}
		return 0;
	}
	if((n[2]&1) && (n[3]&1)) {
		if(n[0]>n[1] && n[2]>n[3]) {
			n[0]=(n[3]+1)/2;
			n[1]=(n[2]+1)/2;
			return 1;
		}
		if(n[0]<n[1] && n[2]<n[3]) {
			n[0]=(n[3]+1)/2;
			n[1]=(n[2]+1)/2;
			return 1;
		}
		return 0;
	}
	return 0;
}

void getans(int nnn[],int N,int len) {
	if(N==0) {
		ans+=jie[len];
		return;
	}

	int cou=0,ecou=0;
	int rem[2];

	for(int i=1;i<=(1<<N);i+=2) {
		num[N][++cou]=(nnn[i+1]+1)/2;
		if((nnn[i] & 1) && (nnn[i]+1==nnn[i+1])) continue;

		if(ecou>=2) return;
		rem[ecou++]=i;
	}

	if(ecou==0) getans(num[N],N-1,len);
	else if(ecou==1) getans(num[N],N-1,len+1);
	else {
		int tn[4]={nnn[rem[0]],nnn[rem[0]+1],nnn[rem[1]],nnn[rem[1]+1]};
		switch(judge(tn)) {
			case 0: return;
			case 1: num[N][(rem[0]+1)/2]=tn[0]; num[N][(rem[1]+1)/2]=tn[1];
					getans(num[N],N-1,len+1);
					break;
			case 2:
					num[N][(rem[0]+1)/2]=tn[0]; num[N][(rem[1]+1)/2]=tn[1];
					getans(num[N],N-1,len+1);
					swap(num[N][(rem[0]+1)/2],num[N][(rem[1]+1)/2]);
					getans(num[N],N-1,len+1);
					break;
		}
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	jie[0]=1;
	for(int i=1;i<=15;++i) jie[i]=jie[i-1]*i;

	while(~scanf("%d",&N)) {
		for(int i=1;i<=(1<<N);++i) scanf("%d",num[0]+i);
		ans=0;

		getans(num[0],N,0);
		printf("%lld\n",ans);
	}
	
	return 0;
}
