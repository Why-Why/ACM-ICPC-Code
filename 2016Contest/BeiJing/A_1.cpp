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
// Created Time  : 2017年03月06日 星期一 13时23分52秒
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
#include <bitset>

using namespace std;

const int MaxN=805;
const int MaxM=805;

class BigNum {
	public:
		const static int MaxL=260;
		const static int Mod=10000;
		const static int Dlen=4;

		int num[MaxL/Dlen+1],len;

	public:
		BigNum() { len=1; memset(num,0,sizeof(num)); }
		void changeStoNum(const char *);

		inline void del1();
		inline void div2();
		inline int mod2() const;
		inline bool is0() const;
};

void BigNum::changeStoNum(const char *x) {
	int L=strlen(x);
	int temp,tp;
	int p=0;

	memset(num,0,sizeof(num));
	len=(L-1)/Dlen+1;

	for(int i=L-1;i>=0;i-=Dlen) {
		temp=0;
		tp=i-Dlen+1;

		if(tp<0) tp=0;

		for(int j=tp;j<=i;++j)
			temp=(temp<<3)+(temp<<1)+x[j]-'0';

		num[p++]=temp;
	}

	while(num[len-1]==0 && len>1) --len;
}

void BigNum::del1() {
	for(int i=0;i<len;++i)
		if(num[i]) {
			--num[i];
			break;
		}
	while(num[len-1]==0 && len>1) --len;
}

void BigNum::div2() {
	long long down=0,tdown;

	for(int i=len-1;i>=0;--i) {
		tdown=(num[i]+down*Mod)&1;
		num[i]=(num[i]+down*Mod)>>1;
		down=tdown;
	}
	while(num[len-1]==0 && len>1) --len;
}

int BigNum::mod2() const {
	return num[0]&1;
}

bool BigNum::is0() const {
	if(len>1 || num[0]) return 0;
	return 1;
}

////////////////////////////

bitset <MaxM> data[MaxN];

int GaussXOR(int M) {
	int ret=0,rem;

	for(int r=1;r<=M;++r) {
		for(rem=r;rem<=M;++rem)
			if(data[rem][r])
				break;
		if(rem>M) return M-r+1;

		if(rem!=r) swap(data[rem],data[r]);
		for(int i=r+1;i<=M;++i)
			if(data[i][r])
				data[i]^=data[r];
	}

	return 0;
}

////////////////////////////

int N,M,Q;
BigNum k;

char s[MaxN];
char ans[MaxN];

int fcou;
bitset <MaxN> fans,tfans;
bitset <MaxN> cnum[MaxN],BASE;

inline void run(int step,int M,const bitset <MaxN> &t) {
	cnum[0].reset();
	cnum[1]=t;

	for(int i=2;i<=step;++i) {
		cnum[i]=cnum[i-2]^cnum[i-1]^(cnum[i-1]<<1)^(cnum[i-1]>>1);
		cnum[i]&=BASE;
	}
}

inline void solve() {
	BASE.reset();
	for(int i=1;i<=M;++i) BASE.set(i),data[i].reset();

	for(int i=1;i<=M;++i) {
		fans.reset();
		fans.set(i);
		run(N+1,M,fans);

		data[i]=cnum[N+1];
	}

	fcou=GaussXOR(M);
}

/////////////////////////////

inline bool change() {
	tfans.reset();
	for(int i=M-fcou+1;i<=M;++i) {
		tfans[i]=k.mod2();
		k.div2();
	}
	if(!k.is0()) return 0;

	for(int i=M-fcou;i>=1;--i)
		tfans[i]=((tfans & data[i]).count())&1;

	fans.reset();
	for(int i=1;i<=M;++i) fans[i]=tfans[M+1-i];

	return 1;
}

inline char getans(int x,int y) {
	run(x,M,fans);
	return '0'+cnum[x][y];
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int x,y;

	while(~scanf("%d %d %d",&N,&M,&Q)) {
		solve();

		for(int i=0;i<Q;++i) {
			scanf("%s %d %d",s,&x,&y);
			k.changeStoNum(s);
			k.del1();

			if(!change()) ans[i]='?';
			else ans[i]=getans(x,y);
		}
		ans[Q]=0;
		puts(ans);
	}

	return 0;
}
