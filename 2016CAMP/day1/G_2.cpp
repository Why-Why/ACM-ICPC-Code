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
// Created Time  : 2017年02月12日 星期日 18时41分40秒
// File Name     : G_2.cpp

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

int N,M,mod;

struct Matrix{
	int a[5][5];
	
	void reset(){
		memset(a,0,sizeof(a));
		for(int i=0;i<M;i++) a[i][i]=1;
	}

	Matrix operator * (const Matrix &t) const {
		Matrix ret;
		long long tmp;

		for (int i=0;i<M;i++)
			for (int j=0;j<M;j++) {
				tmp=0;
				for(int x=0;x<M;++x)
					tmp+=a[i][x]*(long long)t.a[x][j];
				ret.a[i][j]=tmp%mod;
			}

		return ret;
	}
}A,B;

Matrix ans[1000006],rem[1000006],base;
int top,flag;

inline void brute(int R,int L) {
	for(int i=R;i>=L;--i) {
		rem[top]=ans[i]*rem[top-1];
		++top;
	}
	flag=0;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int c;

	while(~scanf("%d %d %d",&N,&M,&mod)) {
		//N=read();
		//if(N==-1) break;
		//M=read();
		//mod=read();

		for(int i=0;i<M;i++) for(int j=0;j<M;j++) scanf("%d",&A.a[i][j]);
		for(int i=0;i<M;i++) for(int j=0;j<M;j++) scanf("%d",&B.a[i][j]);
		top=1;
		rem[0].reset();

		base=A;
		flag=1;
		int p=0;

		for(int i=1;i<=N;++i) {
			scanf("%d",&c);

			while(p<c) {
				if(top>1) --top;
				else {
					brute(i-1,c);
					p=c;
					break;
				}

				++p;
			}

			if(!flag) ans[i]=rem[top-1]*B;
			else if(top==1) ans[i]=base*B;
			else ans[i]=rem[top-1]*base*B;

			if(!flag) base=ans[i];
			else base=base*ans[i];

			flag=1;
		}

		for(int i=0;i<M;++i,puts(""))
			for(int j=0;j<M;++j) {
				if(j) putchar(' ');
				printf("%d",ans[N].a[i][j]);
			}
	}

	return 0;
}
