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
// Created Time  : 2016年07月23日 星期六 21时16分29秒
// File Name     : 1008.cpp

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

const long double PI=3.14159265358979323846264338327950288;

struct Complex {
	long double x,y;

	Complex(double a=0.0,double b=0.0):x(a),y(b) {}

	Complex operator + (const Complex & b) const {
		return Complex(x+b.x,y+b.y);
	}
	Complex operator - (const Complex & b) const {
		return Complex(x-b.x,y-b.y);
	}
	Complex operator * (const Complex & b) const {
		return Complex(x*b.x-y*b.y,x*b.y+y*b.x);
	}
};

void change(Complex y[],int len) {
	int k;
	for(int i=1,j=len>>1;i<len-1;++i) {
		if(i<j) swap(y[i],y[j]);
		k=len>>1;
		while(j>=k) {
			j-=k;
			k>>=1;
		}
		if(j<k) j+=k;
	}
}

// len是2的幂，on=1 is DFT，on=-1 is IDFT。
void fft(Complex y[],int len,int on) {
	change(y,len);

	for(int h=2;h<=len;h<<=1) {
		Complex wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
		for(int j=0;j<len;j+=h) {
			Complex w(1,0);
			for(int k=j;k<j+h/2;++k) {
				Complex u=y[k];
				Complex t=w*y[k+h/2];
				y[k]=u+t;
				y[k+h/2]=u-t;
				w=w*wn;
			}
		}
	}

	if(on==-1)
		for(int i=0;i<len;++i)
			y[i].x/=len;
}

////////////////////////////////

const int MaxN=100005;
const int mod=313;

int N,A[MaxN];
long long ans[MaxN];

Complex x1[MaxN<<2],x2[MaxN<<2];

void solve(int L,int M,int R) {
	int len=1;
	while(len<((R-L)<<1)) len<<=1;

	for(int i=0;i<(M-L+1);++i) x1[i]=Complex(ans[L+i],0);
	for(int i=(M-L+1);i<len;++i) x1[i]=Complex(0,0);
	for(int i=0;i<(R-L);++i) x2[i]=Complex(A[i+1],0);
	for(int i=R-L;i<len;++i) x2[i]=Complex(0,0);

	fft(x1,len,1);
	fft(x2,len,1);
	for(int i=0;i<len;++i) x1[i]=x1[i]*x2[i];
	fft(x1,len,-1);

	for(int i=M+1;i<=R;++i) {
		(ans[i]+=(long long)(x1[i-L-1].x+0.5)%mod)%=mod;		//
	}
}

void CDQ(int L,int R) {
	if(L==R) return;

	int M=(L+R)>>1;

	CDQ(L,M);
	solve(L,M,R);
	CDQ(M+1,R);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d",&N) && N) {
		for(int i=1;i<=N;++i) {
			scanf("%d",A+i);
			A[i]%=mod;
		}
		memset(ans,0,sizeof(ans));
		ans[0]=1;

		CDQ(0,N);

		printf("%d\n",(int)(ans[N]%mod));
	}

	return 0;
}
