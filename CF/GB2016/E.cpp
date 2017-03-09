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
// Created Time  : 2017年01月06日 星期五 16时19分00秒
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

const int MaxN=200005;

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

struct State {
	int a2,a0,a1,a6;
	int a20,a01,a16;
	int a201,a016;
	int a2016;

	State() {}

	State(int x) {
		a2=a0=a1=a6=0;
		a20=a01=a16=0;
		a201=a016=0;
		a2016=0;

		switch(x) {
			case 2:
				a2=1;
				break;
			case 0:
				a0=1;
				break;
			case 1:
				a1=1;
				break;
			case 6:
				a6=1;
				break;
			default:
				break;
		}
	}

	State operator + (const State & b) const {
		State ret;

		ret.a2=a2+b.a2;
		ret.a0=a0+b.a0;
		ret.a1=a1+b.a1;
		ret.a6=a6+b.a6;

		ret.a20=min(a20+b.a0,a2+b.a20);
		ret.a01=min(a01+b.a1,a0+b.a01);
		ret.a16=min(a16+b.a6,a1+b.a16);

		ret.a201=min(min(a201+b.a1,a2+b.a201),a20+b.a01);
		ret.a016=min(min(a016+b.a6,a0+b.a016),a01+b.a16);

		ret.a2016=min(min(a2016+b.a6,a2+b.a2016),min(a20+b.a016,a201+b.a16));

		return ret;
	}

	void show() {
		cout<<a2<<' '<<a0<<' '<<a1<<' '<<a6<<endl;
		cout<<a20<<' '<<a01<<' '<<a16<<endl;
		cout<<a201<<' '<<a016<<endl;
		cout<<a2016<<endl;
		cout<<endl;
	}
};

State BIT[MaxN<<2];
char s[MaxN];

inline void pushUP(int po) {
	BIT[po]=BIT[lc]+BIT[rc];
}

void build(int L,int R,int po) {
	if(L==R) {
		BIT[po]=State(s[L]-'0');
		return;
	}

	int M=(L+R)>>1;
	build(lson);
	build(rson);

	pushUP(po);
}

State query(int ql,int qr,int L,int R,int po) {
	if(ql<=L && qr>=R) return BIT[po];

	int M=(L+R)>>1;
	if(qr<=M) return query(ql,qr,lson);
	if(ql>M) return query(ql,qr,rson);
	return query(ql,qr,lson)+query(ql,qr,rson);
}

int N;
int rem2[MaxN],r2cou;
int rem0[MaxN],r0cou;
int rem1[MaxN],r1cou;
int rem7[MaxN],r7cou;

int sum6[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int Q,a,b;
	State ts0,ts1,ts2;

	scanf("%d %d",&N,&Q);
	scanf("%s",s+1);
	build(1,N,1);

	for(int i=1;i<=N;++i) {
		sum6[i]=sum6[i-1];
		if(s[i]=='2') rem2[++r2cou]=i;
		else if(s[i]=='0') rem0[++r0cou]=i;
		else if(s[i]=='1') rem1[++r1cou]=i;
		else if(s[i]=='7') rem7[++r7cou]=i;
		else if(s[i]=='6') ++sum6[i];
	}

	int t2,t0,t1,t7;
	int ans,tans;

	while(Q--) {
		scanf("%d %d",&a,&b);

		t7=rem7[upper_bound(rem7+1,rem7+r7cou+1,b)-rem7-1];
		t1=rem1[upper_bound(rem1+1,rem1+r1cou+1,t7-1)-rem1-1];
		t0=rem0[upper_bound(rem0+1,rem0+r0cou+1,t1-1)-rem0-1];
		t2=rem2[upper_bound(rem2+1,rem2+r2cou+1,t0-1)-rem2-1];

		if(t2<a) {
			puts("-1");
			continue;
		}

		tans=0x3f3f3f3f;
		ans=sum6[b]-sum6[t1];

		ts0=query(t0,t1,1,N,1);
		ts1=query(t2,t0,1,N,1);
		ts2=query(a,t2,1,N,1);

		tans=min(tans,ts0.a6+ts1.a6+ts2.a2016);
		tans=min(tans,ts0.a6+ts1.a16+ts2.a201);
		tans=min(tans,ts0.a6+ts1.a016+ts2.a20);
		tans=min(tans,ts0.a16+ts1.a1+ts2.a201);
		tans=min(tans,ts0.a16+ts1.a01+ts2.a20);

		printf("%d\n",ans+tans);
	}

	return 0;
}
