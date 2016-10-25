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
// Created Time  : 2016年07月21日 星期四 13时20分01秒
// File Name     : 1005.cpp

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int MaxN=1005;
const int mod=1000000007;

struct State {
	long long x,y,d;
	long long num,num1;
	int id;

	State() {}
	State(long long a,long long b,long long c,int i,long long n,long long n1) {
		x=a;
		y=b;
		d=c;
		id=i;
		num=n;
		num1=n1;
	}

	bool operator < (const State &b) const {
		if(x!=b.x) return x<b.x;
		if(y!=b.y) return y<b.y;
		if(d!=b.d) return d<b.d;
		return id<b.id;
	}
};

struct Point {
	long long x,y,num,num1;

	bool operator < (const Point &b) const {
		if(x!=b.x) return x<b.x;
		return y<b.y;
	}

	bool operator == (const Point & b) const {
		return (x==b.x && y==b.y);
	}
};

State rem[MaxN];
Point P[MaxN];
int N;

long long mi2[MaxN];

inline long long dis2(long long x,long long y) {
	return x*x+y*y;
}

long long gcd(long long x,long long y) {
	if(!x) return y;
	return gcd(y%x,x);
}

inline long long abs1(long long x) {
	if(x<0) return -x;
	return x;
}

long long getans(int p,long long num) {
	int rcou=0;
	long long a,b,c,d;

	for(int i=1;i<=N;++i)
		if(i!=p) {
			//a=X[i]-X[p];
			//b=Y[i]-Y[p];
			a=P[i].x-P[p].x;
			b=P[i].y-P[p].y;

			d=dis2(a,b);

			if(a && b) c=gcd(abs1(a),abs1(b));
			else c=a ? abs1(a) : abs1(b);

			a/=c;
			b/=c;
			//rem[++rcou]=State(X[i]-X[p],Y[i]-Y[p],dis2(X[i]-X[p],Y[i]-Y[p]),i);
			rem[++rcou]=State(a,b,d,i,P[i].num,P[i].num1);
		}

	if(rcou==0) return 0;

	sort(rem+1,rem+rcou+1);

	int cou=rem[1].num;
	long long ret=0;

	if(rem[1].id>p)
		(ret+=num*rem[1].num1%mod)%=mod;

	for(int i=2;i<=rcou;++i) {
		if(rem[i].x!=rem[i-1].x || rem[i].y!=rem[i-1].y)
			cou=0;

		if(rem[i].id>p) (ret+=num*mi2[cou]%mod*rem[i].num1%mod)%=mod;

		cou+=rem[i].num;
	}

	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	mi2[0]=1;
	for(int i=1;i<MaxN;++i)
		mi2[i]=mi2[i-1]*2%mod;

	int T;
	scanf("%d",&T);

	while(T--) {
		scanf("%d",&N);
		for(int i=1;i<=N;++i) scanf("%I64d %I64d",&P[i].x,&P[i].y),P[i].num=1;

		sort(P+1,P+N+1);
		int cou=1,k=0;
		for(int i=2;i<=N;++i) {
			if(P[i]==P[i-1]) ++cou;
			else {
				P[++k]=P[i-1];
				P[k].num=cou;
				cou=1;
			}
		}
		P[++k]=P[N];
		P[k].num=cou;
		N=k;

		for(int i=1;i<=N;++i) {
			P[i].num1=(mi2[P[i].num]-1+mod)%mod;
		}

		long long ans=0;
		for(int i=1;i<=N;++i) {
			(ans+=getans(i,P[i].num1))%=mod;
			(ans+=((mi2[P[i].num]-1-P[i].num)%mod+mod)%mod)%=mod;
		}
		printf("%I64d\n",ans);
	}

	return 0;
}
