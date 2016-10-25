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
// Created Time  : 2016年07月26日 星期二 23时09分44秒
// File Name     : 1004.cpp

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

const int mod = 3;
const int MaxN = 905;

int a[MaxN][MaxN];//增广矩阵
int x[MaxN];//最后得到的解集

inline int gcd(int a,int b) {
	while(b != 0) {
		int t = b;
		b = a%b;
		a = t;
	}
	return a;
}

inline int lcm(int a,int b) {
	return a/gcd(a,b)*b;
}

long long inv(long long a,long long m) {
	if(a == 1) return 1;
	return inv(m%a,m)*(m-m/a)%m;
}

int Gauss(int equ,int var) {
	int max_r,col,k;

	for(k = 0, col = 0; k < equ && col < var; k++,col++) {
		max_r = k;

		for(int i = k+1; i < equ;i++)
			if(abs(a[i][col]) > abs(a[max_r][col]))
				max_r = i;

		if(a[max_r][col] == 0) {
			k--;
			continue;
		}

		if(max_r != k)
			for(int j = col; j < var+1;j++)
				swap(a[k][j],a[max_r][j]);
		for(int i = k+1;i < equ;i++) {
			if(a[i][col] != 0) {
				int LCM = lcm(abs(a[i][col]),abs(a[k][col]));
				int ta = LCM/abs(a[i][col]);
				int tb = LCM/abs(a[k][col]);
    
				if(a[i][col]*a[k][col] < 0) tb = -tb;
    
				for(int j = col;j < var+1;j++)
					a[i][j] = ((a[i][j]*ta - a[k][j]*tb)%mod + mod)%mod;
			}
		}
	}

	for(int i = k;i < equ;i++)
		if(a[i][col] != 0)
			return -1;		//无解

	//if(k < var) return var-k;	//多解

	for(int i = var-1;i >= 0;i--) {
		int temp = a[i][var];

		for(int j = i+1; j < var;j++) {
			if(a[i][j] != 0) {
				temp -= a[i][j]*x[j];
				temp = (temp%mod + mod)%mod;
			}
		}

		if(a[i][i]==0 && temp==0) x[i]=0;
		else x[i] = (temp*inv(a[i][i],mod))%mod;
	}

	return 0;
}

const int step[][2]={{0,1},{0,-1},{1,0},{-1,0}};

int NN;
int N,M;

inline int zhuan(int x,int y) {
	return (x-1)*M+y-1;
}

inline void init(int num,int x,int y) {
	int nx,ny;

	a[num][num]=2;

	for(int i=0;i<4;++i) {
		nx=x+step[i][0];
		ny=y+step[i][1];

		if(nx>0 && ny>0 && nx<=N && ny<=M)
			a[num][zhuan(nx,ny)]=1;
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,t;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d",&N,&M);
		NN=N*M;
		memset(a,0,sizeof(a));

		int cou=0;
		for(int i=1;i<=N;++i)
			for(int j=1;j<=M;++j) {
				scanf("%d",&t);
				a[cou++][NN]=t ? 3-t : 0;
			}

		cou=0;
		for(int i=1;i<=N;++i)
			for(int j=1;j<=M;++j)
				init(cou++,i,j);

		Gauss(NN,NN);

		cou=0;
		for(int i=0;i<NN;++i) {
			x[i]%=3;
			cou+=x[i];
		}
		printf("%d\n",cou);

		cou=0;
		for(int i=1;i<=N;++i)
			for(int j=1;j<=M;++j) {
				for(int k=0;k<x[cou];++k) printf("%d %d\n",i,j);
				++cou;
			}
	}

	return 0;
}
