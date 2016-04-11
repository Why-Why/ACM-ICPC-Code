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
// Created Time  : 2016年03月05日 星期六 15时55分21秒
// File Name     : K.cpp

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

typedef pair<double,int> pii;
const double eps=1e-6;

inline int sgn(double x) {
	return x<-eps ? -1 : x>eps;
}

double fen[111];
int N,Q,C;
double S;

inline void getfen1() {
	int A,a,b,c;
	vector <int> rem[111][11];

	scanf("%d",&A);
	while(A--) {
		scanf("%d %d %d",&a,&b,&c);
		rem[b][c].push_back(a);
	}

	int len;
	double d;

	for(int i=1;i<=N;++i)
		for(int j=1;j<=Q;++j)
			if(rem[i][j].size()) {
				sort(rem[i][j].begin(),rem[i][j].end());		// !!!
				len=unique(rem[i][j].begin(),rem[i][j].end())-rem[i][j].begin();
				fen[i]-=N-1;
				d=(N-1.0)/len;
				for(int k=0;k<len;++k)
					fen[rem[i][j][k]]+=d;
			}
}

inline void getfen2() {
	int rem[111];
	int cou;
	double d;

	for(int i=1;i<=Q;++i) {
		cou=0;
		for(int j=1;j<=N;++j) {
			scanf("%d",rem+j);
			if(rem[j]==0) ++cou;
		}

		if(cou==0) continue;
		if(cou!=N) d=((N-1.0)*cou)/(N-cou-0.0);
		else d=0;

		for(int j=1;j<=N;++j)
			if(rem[j]) fen[j]+=d;
			else fen[j]-=(N-1);
	}
}

inline void showfen() {
	pii temp[111];
	int rem[111];

	for(int i=1;i<=N;++i) temp[i]=pii(fen[i],i);
	sort(temp+1,temp+N+1);
	rem[temp[N].second]=1;
	for(int i=N-1;i>=1;--i)
		if(sgn(temp[i].first-temp[i+1].first)) rem[temp[i].second]=N+1-i;
		else rem[temp[i].second]=rem[temp[i+1].second];

	int A,a;
	scanf("%d",&A);
	while(A--) {
		scanf("%d",&a);
		printf("%.8f %d\n",fen[a],rem[a]);
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d %lf %d",&N,&Q,&S,&C);
		for(int i=1;i<=N;++i) fen[i]=S;

		while(C--) {
			getfen1();
			getfen2();
			showfen();
		}
	}
	
	return 0;
}
