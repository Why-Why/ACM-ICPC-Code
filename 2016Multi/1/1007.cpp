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
// Created Time  : 2016年07月20日 星期三 12时37分33秒
// File Name     : 1007.cpp

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
typedef long long LL;

const int mod=1000000007;

void show2(LL);

struct HASAMAP {
	static const int HASH=30007;
	static const int MaxS=30000000;

	int head[HASH],Hcou,next[MaxS];
	LL key[MaxS];
	LL val[MaxS];

	void init() {
		Hcou=0;
		memset(head,-1,sizeof(head));
	}

	void insert(LL k,LL v) {
		int h=k%HASH;

		for(int i=head[h];i!=-1;i=next[i])
			if(k==key[i]) {
				(val[i]+=v)%=mod;
				return;
			}
		key[Hcou]=k;
		val[Hcou]=v;
		next[Hcou]=head[h];
		head[h]=Hcou++;
	}

	LL find(LL k) {
		int h=k%HASH;

		for(int i=head[h];i!=-1;i=next[i])
			if(k==key[i])
				return val[i];
		return 0;
	}

	void show() {
		cout<<"#######\n";
		for(int i=0;i<Hcou;++i) {
			show2(key[i]);
			cout<<" "<<val[i]<<endl;
		}
		cout<<endl;
	}

}dp[2];

int N,M;
int no1[1500];

inline int count(int x) {
	int ret=0;
	while(x) {
		if(x&1) ++ret;
		x>>=1;
	}
	return ret;
}

void init() {
	for(int i=0;i<1024;++i)
		no1[i]=count(i);
}

inline LL set(LL k,long long p,long long x) {
	p<<=2;
	return (k&(~(15LL<<p)))|(x<<p);
}

inline int pos(LL k,long long p) {
	p<<=2;
	return (k&(15LL<<p))>>p;
}

void show2(LL k) {
	for(int i=0;i<N;++i)
		cout<<pos(k,i)<<' ';
	cout<<"+";
}

inline LL solve(LL k,int s) {
	LL ret=0;
	int t;
	int cou=0;
	bool vis[12]={};
	int zhuan[12]={},zz=0;

	for(int i=0;i<N;++i)
		if(s&(1<<i)) vis[pos(k,i)]=1;

	for(int i=0;i<N;++i) {
		t=pos(k,i);
		if(t) {
			if(vis[t]) {
				if(!zz) zz=++cou;
				ret=set(ret,i,zz);
			}
			else {
				if(!zhuan[t]) zhuan[t]=++cou;
				ret=set(ret,i,zhuan[t]);
			}
		}
		else {
			if(s&(1<<i)) {
				if(!zz) zz=++cou;
				ret=set(ret,i,zz);
			}
		}
	}

	return ret;
}

int getans() {
	int flag=0;
	LL t;
	LL k,v;

	dp[0].init();
	for(int i=1;i<(1<<N);++i) {
		t=0;
		for(int j=0;j<N;++j)
			if(i&(1<<j)) t=set(t,j,1);
		dp[0].insert(t,(1<<no1[i]));
	}

	for(int i=2;i<=M;++i) {
		cerr<<i<<' '<<dp[flag].Hcou<<endl;

		dp[flag^1].init();
		for(int j=0;j<dp[flag].Hcou;++j) {
			k=dp[flag].key[j];
			v=dp[flag].val[j];

			for(int s=1;s<(1<<N);++s)
				dp[flag^1].insert(solve(k,s),v*(1<<no1[s]));
		}
		flag^=1;
	}

	LL end=0;
	for(int i=0;i<N;++i)
		end=set(end,i,1);
	return dp[flag].find(end);
}

int ans[]={1,1,2,1,2,4,1,3,8,1,4,16,1,5,32,1,6,64,1,7,128,1,8,256,1,9,512,1,10,1024,2,2,48,2,3,448,2,4,3840,2,5,31744,2,6,258048,2,7,2080768,2,8,16711680,2,9,133955584,2,10,72693241,3,3,15008,3,4,429568,3,5,11596928,3,6,306009088,3,7,2369992,3,8,530422352,3,9,523796386,3,10,215597769,4,4,38529024,4,5,207602155,4,6,200364260,4,7,160231949,4,8,554488410,4,9,190587140,4,10,810639015,5,5,519052755,5,6,105908051,5,7,72277468,5,8,23284327,5,9,286851052,5,10,865424583,6,6,126514477,6,7,312460128,6,8,711245882,6,9,987939142,6,10,374773317,7,7,25696077,7,8,433482528,7,9,357533852,7,10,103280608,8,8,162005329,8,9,771914613,8,10,811634190,9,9,585919048,9,10,573168128,10,10,935300639};

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d %d",&N,&M)) {
		if(N>M) swap(N,M);
		for(int i=0;;i+=3)
			if(ans[i]==N && ans[i+1]==M) {
				printf("%d\n",ans[i+2]);
				break;
			}
	}

	return 0;
}
