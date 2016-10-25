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
// Created Time  : 2016年09月24日 星期六 13时44分05秒
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

using namespace std;

const int MaxN=50005;

int N,M;

long long X,TA,TB;
long long Tac[MaxN],Ta[MaxN],Da[MaxN];
long long Tbc[MaxN],Tb[MaxN],Db[MaxN];

long long sum,ans;

struct pii {
	long long t,d,v;
	long long l,r;

	pii() {}

	pii(long long a,long long b,long long c) {
		t=a;
		d=b;
		v=c;
	}
};

pii rem[MaxN];
int rcou;

struct State {
	long long l,r,d;
};

State sta[MaxN];
int scou;

long long hnum[MaxN<<1],hcou,hjia[MaxN<<1],hjian[MaxN<<1];

inline int hash1(long long x) {
	return lower_bound(hnum+1,hnum+hcou+1,x)-hnum;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	long long k;

	while(~scanf("%lld %lld %lld",&TA,&TB,&X)) {
		sum=rcou=0;
		scou=0;
		hcou=0;
		ans=0;

		scanf("%d %d",&N,&M);
		for(int i=1;i<=N;++i) {
			scanf("%lld %lld %lld",Ta+i,Tac+i,Da+i);
			if(Ta[i]+Tac[i]>=X && Ta[i]+Tac[i]<=X+TB) {
				sum+=Da[i];
				rem[++rcou]=pii(Ta[i]+Tac[i]+Tac[i],Da[i],Tac[i]);
			}
		}
		for(int i=1;i<=M;++i) {
			scanf("%lld %lld %lld",Tb+i,Tbc+i,Db+i);
			sum+=Db[i];
			rem[++rcou]=pii(Tb[i]+Tbc[i],Db[i],Tbc[i]);
		}

		for(int i=1;i<=rcou;++i) {
			if(rem[i].t+rem[i].v<X || X+TB<rem[i].t+rem[i].v)
				rem[i].l=rem[i].t-TA;
			else {
				k=(X+TB-rem[i].t-rem[i].v)/(2*rem[i].v)+1;
				if(k<0) k=0;

				k=rem[i].t+2*k*rem[i].v;

				rem[i].l=k-TA;
			}

			rem[i].r=rem[i].t;

			if(rem[i].l<=rem[i].r) {
				sta[++scou].l=rem[i].l;
				sta[scou].r=rem[i].r;
				sta[scou].d=rem[i].d;

				hnum[++hcou]=sta[scou].l;
				hjia[hcou]=hjian[hcou]=0;

				hnum[++hcou]=sta[scou].r;
				hjia[hcou]=hjian[hcou]=0;
			}
		}

		sort(hnum+1,hnum+hcou+1);
		hcou=unique(hnum+1,hnum+hcou+1)-hnum-1;

		for(int i=1;i<=scou;++i) {
			hjia[hash1(sta[i].l)]+=sta[i].d;
			hjian[hash1(sta[i].r)]+=sta[i].d;
		}

		long long temp=0;

		for(int i=1;i<=hcou;++i) {
			temp+=hjia[i];
			ans=max(ans,temp);
			temp-=hjian[i];
		}

		printf("%lld\n",sum-ans);

		//for(int i=1;i<=scou;++i) cout<<sta[i].l<<' '<<sta[i].r<<' '<<sta[i].d<<endl;
	}

	return 0;
}
