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
// Created Time  : 2015年12月04日 星期五 11时02分56秒
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

const int MaxN=50005;
typedef long long LL;

int N,M;
int blen,bcou;
int C[MaxN];
int blo[MaxN];
LL ans1[MaxN],ans2[MaxN];

struct OPE {
	int L,R;
	int id;
	
	bool operator < (const OPE &b) const {
		if(blo[L]==blo[b.L]) return R<b.R;
		return blo[L]<blo[b.L];
	}
}ope[MaxN];

int cou[MaxN];
LL tans;

void update(int p,int type) {
	tans=tans+1LL+type*2LL*cou[C[p]];
	cou[C[p]]+=type;
}

void getans() {
	int nL=0,nR=0;
	tans=0;
	memset(cou,0,sizeof(cou));

	for(int i=0;i<M;++i) {
		if(nR>=ope[i].R) for(int j=nR-1;j>=ope[i].R;--j) update(j,-1);
		else for(int j=nR;j<ope[i].R;++j) update(j,1);
		nR=ope[i].R;

		if(nL>=ope[i].L) for(int j=nL-1;j>=ope[i].L;--j) update(j,1);
		else for(int j=nL;j<ope[i].L;++j) update(j,-1);
		nL=ope[i].L;

		ans1[ope[i].id]=tans-(ope[i].R-ope[i].L);
		ans2[ope[i].id]=(ope[i].R-ope[i].L)*(ope[i].R-ope[i].L-1LL);
	}
}

LL gcd(LL a,LL b) {
	if(!a) return b;
	return gcd(b%a,a);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&N,&M);
	blen=(int)sqrt(N+0.0);
	bcou=(N+blen-1)/blen;

	for(int i=0;i<N;++i) {
		scanf("%d",C+i);
		blo[i]=i/blen;
	}

	for(int i=0;i<M;++i) {
		scanf("%d %d",&ope[i].L,&ope[i].R);
		--ope[i].L;
		ope[i].id=i;
	}
	sort(ope,ope+M);
	getans();

	LL temp;
	for(int i=0;i<M;++i) {
		temp=gcd(ans1[i],ans2[i]);
		printf("%lld/%lld\n",ans1[i]/temp,ans2[i]/temp);
	}
	
	return 0;
}
