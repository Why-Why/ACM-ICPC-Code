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
// Created Time  : 2017年02月12日 星期日 13时17分48秒
// File Name     : G.cpp

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

const int N=1000005;

int k;
long long mod;

inline void add(int & a,int b) {
	a+=b;
	if(a>=mod) a-=mod;
}

struct Matrix{
	int a[5][5];
	
	void reset(){
		memset(a,0,sizeof(a));
		for (int i=0;i<k;i++) a[i][i]=1;
	}

	Matrix operator * (const Matrix &t) const {
		Matrix ret;

		for (int i=0;i<k;i++)
			for (int j=0;j<k;j++) {
				ret.a[i][j]=0;
				for(int x=0;x<k;++x)
					add(ret.a[i][j],a[i][x]*(long long)t.a[x][j]%mod);
			}

		return ret;
	}
};

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

Matrix A,B;
Matrix BASE,ans;

Matrix bit[N<<2];
bool flag[N<<2];

inline void bulidtree(int L,int R,int po) {
	bit[po].reset();
	flag[po]=0;

	if(L==R) return;

	int mid=(L+R)>>1;
	bulidtree(L,mid,po<<1);
	bulidtree(mid+1,R,((po<<1)|1));
}

inline void update(int ul,int ur,int L,int R,int po) {
	if(ul<=L && ur>=R) {
		bit[po]=bit[po]*BASE;
		flag[po]=1;
		return;
	}

	int M=(L+R)>>1;
	if(ul<=M) update(ul,ur,lson);
	if(ur>M) update(ul,ur,rson);
}

inline void query(int p,int L,int R,int po) {
	if(L==R) {
		if(flag[po]) ans=ans*bit[po];
		return;
	}

	int M=(L+R)>>1;
	if(p<=M) query(p,lson);
	else query(p,rson);

	if(flag[po]) ans=ans*bit[po];
}

inline long long read() {
	char c=0;
	while(c<'0' || c>'9') {
		c=getchar();
		if(c==EOF) return -1;
	}

	long long ret=c-'0';
	while(c=getchar(),c>='0' && c<='9') ret=ret*10+c-'0';
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	while(1) {
		n=read();
		if(n==-1) break;
		k=read();
		mod=read();

		for (int i=0;i<k;i++)
		for (int j=0;j<k;j++) A.a[i][j]=read();

		for (int i=0;i<k;i++)
		for (int j=0;j<k;j++) B.a[i][j]=read();

		bulidtree(0,n,1);
		BASE=A;
		update(0,0,0,n,1);

		int lastc=-1;

		for (int i=1;i<=n;i++) {
			int c;
			c=read();

			if(lastc==c) ans=ans*ans*B;
			else {
				ans.reset();
				query(c,0,n,1);
			}
			lastc=c;
			BASE=ans*B;
			update(0,i,0,n,1);
		}

		ans.reset();
		query(n,0,n,1);

		for (int i=0;i<k;i++) {
			printf("%d",ans.a[i][0]);
			for (int j=1;j<k;j++)
				printf(" %d",ans.a[i][j]);

			puts("");
		}
	}

	return 0;
}
