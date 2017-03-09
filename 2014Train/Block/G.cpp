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
// Created Time  : 2016年03月24日 星期四 20时11分21秒
// File Name     : G.cpp

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

const int MaxN=100005;

int scou,srem[MaxN],slen[MaxN],sid[MaxN];
int lcou,lrem[MaxN],llen[MaxN],lid[MaxN];
int rem[MaxN],rcou;
long long ladd[MaxN],lans[MaxN];

int rrr[MaxN];

int map1[350][MaxN];
vector <int> zhuan[MaxN];

int N,blen;
long long num[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int M,Q,L,a,b;
	char s[10];

	scanf("%d %d %d",&N,&M,&Q);
	blen=sqrt(double(N));

	for(int i=1;i<=N;++i) scanf("%I64d",num+i);
	for(int i=1;i<=M;++i) {
		scanf("%d",&L);
		if(L>=blen) {
			rrr[i]=1000000+lcou;
			lid[lcou]=i;
			lrem[lcou]=rcou;
			llen[lcou]=L;
			for(int j=0;j<L;++j,++rcou) {
				scanf("%d",rem+rcou);
				zhuan[rem[rcou]].push_back(i);
				lans[lcou]+=num[rem[rcou]];
			}
			++lcou;
		}
		else {
			rrr[i]=scou;
			sid[scou]=i;
			srem[scou]=rcou;
			slen[scou++]=L;
			for(int j=0;j<L;++j,++rcou) {
				scanf("%d",rem+rcou);
				zhuan[rem[rcou]].push_back(i);
			}
		}
	}

	int len;

	for(int i=0;i<lcou;++i)
		for(int j=lrem[i],k=0;k<llen[i];++k,++j) {
			len=zhuan[rem[j]].size();
			for(int t=0;t<len;++t) ++map1[i][zhuan[rem[j]][t]];
		}

	long long ans;

	while(Q--) {
		scanf("%s",s);
		if(s[0]=='?') {
			scanf("%d",&a);
			ans=0;
			if(rrr[a]>=1000000) {
				ans=lans[rrr[a]-1000000];
				for(int i=0;i<lcou;++i)
					ans+=ladd[i]*map1[i][a];
			}
			else {
				for(int i=srem[rrr[a]],j=0;j<slen[rrr[a]];++i,++j)
					ans+=num[rem[i]];
				for(int i=0;i<lcou;++i)
					ans+=ladd[i]*map1[i][a];
			}
			printf("%I64d\n",ans);
		}
		else {
			scanf("%d %d",&a,&b);
			if(rrr[a]>=1000000) {
				//lans[rrr[a]-1000000]+=llen[rrr[a]-1000000]*(long long)b;
				ladd[rrr[a]-1000000]+=b;
			}
			else {
				for(int i=srem[rrr[a]],j=0;j<slen[rrr[a]];++i,++j)
					num[rem[i]]+=b;
				for(int i=0;i<lcou;++i)
					lans[i]+=map1[i][a]*(long long)b;
			}
		}
	}
	
	return 0;
}
