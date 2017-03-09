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
// Created Time  : 2017年02月17日 星期五 15时03分20秒
// File Name     : I.cpp

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
#include <bitset>

using namespace std;

const int MaxN=100005;
const int FLAG=9;

int vis[MaxN];
int rem[MaxN][9],rcou[MaxN];

int cou[MaxN];
int N,a[MaxN];

int npri[MaxN],ncou;
bitset <MaxN> save[10003];
bitset <MaxN> ans;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	for(int i=2;i<MaxN;++i)
		if(!vis[i]) {
			vis[i]=i;
			rem[i][rcou[i]++]=i;
			for(int j=i+i;j<MaxN;j+=i)
				if(!vis[j]) vis[j]=i;
		}
		else {
			int t=i/vis[i];
			if(vis[i]!=rem[t][0]) rem[i][rcou[i]++]=vis[i];
			for(int j=0;j<rcou[t];++j) rem[i][rcou[i]++]=rem[t][j];
		}

	vis[1]=1;
	rcou[1]=0;

	int Q,l,r,x,*tmp;

	scanf("%d %d",&N,&Q);

	for(int i=1;i<=N;++i) {
		scanf("%d",a+i);
		tmp=rem[a[i]];

		for(int j=0;j<rcou[a[i]];++j)
			if(npri[tmp[j]]) save[npri[tmp[j]]].set(N-i);
			else {
				npri[tmp[j]]=++ncou;
				save[ncou].set(N-i);
			}
	}

	while(Q--) {
		scanf("%d %d %d",&l,&r,&x);
		ans.reset();

		tmp=rem[x];
		for(int i=0;i<rcou[x];++i)
			ans|=save[npri[tmp[i]]];

		ans>>=N-r;

		int L=0,R=N+1,M;
		int base=ans.count();

		while(R>L) {
			M=(L+R)>>1;
			if((ans>>M).count()==base-M) L=M+1;
			else R=M;
		}

		if(r+1-L>=l) printf("%d\n",r+1-L);
		else puts("-1");
	}

	return 0;
}
