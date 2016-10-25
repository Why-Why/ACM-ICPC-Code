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
// Created Time  : 2016年10月07日 星期五 13时13分01秒
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

int N;

struct MAT {
	long long num[103][103];

	MAT() {}
	MAT(int x) {
		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				if(i==j) num[i][j]=x;
				else num[i][j]=0;
	}

	MAT operator + (const MAT & b) const {
		MAT ret;
		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				ret.num[i][j]=num[i][j]+b.num[i][j];
		return ret;
	}

	MAT operator * (const MAT & b) const {
		MAT ret;

		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j) {
				ret.num[i][j]=0;
				for(int k=1;k<=N;++k)
					ret.num[i][j]+=num[i][k]*b.num[k][j];
			}

		return ret;
	}

	void show() {
		for(int i=1;i<=N;++i,cout<<endl)
			for(int j=1;j<=N;++j) cout<<num[i][j]<<' ';
		cout<<endl;
	}
};

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int m,k,a,b;
	char s[10];

	while(~scanf("%d %d %d",&N,&m,&k) && N+m+k) {
		++N;
    
		MAT base(1);
    
		while(k--) {
			scanf("%s %d",s,&a);
			if(s[0]=='g') {
				for(int i=1;i<=N;++i) base.num[a][i]+=base.num[N][i];
			}
			else if(s[0]=='e') {
				for(int i=1;i<=N;++i) base.num[a][i]=0;
			}
			else {
				scanf("%d",&b);
				for(int i=1;i<=N;++i) swap(base.num[a][i],base.num[b][i]);
			}
		}

		//base.show();
    
		MAT ret(1);
    
		for(;m;m>>=1,base=base*base)
			if(m&1)
				ret=ret*base;
    
		for(int i=1;i<N-1;++i)
			printf("%lld ",ret.num[i][N]);
		printf("%lld\n",ret.num[N-1][N]);
	}

	return 0;
}
