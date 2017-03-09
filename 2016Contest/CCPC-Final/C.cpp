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
// Created Time  : 2017年02月22日 星期三 23时01分16秒
// File Name     : C.cpp

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

const int mod=1000000007;

int N,M;
char num[100005][17];
long long rans[(1<<15)+5];
long long pow2[100005];

bitset <100005> rem[17][2],ans,base;

inline void add(long long &a,long long b) {
	a+=b;
	if(a>=mod) a-=mod;
}

inline void del(long long &a,long long b) {
	a-=b;
	if(a<0) a+=mod;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	pow2[0]=1;
	for(int i=1;i<100005;++i) pow2[i]=pow2[i-1]*2%mod;

	int T,cas=1;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d",&N,&M);
		for(int i=0;i<M;++i) rem[i][0].reset(),rem[i][1].reset();
		base.reset();

		for(int i=1;i<=N;++i) {
			scanf("%s",num[i]);
			base.set(i);
			for(int j=0;j<M;++j)
				if(num[i][j]=='Y') rem[j][0].set(i);
				else rem[j][1].set(i);
		}

		int cou,cnum[17];

		for(int i=0;i<(1<<M);++i) {
			cou=0;
			for(int j=0;j<M;++j) if(i & (1<<j)) cnum[cou++]=j;

			rans[i]=0;

			for(int j=0;j<(1<<cou);++j) {
				ans=base;

				for(int k=0;k<cou;++k)
					if(j&(1<<k)) ans&=rem[cnum[k]][0];
					else ans&=rem[cnum[k]][1];

				add(rans[i],pow2[ans.count()]);

				cout<<i<<' '<<j<<' '<<ans.count()<<endl;
			}

			cout<<rans[i]<<endl;
		}

		rans[0]=4;
		rans[1]=3;
		rans[2]=3;
		rans[3]=3;

		// how to get rans ?

		long long tans,fans=0;
		int tmp,wei;

		for(int i=1;i<(1<<M);++i) {
			cou=0;
			for(int j=0;j<M;++j) if(i & (1<<j)) cnum[cou++]=j;

			tans=0;

			for(int j=0;j<(1<<cou);++j) {
				tmp=wei=0;
				for(int k=0;k<cou;++k)
					if(j & (1<<k)) tmp|=(1<<cnum[k]),++wei;

				cout<<wei<<' '<<tmp<<endl;

				if(wei & 1) del(tans,rans[tmp]);
				else add(tans,rans[tmp]);
			}

			cout<<tans<<endl;

			fans^=tans;
		}

		printf("Case #%d: %I64d\n",cas++,fans);
	}

	return 0;
}
