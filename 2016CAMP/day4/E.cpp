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
// Created Time  : 2017年02月16日 星期四 20时42分55秒
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

const long long MaxN=200005;
typedef long long LL;

struct FLAG {
	LL t;
	LL type;	// 1 is query, 2 is lightning, 3 is merge.
	LL a,b;

	FLAG() {}
	FLAG(LL t,LL type,LL a,LL b):t(t),type(type),a(a),b(b) {}

	bool operator < (const FLAG & b) const {
		if(t==b.t) return type<b.type;
		return t>b.t;
	}
};

struct RANGE {
	LL L,R,t;

	RANGE() {}
	RANGE(LL a,LL b,LL c):L(a),R(b),t(c) {}

	bool operator < (const RANGE & b) const {
		return L<b.L;
	}
};

int N,M;
priority_queue <FLAG> que;
set <RANGE> sta;
char ans[200005];

///////////////////////////

inline bool inRange(int p,int t,const RANGE & f) {
	if(f.L-t+f.t<=p && f.R+t-f.t>=p) return 1;
	return 0;
}

inline set <RANGE> ::iterator findL(int p,int t) {
	if(sta.empty()) return sta.end();

	set <RANGE> ::iterator iter=sta.lower_bound(RANGE(p,0,0));

	if(iter!=sta.end() && inRange(p,t,*iter)) return iter;
	if(iter==sta.begin()) return sta.end();
	--iter;
	return iter;
}

inline set <RANGE> ::iterator findR(int p,int t) {
	if(sta.empty()) return sta.end();

	set <RANGE> ::iterator iter=sta.lower_bound(RANGE(p,0,0));

	if(iter!=sta.end() && inRange(p,t,*iter)) return iter;
	if(iter==sta.begin()) return iter;
	--iter;
	if(inRange(p,t,*iter)) return iter;
	++iter;
	return iter;
}

inline void add(set <RANGE> ::iterator iter1) {
	set <RANGE> ::iterator iter2=iter1;

	if(iter1!=sta.begin()) {
		--iter1;
		que.push(FLAG(((iter2->L)-(iter1->R)+(iter1->t)+(iter2->t)+1)/2,3,iter1->L,iter2->L));
		++iter1;
	}
	++iter2;
	if(iter2!=sta.end())
		que.push(FLAG(((iter2->L)-(iter1->R)+(iter1->t)+(iter2->t)+1)/2,3,iter1->L,iter2->L));
}

inline void fenL(const RANGE & f,int p,int t) {
	int nL=f.L-t+f.t;
	int nR=f.R+t-f.t;
	RANGE tmp(p,nR,t);

	set <RANGE> ::iterator iter=sta.insert(tmp).first;
	add(iter);
}

inline void fenR(const RANGE & f,int p,int t) {
	int nL=f.L-t+f.t;
	int nR=f.R+t-f.t;
	RANGE tmp(nL,p,t);

	set <RANGE> ::iterator iter=sta.insert(tmp).first;
	add(iter);
}

inline void fen(const RANGE & f,int p1,int p2,int t) {
	int nL=f.L-t+f.t;
	int nR=f.R+t-f.t;

	RANGE tmp(nL,p1,t);
	set <RANGE> ::iterator iter1=sta.insert(tmp).first;

	tmp=RANGE(p2,nR,t);
	set <RANGE> ::iterator iter2=sta.insert(tmp).first;

	add(iter1);
	add(iter2);
}

inline void solve(const FLAG & x) {
	RANGE tmp1,tmp2;
	set <RANGE> ::iterator iter1,iter2;

	switch(x.type) {
		case 1:
			iter1=findR(x.a,x.t);
			if(iter1!=sta.end() && inRange(x.a,x.t,*iter1)) ans[x.b]='@';
			else ans[x.b]='*';

			/*
			if(sta.empty()) {
				ans[x.b]='*';
				break;
			}

			bool ok=0;
			iter1=sta.lower_bound(RANGE(x.a,0,0));
			if(iter1!=sta.end() && L+(iter1->t)-x.t<=x.a) ok=1;
			else if(iter1!=sta.begin()) {
				--iter1;
				if(R+x.t-(iter1->t)>=x.a) ok=1;
			}

			if(ok) ans[x.b]='*';
			else ans[x.b]='@';
			*/

			break;
		case 2:
			if(sta.empty()) break;

			iter1=findR(x.a,x.t);
			iter2=findL(x.b,x.t);

			if(iter1==sta.end() || iter2==sta.end()) break;
			if(*iter2<*iter1) break;

			if(iter1==iter2) {
				tmp1=*iter1;
				sta.erase(iter1);

				if(inRange(x.a,x.t,*iter1)) {
					if(inRange(x.b,x.t,tmp1)) fen(tmp1,x.a,x.b,x.t);
					else fenR(tmp1,x.a,x.t);
				}
				else if(inRange(x.b,x.t,tmp1)) fenL(tmp1,x.b,x.t);

				break;
			}

			tmp1=*iter1;
			tmp2=*iter2;
			++iter2;
			sta.erase(iter1,iter2);

			if(inRange(x.a,x.t,tmp1)) fenR(tmp1,x.a,x.t);
			if(inRange(x.b,x.t,tmp2)) fenL(tmp2,x.b,x.t);

			break;
		case 3:
			iter1=sta.find(RANGE(x.a,0,0));
			iter2=sta.find(RANGE(x.b,0,0));

			if(iter1==sta.end() || iter2==sta.end()) break;
			if((iter1->R)+x.t-(iter1->t)<(iter2->L)-x.t+(iter2->t)) break;

			tmp1=RANGE((iter1->L)-x.t+(iter1->t),(iter2->R)+x.t-(iter2->t),x.t);

			sta.erase(iter1);
			sta.erase(iter2);
			iter1=sta.insert(tmp1).first;			// !!!

			add(iter1);

			/*
			*/

			break;
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,a,b,c;
	scanf("%d",&T);

	while(T--) {
		while(!que.empty()) que.pop();
		sta.clear();

		scanf("%d",&N);
		for(long long i=1;i<=N;++i) {
			scanf("%d %d %d",&a,&b,&c);
			que.push(FLAG(a,2,b-c,b+c));
		}
		scanf("%d",&M);
		for(long long i=1;i<=M;++i) {
			scanf("%d %d",&a,&b);
			que.push(FLAG(a,1,b,i));
		}

		sta.insert(RANGE(0,0,0));

		while(!que.empty()) {
			solve(que.top());
			que.pop();
		}

		puts(ans+1);
	}

	return 0;
}
